#ifndef CLIENT_H
#define CLIENT_H

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include "../common/messages.h"


typedef struct {
  int id;
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

/* 
   A given Client will send a USE_REQ.
   And will wait for the server's response.
   Returns : 
    USE_OK : if the server allowed the client to start.
    USE_NO : if not.

*/
int sendUseRequestAndWaitResponse(int sockfd, const Client aClient);

/*
   A given Client will send it's number of use.
   Always returns 0;
*/
int sendInfo(int sockfd, const Client aClient);

#endif
