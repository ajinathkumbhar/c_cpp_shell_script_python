#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <gst/gst.h>
#include <pthread.h>
#include <unistd.h>
#include <sstream>
#include <string.h>
#include <string>

#include "log.h"


#define TAG "apptest"

#define MUSIC_1 "playbin uri=file:///home/ajinath/work/00_Me/media/mp3/Tuhi_Hai-(Mr-Jatt.com).mp3"


using namespace std;
enum state {
  NONE = 0,
  PALYING,
  PAUSED,
  STOPPED,
};

static state mPlayerState = NONE;
static state mPlayerReq = NONE;

static pthread_cond_t mCond = PTHREAD_COND_INITIALIZER;
static pthread_mutex_t mMutex = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t cCond = PTHREAD_COND_INITIALIZER;
static pthread_mutex_t cMutex = PTHREAD_MUTEX_INITIALIZER;

void * commandProducer(void * src) {
    int ret;
    string request_str;

    for (int req = 1; req <= STOPPED; ++req) {
      LOGD("Creating request");
      if(pthread_mutex_lock(&cMutex) != 0) {
        LOGE("failed to lock");
        break;
      }

      // if ( req == STOPPED )
      //     req = PALYING;

      mPlayerReq = (state)req;
      request_str = to_string(req);
      LOGD(request_str.c_str());
      LOGD("Reuest send : ");

      if (pthread_mutex_unlock(&cMutex) != 0 ) {
        LOGE("failed to unlock");
        break;
      }

      if (pthread_cond_signal(&cCond) != 0 ){
        LOGE("failed to send request");
        break;
      }
      
      usleep(2000000);
    }

    LOGE("Treminate thread ");
}

void * commandConsumer(void * src) {

#define CMDPLAY "playbin uri=file:///home/ajinath/work/00_Me/c_cpp_shell_script_python/c++/Pthread/gstreamer/start.mp3"
#define CMDPAUSE "playbin uri=file:///home/ajinath/work/00_Me/c_cpp_shell_script_python/c++/Pthread/gstreamer/pause.mp3"
#define CMDSTOP "playbin uri=file:///home/ajinath/work/00_Me/c_cpp_shell_script_python/c++/Pthread/gstreamer/stop.mp3"

  GstElement *pipeline;
  GstBus *bus;
  GstMessage *msg;
  const char * command = NULL;
  int ret;
  state localReq = NONE;


  while (1) {
    if(pthread_mutex_lock(&cMutex) != 0) {
      LOGE("failed to get lock for request");
    }

    while ( mPlayerReq == NONE) {
      LOGE(" wait for request ...");
      if (pthread_cond_wait(&cCond,&cMutex) != 0 ) {
        LOGE(" failed to wakeup for req");
      }

      if (mPlayerReq != NONE) {
        LOGD("Request received ");
        break;
      }

    }

    localReq = mPlayerReq;
    
    switch (localReq) {
      case PALYING:
        LOGD("Request received : PALYING");
        command = CMDPLAY;
        break;  
      case PAUSED:
        LOGD("Request received : PAUSED");
        command = CMDPAUSE;
        break;
      case STOPPED:
        LOGD("Request received : STOPPED");
        command = CMDSTOP;
        break;
    }

    pipeline = gst_parse_launch (command, NULL);

    /* Start playing */
    gst_element_set_state (pipeline, GST_STATE_PLAYING);
    // gst_element_set_state (pipeline, GST_STATE_PAUSED);

    /* Wait until error or EOS */
    bus = gst_element_get_bus (pipeline);
    msg = gst_bus_timed_pop_filtered (bus, GST_CLOCK_TIME_NONE, (GstMessageType) (GST_MESSAGE_ERROR | GST_MESSAGE_EOS));

    /* Free resources */
    if (msg != NULL)
      gst_message_unref (msg);
    gst_object_unref (bus);
    gst_element_set_state (pipeline, GST_STATE_NULL);
    gst_object_unref (pipeline);

    if (pthread_mutex_unlock(&cMutex) != 0) {
      LOGE("failed to unlock on request received");
    }


    ret = pthread_mutex_lock(&mMutex);
    if (ret != 0 ) {
      LOGE("failed to lock ");
    }

    mPlayerState = localReq;
    ret = pthread_mutex_unlock(&mMutex);
    if ( ret !=0 ) {
      LOGE("failed to unlock");
    }

    ret = pthread_cond_signal(&mCond);
    if (ret != 0 ) {
      LOGE("failed to send signal");
    }
    LOGD("sending signal");
    
    if ( localReq == STOPPED) {
      LOGD("Treminate commandConsumer");
      break;
    }
  }
}

void * musixProducer(void * src) {
  const char * src_file = (const char * ) src;

  GstElement *pipeline;
  GstBus *bus;
  GstMessage *msg;
  int ret;
  /* Build the pipeline */
  // uri=file:///path/to/song.mp3
  pipeline = gst_parse_launch (src_file, NULL);


  ret = pthread_mutex_lock(&mMutex);
  if (ret != 0 ) {
    LOGE("failed to lock ");
  }

  while ( mPlayerState == NONE ) {
    LOGE(" wait for signal ...");
    ret = pthread_cond_wait(&mCond,&mMutex);
    if (ret !=0 ) {
      LOGE("failed to wait on condition");
    }
    if (mPlayerState != NONE) {
      LOGD("signal received");
      break;
    }
  }

  ret = pthread_mutex_unlock(&mMutex);
  if ( ret !=0 ) {
    LOGE("failed to unlock");
  }

  switch (mPlayerState) {
    case PALYING:
      /* Start playing */
      gst_element_set_state (pipeline, GST_STATE_PLAYING);
      LOGD("GST_STATE_PLAYING");
      break;
    case PAUSED:
      /* Start playing */
      gst_element_set_state (pipeline, GST_STATE_PAUSED);
      LOGD("GST_STATE_PAUSED");
      break;
    case STOPPED:
      LOGD("GST_STATE_STOPPED");
      goto clean;
      break;
    default:
      LOGE("Unknown state");
  }



  // gst_element_set_state (pipeline, GST_STATE_PAUSED);

  /* Wait until error or EOS */
  bus = gst_element_get_bus (pipeline);
  msg = gst_bus_timed_pop_filtered (bus, GST_CLOCK_TIME_NONE, (GstMessageType) (GST_MESSAGE_ERROR | GST_MESSAGE_EOS));

clean:
  /* Free resources */
  if (msg != NULL)
    gst_message_unref (msg);
  gst_object_unref (bus);
  gst_element_set_state (pipeline, GST_STATE_NULL);
  gst_object_unref (pipeline);

  ret = pthread_mutex_lock(&mMutex);
  if (ret != 0 ) {
    LOGE("failed to lock ");
  }
  
  mPlayerState == NONE;

  ret = pthread_mutex_unlock(&mMutex);
  if ( ret !=0 ) {
    LOGE("failed to unlock");
  }

}

namespace thread_name {
}

int main(int argc, char *argv[])
{

  /* Initialize GStreamer */
  gst_init (&argc, &argv);
  pthread_t musicProducer, cmdProducer, cmdConsumer;

  LOGD("START");
  pthread_create(&cmdProducer, NULL, commandProducer, NULL);
  pthread_create(&cmdConsumer, NULL, commandConsumer, NULL);
  pthread_create(&musicProducer, NULL, musixProducer, (void *)MUSIC_1);
	
  pthread_join(cmdProducer, NULL);
  pthread_join(cmdConsumer, NULL);
  pthread_join(musicProducer, NULL);

	LOGD("END");


	return 0;
}