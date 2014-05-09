#ifndef CLIENT_H
#define CLIENT_H

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>


typedef struct {
  int seuil;
  int nbrUtilisations;
} Client;


#define INVALID_SERVER_ERR -2
#define CONNECTION_ERR -3

/*
  se_connect(host, port) :
  Permet de se connecter à un serveur (host) via le port (portNum).
  Retourne
    sockfd en cas de succès,
    -1 s'il y a erreur lors de l'ouverture du socket,
    INVALID_SERVER_ERR si |host| n'est pas valide.
    CONNECTION_ERR s'il y a erreur lors de l'établissement de connexion.
*/

int se_connecter(const char* host, int portNum);


#endif
