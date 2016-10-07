#ifndef SOCKET_H
#define SOCKET_H
#include<sys/types.h>
#include<sys/socket.h>

int Socket(int domain, int type, int protocol);

const struct sockaddr* GetSockaddr(struct sockaddr_in* addr, int port, const char*sin_addr);

int Bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);

int Listen(int sockfd, int backlog);

int Accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);

#endif // SOCKET_H
