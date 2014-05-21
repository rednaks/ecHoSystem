#ifndef MESSAGES_H
#define MESSAGES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
   This file contains the definition of the messages between the client
   and the server, they should be known by each parts.
   It's a common file.
*/

/*

   The message format:
   +---------+---+----+
   |CLIENT_ID|CMD|ARG |
   +---------+---+----+

   At the moment, each filed will be encoded into one byte,
   except the CLIENT_ID which is on two bytes.
   If we want to expend the system, we can use 
   a seperator to identify the fields, a ":" for example.

*/

typedef struct {
  int client_id;
  int cmd;
  int arg;
} Message;

/*
   The INFO_CMD is sent when a client will provide informations to the server,
   such as the number of use in a period.
   The only allowed argument is the number if use for the client.
   If the server sends an INFO_CMD to a client, this mean that he's requesting
   the number of use from the client.

*/
#define INFO_CMD      0x1



/*
   The USE_CMD is sent by the client if he wants to start working.
   There are the different args that USE can have.
*/
#define USE_CMD       0x2

#define USE_REQ       0x1
#define USE_OK        0x2
#define USE_NO        0x3




/*
   This function will parse a raw message (received from a client)
   As a string, then it will be stored in a Message struct.
*/

void parseMessage(char *aRawMessage, Message *aParesedMessage);

/*
   composeMessage will compose and return a message frame (as a string )
   that will be send over network.

*/

char* composeMessage(const Message aMessage);


#endif
