#include<stdio.h>
#include "cmdline.h"

extern char logtag[PROG_NAME_SIZE];

void getmeminfo(void) {
    fprintf(stdout,"%s - %s:%d - %s \n",logtag,__func__,__LINE__,(char * )"8GB");
}
