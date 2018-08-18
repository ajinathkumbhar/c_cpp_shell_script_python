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
 */



#include "CarrotMediaPlayer.h"


CarrotMediaPlayer::CarrotMediaPlayer() {
	syslog(LOG_NOTICE,"Default constructor called : CarrotMediaPlayer");
}

CarrotMediaPlayer::CarrotMediaPlayer(int argc, char ** argv) {
    syslog(LOG_NOTICE,"constructor called : CarrotMediaPlayer");
	error = CMP_OK;
	status = CMP_NONE;
	GError * gstErr = NULL;

    if(!gst_init_check(&argc,&argv,&gstErr)){
   		syslog (LOG_ERR, "gst_init_check failed ");
    }
    syslog(LOG_NOTICE,"gst_init_check done");
    dumpGstVersion();
}


CarrotMediaPlayer::~CarrotMediaPlayer() {
	syslog(LOG_NOTICE,"De-constructor called : CarrotMediaPlayer");
	for (unsigned int eIndex = 0 ; eIndex < gstElementList.size(); eIndex++ )
		gst_object_unref (GST_OBJECT (gstElementList.at(eIndex)));
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

bool CarrotMediaPlayer::prepare(){
	GstElement * elementSrc;
	elementSrc = gst_element_factory_make("fakesrc","cmpsrc");
	if (!elementSrc) {
		syslog(LOG_CRIT,"failed  to creatre element of type cmpsrc \n");
		this->error = CMP_PREPARE_ERROR;
		return false;
	}
	gstElementList.push_back(elementSrc);
	return true;
}

