#ifndef CLIENT_H
#define CLIENT_H

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include "../common/messages.h"


typedef struct {
  int threshold;
  int useNumber;
} Client;


#define INVALID_SERVER_ERR -2
#define CONNECTION_ERR -3

/*
  Connect(host, port) :
  Allow to connect to a server (host) via a port number (portNum).
  Returns :
    sockfd if success
    -1 in case of an error while opening the socket.
    INVALID_SERVER_ERR if |host| is not a valid address.
    CONNECTION_ERR error in connection.
*/

int Connect(const char* host, int portNum);

int sendUseRequestAndWaitResponse(int sockfd);

#endif
