#include "client.h"



int main(int argc, char **argv) {

  // TODO

  int sockfd = Connect("localhost", 9999);

  if(sockfd >= 0) {
    Message msg;
    msg.client_id = 1;
    msg.cmd = INFO_CMD;
    msg.arg = 0;
    sendMsg(sockfd, msg);

  } else {
    printf("Erreur : %d\n", sockfd);
  }


  return 0;
}
