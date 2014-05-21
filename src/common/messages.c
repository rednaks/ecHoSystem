#include "messages.h"

void parseMessage(char *aRawMessage, Message *aParsedMessage){

  /*
    TODO :
    Some imporvements : 
    * Checking the size of the frame, should be 4 bytes and return an error if
      not correct.
    * Checking each field, if it's valid or not. and return an error 
      if not valid.
  */

  // we get first the client id

  char raw_id[] = {aRawMessage[0], aRawMessage[1], '\0'};
  int client_id = atoi(raw_id);


  // Extracting the command.

  char raw_cmd[] = {aRawMessage[2], '\0'};
  int cmd = atoi(raw_cmd);


  // Extracting the argument

  char raw_arg[] = {aRawMessage[3], '\0'};
  int arg = atoi(raw_arg);

  aParsedMessage->client_id = client_id;
  aParsedMessage->cmd = cmd;
  aParsedMessage->arg = arg;
}


