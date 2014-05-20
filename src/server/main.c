#include <stdio.h>

#include "server.h"



int main(int argc, char **argv) {

  int res = init_server(9999);
  printf("Res = %d\n", res);

  int taille = 256;
  char message[taille];

  int client_sockfd, client_len;
  int client_addr;
  client_len = sizeof(client_addr);

  client_sockfd = accept(res, (struct sockaddr*) &client_addr, &client_len);
  int n = receiveMsg(client_sockfd, message, taille);

  if(n < 0){
    perror("RES");
  }

  printf("J'ai reçu : %d octets\n", n);
  printf("Le message est : %s\n", message);

  return 0;
}
