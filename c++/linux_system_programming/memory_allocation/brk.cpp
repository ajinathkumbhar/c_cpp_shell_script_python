#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <mcheck.h>


void dumpHeap(void) {
    printf("%d \t %p \t %x\n",sbrk(0),sbrk(0),sbrk(0));
}
main(int argc, char * argv[]) {

    int * heapint = NULL;
    mtrace();
    dumpHeap();
    heapint = (int * ) malloc(sizeof(int)*500);
    dumpHeap();
    dumpHeap();

    muntrace();


}
