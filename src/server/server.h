#ifndef SERVER_H
#define SERVER_H

#define MAX_CONNECTION              100
#define MAX_PENDING_CONNECTIONS     10

#define PORT_BIND_ERR               -2
#define LISTEN_ERR                  -3

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

#include "clientInfo.h"

#include "../common/messages.h"

ClientInfo ClientRang[MAX_CONNECTION];


/*
  init_serve(portNum) :
  Will prepare the server to accept connections.
  Returns :
    sockfd : if everything is okey.
    -1 : if error on opening the socket.
    PORT_BIND_ERR : if the address is busy.
    LISTEN_ERR : not able to listen.
*/
int init_server(int portNum);

/*
   Will send an information request to a given
   client, this should be called whenever the
   threashold reached.
*/
void sendInfoRequest(int sockfd, ClientInfo *aClient);

#endif
