#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "cmdline.h"
#include<errno.h>
#include<unistd.h>

#define CLOGE(msg) \
    fprintf(stderr,"%s:%d %s E - %s \n",__func__,__LINE__,logtag,msg);
#define CLOGI(msg) \
    fprintf(stdout,"%s:%d %s I - %s \n",__func__,__LINE__,logtag,msg);

char TAG[PROG_NAME_SIZE]= {0};
char logtag[PROG_NAME_SIZE]= {0};

extern void getmeminfo(void);
void printError(char * errMsg,bool terminate);
void printInfo(char * Msg);


/* pcinfo class to store pc info */
class pcinfo {
    private:
        char oem[PROP_SIZE];
        char model[PROP_SIZE];
        float size;
    public:
        pcinfo(void);
        ~pcinfo(void);
        void setinfo(char * manufacturer,char * model,float size);
        
};

void pcinfo::setinfo(char * manufacturer,char * mdl,float sz) {
    strcpy(oem,manufacturer);
    strcpy(model,mdl);
    size = sz;
    //CLOGI(getpid());
    printf("i----------------------%d \n",getpid());
}

pcinfo::pcinfo(void) {
    printInfo((char*)"constructor called");
}

pcinfo::~pcinfo(void) {
    printInfo((char*)"deconstructor called ");
}

/* print error on screen on stderr */
void printError(char * errMsg,bool terminate=false) {
    fprintf(stderr,"%s - %s:%d - %s \n",logtag,__func__,__LINE__,errMsg);
    if (terminate)
        exit(EXIT_FAILURE);
}

/* print info on screen stdout */
void printInfo(char * Msg) {
    fprintf(stdout,"%s - %s:%d - %s \n",logtag,__func__,__LINE__,Msg);
}

/* init program */
void init(char * prog_name) {
#ifdef LOGTAG
    strcpy(logtag,LOGTAG); 
#else
    strcpy(logtag,prog_name);
#endif
}

/* print usage */
void usage(void) {
    printf("\n%s <options> \n",logtag);
    printf("\t--setinfo - To store pcinfo\n");
    printf("\t--getinfo - To display pcinfo\n\n");
}

void dumpCmdline(char **element) {
    for(;*element != NULL;element++)
        CLOGI(*element);
}

void dumpenv(char **element) {
    for(;*element != NULL;element++)
        CLOGI(*element);
}
extern char **environ;
/* main function starts */
int main(int argc, char * argv[]) {
    init(argv[0]);
    pcinfo dell;
    CLOGE("asdf");
    CLOGI(program_invocation_name);
    CLOGI(program_invocation_short_name);
    dumpCmdline(argv); 
    //dumpenv(environ);
    CLOGI(getenv("HOME"));
    if ( argc != 2 ) {
       usage();
       printError((char * )" invalid argument - check usage",true);
    }
    printf("argv[1] : %s\n",argv[1]);
    if ( strcmp(argv[1],"--setinfo") == 0 ) {
        printInfo("call setinfo ");
        dell.setinfo((char*)"dell",(char*)"E6440",14.5); 
    }
    else if ( strcmp(argv[1],"--getinfo") == 0 ) {
        printInfo("call getinfo");
        getmeminfo();
    } else {
        printInfo("in side else");
        usage();
        printError((char *) "invalide argument",true);
    }
    exit(EXIT_SUCCESS);
}

