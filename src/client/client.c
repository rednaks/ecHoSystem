#include "client.h"


int Connect(const char* host, int portNum) {
  int sockfd;
  int client_id = 1;

  struct sockaddr_in server_addr;
  struct hostent *server;

  sockfd = socket(AF_INET, SOCK_STREAM, 0);

  if(sockfd < 0)
    return sockfd; // -1 : error while opening the socket.


  server = gethostbyname(host);

  if(server == NULL)
    return INVALID_SERVER_ERR; // The host is not valid.

  bzero((char *) &server_addr, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  bcopy((char *) server->h_addr,
        (char *) &server_addr.sin_addr.s_addr,
        server->h_length);

  server_addr.sin_port = htons(portNum);

  if(connect(sockfd, &server_addr, sizeof(server_addr)) < 0) {
    return CONNECTION_ERR;
  }


  return sockfd;
}


int sendUseRequestAndWaitResponse(int sockfd) {
  Message msg;
  msg.client_id = 1; // TODO : have to be dynamic
  msg.cmd = USE_CMD;
  msg.arg = USE_REQ;
  sendMsg(sockfd, msg);
  return 0; // TODO : have to change this.
}
