#include"socket.h"
#include<sys/socket.h>
#include<netinet/in.h>
#include<netinet/ip.h>
int main(int argc, char *argv[])
{
    int servfd = Socket(AF_INET,SOCK_STREAM,0);
    int clientfd;
    unsigned int cl_addrlen;
    struct sockaddr_in addr;
    struct sockaddr client_addr;

    Bind(servfd,GetSockaddr(&addr,9999,"127.0.0.1"),sizeof(struct sockaddr));
    Listen(servfd,5);
    clientfd = Accept(servfd,&client_addr,&cl_addrlen);
}
