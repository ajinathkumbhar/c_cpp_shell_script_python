
#include <syslog.h>
#include <string.h>
#include "CarrotMediaPlayer.h"

static void sysLogInit(const char *);

static void sysLogInit(const char * kCommand) {
	const char * kProcess = strstr(kCommand,"/") + 1;
	openlog (kProcess, LOG_INFO | LOG_PID | LOG_NDELAY, LOG_LOCAL1);
	syslog (LOG_NOTICE, "%s : success ",__func__);
}


int main(int argc, char** argv) {
	sysLogInit(argv[0]);
	CarrotMediaPlayer cPlayer(argc,argv);
	if(!cPlayer.prepare()){
		syslog(LOG_ERR,"prepare failed");
		return -1;
	}
	
    return 0;
}
