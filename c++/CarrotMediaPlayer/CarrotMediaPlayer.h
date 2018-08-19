/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CarrotMediaPlayer.h
 * Author: ajinath
 *
 * Created on 18 August, 2018, 3:47 PM
 */

#include <vector>
#include <cstdlib>
#include <syslog.h>
#include <gst/gst.h>
#include <string.h>
#include <iostream>

#ifndef CARROTMEDIAPLAYER_H
#define CARROTMEDIAPLAYER_H

#define MAX_FILENAMESIZE 256
enum CmpError {
	CMP_OK = 1,
    CMP_GST_INIT_ERROR = 131,
    CMP_PREPARE_ERROR= 132,
};

enum PlayerStatus {
	CMP_NONE=-1,
	CMP_PLAY,
	CMP_PAUSE,
	CMP_RESUME,
	CMP_STOP,
	CMP_REPLAY,
	CMP_FORWARD,
	CMP_REVERS,
};

struct GstComponent
{
	GstElement *pipeline; 
	GstElement *srcElement;
	GstElement *filter;
	GstElement *sinkElement;
	GstBus *bus;
    std::string fileSrc;
};

struct GstplayerState {
    GstState oldState;
    GstState newState;
    GstState pendingState;
};


class CarrotMediaPlayer {
private:
    GstComponent GstComp;
	PlayerStatus status;
	CmpError error;
	std::vector<GstElement *> gstElementList;
    int init(int,char**);
public:
	CarrotMediaPlayer();
	CarrotMediaPlayer(int,char **);
    ~CarrotMediaPlayer();

    void dumpGstVersion(void);
	bool prepare(void);
    bool play(void);
	void tearDown(void);

};


#endif /* CARROTMEDIAPLAYER_H */

