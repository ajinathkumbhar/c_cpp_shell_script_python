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

#include <cstdlib>
#include <gstreamer-1.0/gst/gst.h>
#include <syslog.h>

#include "CarrotMediaPlayer.h"


CarrotMediaPlayer::CarrotMediaPlayer() {
	syslog(LOG_NOTICE,"Default constructor called : CarrotMediaPlayer");
}

CarrotMediaPlayer::CarrotMediaPlayer(int argc, char ** argv) {
    syslog(LOG_NOTICE,"constructor called : CarrotMediaPlayer");
	error = CMP_NONE_ERROR;
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


