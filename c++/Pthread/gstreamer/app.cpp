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

#define MUSIC_1 "playbin uri=file:///home/ajinath/work/00_Me/c_cpp_shell_script_python/c++/Pthread/gstreamer/test.mp3"


using namespace std;
enum state {
	NONE = 0,
	PLAYING,
	PAUSED,
	RESUME,
	STOPPED,
};

static state mPlayerState = NONE;
static state mPlayerReq = NONE;

static pthread_cond_t mCond = PTHREAD_COND_INITIALIZER;
static pthread_mutex_t mMutex = PTHREAD_MUTEX_INITIALIZER;

static pthread_cond_t cCond = PTHREAD_COND_INITIALIZER;
static pthread_mutex_t cMutex = PTHREAD_MUTEX_INITIALIZER;

static pthread_cond_t pCond = PTHREAD_COND_INITIALIZER;
static pthread_mutex_t pMutex = PTHREAD_MUTEX_INITIALIZER;

GstElement *mPipeline;
GstBus *mBus;
GstMessage *mMsg;

void * commandProducer(void * src) {
	int ret;
	string request_str;
	int req = PLAYING;

	while (req) {
		LOGD("Creating request");
		if(pthread_mutex_lock(&cMutex) != 0) {
			LOGE("failed to lock");
			break;
		}

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

		usleep(8000000);

		if (req == STOPPED) {
			req = PLAYING;
			continue;
		}
		req++;


	}

	LOGE("Treminate thread ");
}

void * commandConsumer(void * src) {

#define CMDPLAY "playbin uri=file:///home/ajinath/work/00_Me/c_cpp_shell_script_python/c++/Pthread/gstreamer/start.mp3"
#define CMDPAUSE "playbin uri=file:///home/ajinath/work/00_Me/c_cpp_shell_script_python/c++/Pthread/gstreamer/pause.mp3"
#define CMDRESUME "playbin uri=file:///home/ajinath/work/00_Me/c_cpp_shell_script_python/c++/Pthread/gstreamer/resume.mp3"
#define CMDSTOP "playbin uri=file:///home/ajinath/work/00_Me/c_cpp_shell_script_python/c++/Pthread/gstreamer/stop.mp3"

	GstElement *pipeline;
	GstBus *bus;
	GstMessage *msg;
	const char * command = NULL;
	int ret;
	state localReq = NONE;
	state prevReq = NONE;
	state newReq = NONE;

	while (1) {
		if(pthread_mutex_lock(&cMutex) != 0) {
			LOGE("failed to get lock for request");
		}
		printf("prevReq : %d , newReq : %d \n",prevReq,newReq);

		while ( mPlayerReq == NONE || mPlayerReq == prevReq) {
			LOGE(" wait for request ...");
			if (pthread_cond_wait(&cCond,&cMutex) != 0 ) {
				LOGE(" failed to wakeup for req");
			}
			newReq = mPlayerReq;

			if (mPlayerReq != NONE &&  mPlayerReq != prevReq) {
				LOGD("Request received ");
				break;
			}

		}

		localReq = mPlayerReq;

		switch (localReq) {
			case PLAYING:
			LOGD("Request received : PLAYING");
			command = CMDPLAY;
			break; 

			case PAUSED:
			LOGD("Request received : PAUSED");
			command = CMDPAUSE;
			break;
			case RESUME:
			LOGD("Request received : RESUME");
			command = CMDRESUME;
			break; 
			case STOPPED:
			LOGD("Request received : STOPPED");
			command = CMDSTOP;
			break;
		}

		pipeline = gst_parse_launch (command, NULL);

    /* Start playing */
		gst_element_set_state (pipeline, GST_STATE_PLAYING);

    /* Wait until error or EOS */
		bus = gst_element_get_bus (pipeline);
		msg = gst_bus_timed_pop_filtered (bus, GST_CLOCK_TIME_NONE, (GstMessageType) (GST_MESSAGE_ERROR | GST_MESSAGE_EOS));

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

		prevReq = localReq;

		if (pthread_mutex_unlock(&cMutex) != 0) {
			LOGE("failed to unlock on request received");
		}

	}
}

void * musixThread(void * pipeline) {
	LOGD("Enter");

	while(1) {
		if(pthread_mutex_lock(&pMutex) !=0 ) {
			LOGE("failed to get lock");
		}

		mPipeline = gst_parse_launch (MUSIC_1, NULL);

		if (mPipeline == NULL ) {
			LOGE("failed to gst_parse_launch");
			pthread_cancel(pthread_self());
		}

		if (pthread_mutex_unlock(&pMutex) != 0) {
			LOGE("failed to unlock");
		}

		if (pthread_cond_signal(&pCond) !=0 ) {
			LOGD("failed to send signal");
		}

    /* Wait until error or EOS */
		mBus = gst_element_get_bus (mPipeline);

		LOGD("Wait until error or EOS");
		mMsg = gst_bus_timed_pop_filtered (mBus, GST_CLOCK_TIME_NONE, (GstMessageType) (GST_MESSAGE_ERROR | GST_MESSAGE_EOS));

    /* Free resources */
		if (mMsg != NULL)
			gst_message_unref (mMsg);
		gst_object_unref (mBus);

		LOGD("EXIT");
	}



  //=========================================

}
void * musixProducer(void * src) {
	LOGD("Enter");
	const char * src_file = (const char * ) src;

	int ret;
	pthread_t playThread = NULL;
	state prevState = NONE;
	state newState = NONE;

	while (1) {
		ret = pthread_mutex_lock(&mMutex);
		if (ret != 0 ) {
			LOGE("failed to lock ");
		}

		if (playThread == NULL) {
			LOGE("creating new playthread");
			pthread_create(&playThread, NULL, musixThread, NULL);
			pthread_setname_np(playThread,"playThread");
		}

		while ( mPipeline == NULL ) {
			LOGE(" wait for pipeline signal musixThread ...");
			ret = pthread_cond_wait(&pCond,&pMutex);
			if (ret !=0 ) {
				LOGE("failed to wait on condition");
			}
			if (mPipeline != NULL) {
				LOGD("signal received from musixThread");
				break;
			}
		}


		while (mPlayerState == NONE || mPlayerState == prevState) {
			LOGE(" wait for signal ...");
			ret = pthread_cond_wait(&mCond,&mMutex);
			if (ret !=0 ) {
				LOGE("failed to wait on condition");
			}
			if (mPlayerState != NONE && mPlayerState != prevState ) {
				LOGD("signal received");
				break;
			}
		}

		switch (mPlayerState) {
			case PLAYING:
            /* Start playing */
			gst_element_set_state (mPipeline, GST_STATE_PLAYING);
			LOGD("GST_STATE_PLAYING");
			break;
			case PAUSED:
            /* Start playing */
			gst_element_set_state (mPipeline, GST_STATE_PAUSED);
			LOGD("GST_STATE_PAUSED");
			break;
			case RESUME:
            /* Start playing */
			gst_element_set_state (mPipeline, GST_STATE_PLAYING);
			LOGD("GST_STATE_RESUME");
			break;
			case STOPPED:
			LOGD("GST_STATE_STOPPED");
			gst_element_set_state (mPipeline, GST_STATE_NULL);
			gst_object_unref (mPipeline);
			pthread_cancel(playThread);
			mPipeline = NULL;
			mBus = NULL;
			mMsg = NULL;
			playThread = NULL;
			break;
			default:
			LOGE("Unknown state");
		}

		prevState = mPlayerState;

		ret = pthread_mutex_unlock(&mMutex);
		if ( ret !=0 ) {
			LOGE("failed to unlock");
		}

	}

	LOGD("Enter");
}

int main(int argc, char *argv[])
{

  /* Initialize GStreamer */
	gst_init (&argc, &argv);
	pthread_t musicProducer, cmdProducer, cmdConsumer;

	LOGD("START");
	pthread_create(&musicProducer, NULL, musixProducer, (void *)MUSIC_1);
	pthread_setname_np(musicProducer,"musicProducer");

	pthread_create(&cmdConsumer, NULL, commandConsumer, NULL);
	pthread_setname_np(cmdConsumer,"cmdConsumer");

	pthread_create(&cmdProducer, NULL, commandProducer, NULL);
	pthread_setname_np(cmdProducer,"cmdProducer");



	
	pthread_join(cmdProducer, NULL);
	pthread_join(cmdConsumer, NULL);
	pthread_join(musicProducer, NULL);

	LOGD("END");


	return 0;
}