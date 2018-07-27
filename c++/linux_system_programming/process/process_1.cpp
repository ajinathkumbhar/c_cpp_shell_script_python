#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

char globBuf[65536];
int primers[] = {2,3,5,7};

static int square(int x) {
    int result;
    result = x * x ;
    return result;
}

static void doClac(int val) {
    printf("The square is %d is %d \n", val,square(val));
    if (val < 1000 ){
        int t;
        t = val * val * val;
        printf(" The Cube of %d is %d \n", val,t);
    }
}

int main(int argc, char * argv[]) {
    static int key = 9973;
    static char mbuf[10240000];
    char *p;
    p = (char*)malloc(1024);
    doClac(key);
    exit(EXIT_SUCCESS);
}