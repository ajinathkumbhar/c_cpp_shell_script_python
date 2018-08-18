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
#include <iostream>
#include <gstreamer-1.0/gst/gst.h>
#include <syslog.h>
#include <string.h>

#include "CarrotMediaPlayer.h"

using namespace std;


static int init(int ac,char** av){
	sysLogInit(av[0]);
	GError * gstErr = NULL;

    if(!gst_init_check(&ac,&av,&gstErr)){
   		syslog (LOG_ERR, "gst_init_check failed ");
    	return false;
    }
    return true;
}

static void dumpGstVersion(){
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

static void sysLogInit(const char * kCommand) {
	const char * kProcess = strstr(kCommand,"/") + 1;
	openlog (kProcess, LOG_INFO | LOG_PID | LOG_NDELAY, LOG_LOCAL1);
	syslog (LOG_NOTICE, "%s : success ",__func__);
}


/*
 * 
 */
int main(int argc, char** argv) {
	init(argc,argv);
    // if(!gst_init_check(&argc,&argv,&gstErr)){
   	// 	syslog (LOG_ERR, "gst_init_check failed : %d",gstErr);
    // 	return -1;
    // }
    dumpGstVersion();


    return 0;
}

