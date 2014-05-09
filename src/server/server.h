#ifndef SERVER_H
#define SERVER_H

#define MAX_CONNECTION              100
#define MAX_PENDING_CONNECTIONS     10

#define PORT_BIND_ERR               -2
#define LISTEN_ERR                  -3
#define RECV_ERR                    -4

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

#include "clientInfo.h"

ClientInfo ClientRang[MAX_CONNECTION];


/*
  init_serve(portNum) :
  Prépare le serveur pour l'acceptation des connexions.
  Retourne :
    sockfd : si tout va bien.
    -1 : s'il y erreur lors de l'ouverture du socket.
    PORT_BIND_ERR : si l'address est occupée.
    LISTEN_ERR : s'il n'est pas possible d'écouter
*/
int init_server(int portNum);

/*
  recevoirMsg(sockfd, message, taille):
    Le message reçu sera mis dans la variable |message|.
    n : le nombre d'octets reçus
    RECV_ERR : s'il y a eu une erreur lors de la reception.
*/
int recevoirMsg(int sockfd, char* message, int size);

#endif
