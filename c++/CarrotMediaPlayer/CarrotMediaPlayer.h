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


class CarrotMediaPlayer {
private:
	PlayerStatus status;
	CmpError error;
	int init(int,char**);

public:
	CarrotMediaPlayer();
	CarrotMediaPlayer(int,char **);

	~CarrotMediaPlayer();
	void dumpGstVersion(void);
};


#endif /* CARROTMEDIAPLAYER_H */

