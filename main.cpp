#include"socket.h"
#include<sys/socket.h>
#include<netinet/in.h>
#include<netinet/ip.h>
#include<iostream>
#include<cstring>
#include<unistd.h>
using namespace std;
int main(int argc, char *argv[])
{
    int servfd = Socket(AF_INET,SOCK_STREAM,0);
    int clientfd;
    unsigned int cl_addrlen;
    struct sockaddr_in addr;
    struct sockaddr client_addr;
    char recv[100];

    Bind(servfd,GetSockaddr(&addr,9998,"127.0.0.1"),sizeof(struct sockaddr));
    Listen(servfd,5);
    for(;;){
        clientfd = Accept(servfd,&client_addr,&cl_addrlen);
        cout<<"accept"<<endl;
        pid_t child = fork();
        if( child==0 ){
            close(servfd);
            read(clientfd,recv,sizeof(recv));
            write(clientfd,recv,strlen(recv));
            close(clientfd);
            exit(0);
        }
        else if( child>0 ){
            close(clientfd);
        }
        else{
            cout<<"fork error: "<<strerror(errno)<<endl;
            return -1;
        }
    }

//    read(clientfd,recv,sizeof(recv));
//    write(clientfd,recv,strlen(recv));
}
