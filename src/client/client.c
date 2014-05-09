#include "client.h"


int se_connecter(const char* host, int portNum) {
  int sockfd;

  struct sockaddr_in server_addr;
  struct hostent *server;

  sockfd = socket(AF_INET, SOCK_STREAM, 0);

  if(sockfd < 0)
    return sockfd; // Erreur lors de l'ouverture du socket


  server = gethostbyname(host);

  if(server == NULL)
    return INVALID_SERVER_ERR; // le nom d'hôte est incorrecte

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
