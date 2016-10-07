#include<sys/socket.h>
#include<sys/types.h>
#include<cstring>
#include<errno.h>
#include<iostream>
#include<netinet/in.h>
#include<netinet/ip.h>
#include<arpa/inet.h>
#include "socket.h"
using namespace std;

int Socket(int domain, int type, int protocol){
    int fd = socket(domain,type,protocol);
    if( fd<0 ){
        cout<<"socket error: "<<strerror(errno)<<endl;
        exit(-1);
    }
    else return fd;
}

const struct sockaddr* GetSockaddr(struct sockaddr_in* addr, int port, const char*sin_addr){
    addr->sin_family = AF_INET;
    addr->sin_port = htons(port);
    addr->sin_addr.s_addr = inet_addr(sin_addr);
    return (struct sockaddr*)addr;
}

int Bind(int sockfd, const sockaddr* addr, socklen_t addrlen){
    int status = bind(sockfd,addr,addrlen);
    if( status<0 ){
        cout<<"bind error: "<<strerror(errno)<<endl;
        exit(-1);
    }
    else return status;
}

int Listen(int sockfd, int backlog){
    int status = listen(sockfd,backlog);
    if( status<0 ){
        cout<<"listen error: "<<strerror(errno)<<endl;
        exit(-1);
    }
    else return status;
}

int Accept(int sockfd, sockaddr* addr, socklen_t* addrlen){
    int status  = accept(sockfd,addr,addrlen);
    if( status<0 ){
        cout<<"accept error: "<<strerror(errno)<<endl;
        exit(-1);
    }
    else return status;
}
