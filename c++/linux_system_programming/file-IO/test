#include<sys/stat.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
#include<sys/types.h>
#include<fcntl.h>


#ifndef BUF_SIZE
#define BUF_SIZE 1024
#endif

using namespace std;
int main(int argc, char * argv[]) {
    int inputFd, outputFd, openFlags;

    mode_t filePerms;
    ssize_t numRead;
    char buf[BUF_SIZE];

    if ( argc !=3 || strcmp(argv[1], "--help") == 0) {
        cout << "%s oldfile newfile\n" << argv[0] << endl;
        exit(EXIT_FAILURE);
    } 

   /*open inpout and output file*/

    inputFd = open(argv[1],O_RDONLY);
    if (inputFd == -1 ) {
        cout << " Open file erro " << argv[1] << endl;
        exit(EXIT_FAILURE);
    }

    openFlags = O_CREAT | O_WRONLY | O_TRUNC;
    filePerms = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP |
                S_IROTH | S_IWOTH ;

    outputFd = open(argv[2],openFlags,filePerms);
    if ( outputFd == -1 ) {
        cout << " Failed to create file " << argv[2] << endl;
        exit(EXIT_FAILURE);
     }
    
    /* Transfer data until we encounter end of input or en error */

    while ( (numRead = read(inputFd,buf,BUF_SIZE)) > 0) 
        if(write(outputFd,buf,numRead) != numRead) {
            cout  << "Failed to write buf " << endl;
        }

    if (numRead == -1) {
        cout << "Read error " << endl;
        exit(EXIT_FAILURE);
    }

    if (close(inputFd) == -1) {
        cout << "failed to close input fd " << endl;
        exit(EXIT_FAILURE);
    }
    
    if (close(outputFd) == -1 ) {
        cout << " failed to close output fd " << endl;
        exit(EXIT_FAILURE);
    }
    
    exit(EXIT_SUCCESS);

            

}

