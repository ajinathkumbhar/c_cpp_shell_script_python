/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CarrotMediaPlayer.cpp
 * Author: ajinath
 *
 * Created on 18 August, 2018, 3:46 PM
 *

gst_pipeline_new
gst_element_factory_make
g_object_get
g_object_set
gst_object_unref
gst_bin_add_many
gst_element_link_many
gst_element_set_state

 */



#include "CarrotMediaPlayer.h"
GMainLoop * gLoop;
void * cmPlayer(void *);
struct GstplayerState gCmPlayerState;
static pthread_mutex_t gCmStateMutex = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t gCmStateCond = PTHREAD_COND_INITIALIZER;

gboolean busCallBack(GstBus *bus, GstMessage *message, gpointer data);


CarrotMediaPlayer::CarrotMediaPlayer() {
	syslog(LOG_NOTICE,"Default constructor called : CarrotMediaPlayer");
}

CarrotMediaPlayer::CarrotMediaPlayer(int argc, char ** argv) {
    syslog(LOG_NOTICE,"constructor called : CarrotMediaPlayer");
	error = CMP_OK;
	status = CMP_NONE;
    // gst component init
    static std::string testFile(
           "/home/ajinath/work/00_Me/c_cpp_shell_script_python/c++/CarrotMediaPlayer/files/test.mp3");
    GstComp.fileSrc = testFile;
    GstComp.pipeline = NULL;
    GstComp.bus = NULL;
    GstComp.srcElement = NULL;
    GstComp.filter = NULL;
    GstComp.sinkElement = NULL;

    gCmPlayerState.newState = GST_STATE_NULL;
    gCmPlayerState.oldState = GST_STATE_NULL;
    gCmPlayerState.pendingState = GST_STATE_NULL;

	GError * gstErr = NULL;

    if(!gst_init_check(&argc,&argv,&gstErr)){
   		syslog (LOG_ERR, "gst_init_check failed ");
    }
    syslog(LOG_NOTICE,"gst_init_check done");
    dumpGstVersion();
}


CarrotMediaPlayer::~CarrotMediaPlayer() {
	syslog(LOG_NOTICE,"De-constructor called : CarrotMediaPlayer");
	this->tearDown();
}	

void CarrotMediaPlayer::dumpGstVersion(){
	guint major, minor, micro, nano;
	gchar *nano_str;
	gst_version(&major, &minor, &micro, &nano);
	if (nano == 1)
		nano_str = (gchar*)"(CSV)";
	else if ( nano == 2 ) 
		nano_str = (gchar*)"(Prerelease)";
	else
		nano_str = (gchar*)"NN";
	syslog(LOG_INFO,"Gstremer version : %d.%d.%d.%d : %s ", \
		major,minor,micro,nano,nano_str);

}

void * cmPlayer(void * gComp) {
    GstComponent * GstComp = (GstComponent * ) gComp;
    guint busWatchId;
    std::string cmd("playbin uri=file://") ;
    cmd.append(GstComp->fileSrc);
    syslog(LOG_DEBUG,"cmplayer thread started : %s",cmd.c_str());


    while (1) {
  /*    GstComp->pipeline = gst_pipeline_new ("cmpPipeline");
        GstComp->srcElement = gst_element_factory_make ("fackesrc","cmpsrc");
        GstComp->filter = gst_element_factory_make ("identity", \
                                                    "cmpFileterIdentity");
        GstComp->sinkElement = gst_element_factory_make ("fakesink", "cmpSink");

        if ( !GstComp->pipeline || !GstComp->srcElement ||
             !GstComp->filter || !GstComp->sinkElement) {
            syslog(LOG_CRIT,"failed  to create factory elements \n");
        }

        gst_bin_add_many (GST_BIN(GstComp->pipeline), GstComp->srcElement, \
                          GstComp->filter, GstComp->sinkElement, NULL);

        if (!gst_element_link_many(GstComp->srcElement, GstComp->filter, \
                                   GstComp->sinkElement, NULL)) {
            syslog(LOG_CRIT,"failed  to gst_element_link_many \n");
        }
*/
        pthread_mutex_lock(&gCmStateMutex);
        GstComp->pipeline = gst_parse_launch(cmd.c_str(), NULL);
        if ( !GstComp->pipeline) {
            syslog(LOG_CRIT,"failed  to create factory elements \n");
            break;
        }
        GstComp->bus = gst_pipeline_get_bus (GST_PIPELINE (GstComp->pipeline));
        busWatchId = gst_bus_add_watch (GstComp->bus, busCallBack, NULL);
        gst_object_unref (GstComp->bus);
        gCmPlayerState.newState = GST_STATE_READY;

        pthread_mutex_unlock(&gCmStateMutex);
        pthread_cond_signal(&gCmStateCond);

        gLoop = g_main_loop_new (NULL, FALSE);
        g_main_loop_run (gLoop);

        gst_element_set_state (GstComp->pipeline, GST_STATE_NULL);
        gst_object_unref (GstComp->pipeline);
        g_source_remove (busWatchId);
        g_main_loop_unref (gLoop);
        GstComp->pipeline = NULL;
    }

    return (void *)0;
}

gboolean busCallBack(GstBus *bus, GstMessage *message, gpointer data) {
    //syslog(LOG_INFO, "Got %s message ",GST_MESSAGE_TYPE_NAME (message));

	switch (GST_MESSAGE_TYPE (message)) {
		case GST_MESSAGE_ERROR:
			GError *err;
			gchar *debug;

            gst_message_parse_error(message, &err, &debug);
			syslog(LOG_ERR, "bus Error: %s",err->message);
			g_error_free(err);
			g_free(debug);

			g_main_loop_quit(gLoop);
			break;
		case GST_MESSAGE_EOS:
			syslog(LOG_DEBUG, "Bus EOS");
            pthread_mutex_lock(&gCmStateMutex);
            gCmPlayerState.newState = GST_STATE_NULL;
            gCmPlayerState.oldState = GST_STATE_NULL;
            gCmPlayerState.pendingState = GST_STATE_NULL;
            pthread_mutex_unlock(&gCmStateMutex);

            g_main_loop_quit(gLoop);
            break;
        case GST_MESSAGE_STATE_CHANGED:
            gst_message_parse_state_changed(message,&gCmPlayerState.oldState,
                                            &gCmPlayerState.newState, \
                                            &gCmPlayerState.pendingState);
            syslog(LOG_DEBUG, "oldstate : %d, Newstate : %d, Pending: %d", \
                    gCmPlayerState.oldState,gCmPlayerState.newState, \
                    gCmPlayerState.pendingState);
    default:
            //syslog(LOG_DEBUG, "Unhandled bus message : %s", GST_MESSAGE_TYPE_NAME(message));
			break;
	}
   /* we want to be notified again the next time there is a message
   * on the bus, so returning TRUE (FALSE means we want to stop watching
   * for messages on the bus and our callback should not be called again)
   */
	return CMP_OK;
}

bool CarrotMediaPlayer::prepare(){
    pthread_t cmPlayerThread;
    pthread_create(&cmPlayerThread,NULL,cmPlayer,(void *)&GstComp);
  //  pthread_join(cmPlayerThread,NULL);
    return true;
}

bool CarrotMediaPlayer::play() {

    GstStateChangeReturn ret;
    pthread_mutex_lock(&gCmStateMutex);
    while (1) {
        pthread_cond_wait(&gCmStateCond,&gCmStateMutex);
        if (gCmPlayerState.newState == GST_STATE_READY) {
            syslog(LOG_DEBUG, "single received for play");
            break;
        }
        if (gCmPlayerState.newState == GST_STATE_NULL) {
            pthread_mutex_unlock(&gCmStateMutex);
            return true;
        }
    }
    pthread_mutex_unlock(&gCmStateMutex);
    ret = gst_element_set_state (GstComp.pipeline, GST_STATE_PLAYING);
    if (ret == GST_STATE_CHANGE_FAILURE) {
        syslog (LOG_ERR,"Unable to set the pipeline to the playing state.\n");
        gst_object_unref (GstComp.pipeline);
        return false;
    }
    syslog(LOG_INFO,"Play");
    return true;
}

void CarrotMediaPlayer::tearDown() {
	gchar * elementName;
	GstElement * element;
	for (unsigned int eIndex = 0 ; eIndex < gstElementList.size(); eIndex++ ) {
		element = gstElementList.at(eIndex);
		g_object_get (G_OBJECT (element), "name" , &elementName, NULL);
		syslog (LOG_DEBUG, "gst_object_unref called for element: %s", (char *)elementName);
		//gst_object_unref (GST_OBJECT (element));
		//g_free (elementName);
	}
}
