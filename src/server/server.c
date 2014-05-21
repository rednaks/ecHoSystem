#include "server.h"


int init_server(int portNum) {

  int sockfd;
  struct sockaddr_in server_addr;

  sockfd = socket(AF_INET, SOCK_STREAM, 0);

  if(sockfd < 0) {
    return sockfd;
  }

  bzero((char*) &server_addr, sizeof(server_addr));

  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = INADDR_ANY;
  server_addr.sin_port = htons(portNum);

  if(bind(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
    return PORT_BIND_ERR;
  }


  if(listen(sockfd, MAX_PENDING_CONNECTIONS) < 0) {
    return LISTEN_ERR;
  }

  return sockfd;
}

