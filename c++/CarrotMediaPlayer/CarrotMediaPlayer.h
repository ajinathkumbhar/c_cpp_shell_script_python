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

#ifndef CARROTMEDIAPLAYER_H
#define CARROTMEDIAPLAYER_H

enum CmpError {
    CMP_NONE_ERROR = -1,
    GST_INIT_ERROR = 131,
    
};

CmpError gCmpError = CMP_NONE_ERROR;

static int init(int,char**);
static void dumpGstVersion(void);
static void sysLogInit(const char *);

#endif /* CARROTMEDIAPLAYER_H */

