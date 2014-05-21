#include "client.h"


int Connect(const char* host, int portNum) {
  int sockfd;

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


int sendUseRequestAndWaitResponse(int sockfd, const Client aClient) {
  Message msg;
  msg.client_id = aClient.id; // TODO : have to be dynamic
  msg.cmd = USE_CMD;
  msg.arg = USE_REQ;
  sendMsg(sockfd, msg);

  receiveMsg(sockfd, &msg); // We have to check if it's a USE_CMD

  if(msg.cmd == USE_CMD)
    return msg.arg;
  return -1;

}

int sendInfo(int sockfd, const Client aClient) {
  Message msg;
  msg.client_id = aClient.id;
  msg.cmd = INFO_CMD;
  msg.arg = aClient.useNumber;

  return 0;
}

