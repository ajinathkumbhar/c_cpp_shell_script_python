#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>

void errorExit(const char * msg) {
    printf("%s\n",msg);
    exit(-1);
}

int main(int argc, char * argv[]) {
	int socketFd,clientsockFd, portNo;
	struct sockaddr_in serv_addr,client_addr;
    char buffer[256];
    socklen_t clientlen;
    if (argc < 2 ) {
		fprintf(stderr,"ERROR, no port number provided\n");
		exit(1);
    }
    socketFd = socket(AF_INET,SOCK_STREAM, 0);
    if ( socketFd < 0 ) 
        error("failed to create socket");
    bzero((char *)&serv_addr,sizeof(serv_addr));
    portNo = atoi(argv[1]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portNo);

    if(bind(socketFd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0 ) 
        error("failed to bind socket");

     listen(socketFd,5);
    
     // client
     clientlen = sizeof(client_addr);

     clientsockFd = accept(socketFd,(struct sockadd *)&client_addr, &clientlen);
     if (clientsockFd < 0 )
        error("failed to accept connection ");
     
    bzero(buffer,sizeof(buffer));

    if (read(clientsockFd,buffer,sizeof(buffer)) < 0)
        error("failed to read data");
    if (write(clientsockFd,"OK\n",3) < 0 )
        error("failed to write data");
    close(clientsockFd);
    close(socketFd);
    return 0;
}







