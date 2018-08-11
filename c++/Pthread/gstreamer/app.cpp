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

void * createPipelineAndPlay(void * src) {
	const char * src_file = (const char * ) src;

  GstElement *pipeline;
  GstBus *bus;
  GstMessage *msg;

  /* Build the pipeline */
  // uri=file:///path/to/song.mp3
  pipeline = gst_parse_launch (src_file, NULL);

  /* Start playing */
  while(1) {
    gst_element_set_state (pipeline, GST_STATE_PLAYING);
    LOGD("GST_STATE_PLAYING");
    usleep(2000000);
    gst_element_set_state (pipeline, GST_STATE_PAUSED);
    LOGD("GST_STATE_PAUSED");
    usleep(2000000);
  }
  /* Wait until error or EOS */
  bus = gst_element_get_bus (pipeline);
  msg = gst_bus_timed_pop_filtered (bus, GST_CLOCK_TIME_NONE, (GstMessageType) (GST_MESSAGE_ERROR | GST_MESSAGE_EOS));

  /* Free resources */
  if (msg != NULL)
    gst_message_unref (msg);
  gst_object_unref (bus);
  gst_element_set_state (pipeline, GST_STATE_NULL);
  gst_object_unref (pipeline);
}


int main(int argc, char *argv[])
{

	pthread_t command_proc, music_proc;
  /* Initialize GStreamer */
  gst_init (&argc, &argv);

	//pthread_create(&command_proc, NULL, createPipelineAndPlay, (void *)SRC_1);
  pthread_create(&music_proc, NULL, createPipelineAndPlay, (void *)SRC_2);
  usleep(100000);

	//pthread_join(command_proc, NULL);
  pthread_join(music_proc, NULL);

	LOGD("start");


	return 0;
}