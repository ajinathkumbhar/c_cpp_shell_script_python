
#include <syslog.h>
#include <string.h>
#include "CarrotMediaPlayer.h"

static void sysLogInit(const char *);
void * play(void *);
static void sysLogInit(const char * kCommand) {
	const char * kProcess = strstr(kCommand,"/") + 1;
	openlog (kProcess, LOG_INFO | LOG_PID | LOG_NDELAY, LOG_LOCAL1);
	syslog (LOG_NOTICE, "%s : success ",__func__);
}

void * play(void * cPlayer) {
    CarrotMediaPlayer * cmPlayer = (CarrotMediaPlayer*) cPlayer;
    cmPlayer->play();
    return (void *)0;
}

int main(int argc, char** argv) {
	sysLogInit(argv[0]);
	CarrotMediaPlayer cPlayer(argc,argv);
	if(!cPlayer.prepare()){
		syslog(LOG_ERR,"prepare failed");
		return -1;
	}
    pthread_t playerThread;
    pthread_create(&playerThread,NULL,play,(void *)cPlayer.play());
    pthread_join(playerThread,NULL);
    return 0;
}

