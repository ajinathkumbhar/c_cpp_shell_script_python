#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <gst/gst.h>
#include <pthread.h>
#include <unistd.h>

#include "log.h"


#define TAG "apptest"
#define SRC_1 "playbin uri=file:///home/ajinath/work/00_Me/c_cpp_shell_script_python/c++/Pthread/gstreamer/stop_eng_india.mp3"
#define SRC_2 "playbin uri=file:///home/ajinath/work/00_Me/media/mp3/Tuhi_Hai-(Mr-Jatt.com).mp3"



using namespace std;
enum state {
  NONE,
  PALYING,
  PAUSED
};

static state mPalyer_state = NONE;
static pthread_cond_t mCond_play = PTHREAD_COND_INITIALIZER;
static pthread_mutex_t mMutex_play = PTHREAD_MUTEX_INITIALIZER;



void * commandPipe(void * src) {
	const char * src_file = (const char * ) src;

  GstElement *pipeline;
  GstBus *bus;
  GstMessage *msg;
  int ret;
  /* Build the pipeline */
  // uri=file:///path/to/song.mp3
  pipeline = gst_parse_launch (src_file, NULL);

  /* Start playing */
  gst_element_set_state (pipeline, GST_STATE_PLAYING);
  LOGD("GST_STATE_PLAYING");

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

  ret = pthread_mutex_lock(&mMutex_play);
  if (ret != 0 ) {
    LOGE("failed to lock ");
  }

  mPalyer_state = PALYING;
  ret = pthread_mutex_unlock(&mMutex_play);
  if ( ret !=0 ) {
    LOGE("failed to unlock");
  }

  ret = pthread_cond_signal(&mCond_play);
  if (ret != 0 ) {
    LOGE("failed to send signal");
  }
  LOGD("sending signal");

}

void * musicPipe(void * src) {
  const char * src_file = (const char * ) src;

  GstElement *pipeline;
  GstBus *bus;
  GstMessage *msg;
  int ret;
  /* Build the pipeline */
  // uri=file:///path/to/song.mp3
  pipeline = gst_parse_launch (src_file, NULL);


  ret = pthread_mutex_lock(&mMutex_play);
  if (ret != 0 ) {
    LOGE("failed to lock ");
  }

  while ( mPalyer_state == NONE ) {
    ret = pthread_cond_wait(&mCond_play,&mMutex_play);
    if (ret !=0 ) {
      LOGE("failed to wait on condition");
    }
    if (mPalyer_state != NONE) {
      LOGD("signal received");
      break;
    }
  }

  ret = pthread_mutex_unlock(&mMutex_play);
  if ( ret !=0 ) {
    LOGE("failed to unlock");
  }

  switch (mPalyer_state) {
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
    default:
      LOGE("Unknown state");
  }



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

  ret = pthread_mutex_lock(&mMutex_play);
  if (ret != 0 ) {
    LOGE("failed to lock ");
  }
  
  mPalyer_state == NONE;

  ret = pthread_mutex_unlock(&mMutex_play);
  if ( ret !=0 ) {
    LOGE("failed to unlock");
  }

}


int main(int argc, char *argv[])
{

	pthread_t command_proc, music_proc;
  /* Initialize GStreamer */
  gst_init (&argc, &argv);

	pthread_create(&command_proc, NULL, commandPipe, (void *)SRC_1);
  pthread_create(&music_proc, NULL, musicPipe, (void *)SRC_1);
	
  pthread_join(command_proc, NULL);
  LOGE("command_proc died");
  pthread_join(music_proc, NULL);

	LOGD("start");


	return 0;
}