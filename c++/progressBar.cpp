#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<unistd.h>

using namespace std;

int main(int argc,char * argv[] ) {

    int count = 10;
    do {
        usleep(100000);
        printf( "*" );
    } while ( count-- );
    cout << endl;
return EXIT_SUCCESS;
}

