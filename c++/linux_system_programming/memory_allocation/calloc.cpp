#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>

main(int argc, char * argv[]) {

    struct pcinfo {
        int model;
        int size;
    };

    typedef struct pcinfo t_pcinfo;
    t_pcinfo * pcdata;

    pcdata = (t_pcinfo *) calloc(20,sizeof(t_pcinfo));
    if (pcdata == NULL) {
        printf("failed to allocate memory \n");
        exit(EXIT_FAILURE);
    }

    for( int i=0;i < 20 ; i++) {
         pcdata[i].model = rand() % 100 + 1;
         pcdata[i].size = rand() % 10 + 1;
    }
    
    for( int i=0;i < 20 ; i++) {
        printf("model : %d\tsize : %d\n",pcdata[i].model,pcdata[i].size);
    }

    free(pcdata);
}
