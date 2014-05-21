
#include "server.h"



int main(int argc, char **argv) {

  int res = init_server(9999);
  printf("Res = %d\n", res);


  int client_sockfd, client_len;
  int client_addr;
  client_len = sizeof(client_addr);

  client_sockfd = accept(res, (struct sockaddr*) &client_addr, &client_len);

  Message msg;
  receiveMsg(client_sockfd, &msg);


  printf("J'ai reçu un message : de la part de %d, cmd : %d, arg = %d\n", msg.client_id, msg.cmd, msg.arg);

  return 0;
}
