
#include "server.h"
#include <pthread.h>



int ClientRangCurrentIndex = 0;


void* clientHandler(void* aClientfd) {
  int sockfd = *((int *)aClientfd);
  int index = 0;
  ClientInfo client;
  startLearningProcess(sockfd, &client);
  // The threashol reached, we add the client to ClientRang
  // FIXME : Add mutex here.
  index = ClientRangCurrentIndex++;  // Should be a critic resource.
  ClientRang[index] = client; // Samething here.

  printf("Client: %d, Threshold : %d, Avg : %d\n", client.id, client.threshold, client.useAverage);



}

int main(int argc, char **argv) {

  int res = init_server(9999);
  pthread_t connections[MAX_CONNECTION];
  int connectedClients = 0;
  int clients_sockfd[MAX_CONNECTION] = {0};


  int client_len;
  int client_addr;
  client_len = sizeof(client_addr);


  while(1) {
    if(connectedClients == MAX_CONNECTION) 
      continue; // We donc accept new clients anymore.

    clients_sockfd[connectedClients - 1] = accept(res, (struct sockaddr*) &client_addr, &client_len);
    pthread_create(connections + (connectedClients - 1), 
        NULL, clientHandler, &clients_sockfd[connectedClients -1]);

  }


  return 0;
}
