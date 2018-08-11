#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <gst/gst.h>
#include "log.h"

#define TAG "apptest"

#ifndef SRC_1
#define SRC_1 "playbin uri=file:///home/ajinath/work/00_Me/c_cpp_shell_script_python/c++/Pthread/gstreamer/stop_eng_india.mp3"
#endif

#ifndef SRC_2
#define SRC_2 "playbin uri=file:///home/ajinath/work/00_Me/media/mp3/Tuhi_Hai-(Mr-Jatt.com).mp3"
#endif


using namespace std;
int mArgc;
char **mArgv = NULL;

void cmdSession(const char * src) {
  GstElement *pipeline;
  GstBus *bus;
  GstMessage *msg;

  /* Initialize GStreamer */
  gst_init (&mArgc, &mArgv);

  /* Build the pipeline */
  // uri=file:///path/to/song.mp3
  pipeline = gst_parse_launch (src, NULL);

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
}

int main(int argc, char *argv[])
{
	int mArgc = argc;
	char **mArgv = argv;
	LOGD("start");
	cmdSession(SRC_1);
	cmdSession(SRC_2);

	return 0;
}