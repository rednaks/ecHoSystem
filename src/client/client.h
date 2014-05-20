#ifndef CLIENT_H
#define CLIENT_H

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>


typedef struct {
  int threshold;
  int useNumber;
} Client;


#define INVALID_SERVER_ERR -2
#define CONNECTION_ERR -3
#define SEND_ERROR -4

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
   sendMsg(message, sockfd) :
   Send a message to the server using a given socket.
   Returns :
    n : The number of sent bytes.
    SEND_ERROR if error..
*/

int sendMsg(const char* message, int sockfd);


#endif
