#include "client.h"



int main(int argc, char **argv) {

  // TODO

  int sockfd = Connect("localhost", 9999);

  if(sockfd >= 0) {

    if(sendMsg("Hello ! ", sockfd) == SEND_ERROR) {

      printf("Erreur Lors de l'envoie\n");
    }
  } else {
    printf("Erreur : %d\n", sockfd);
  }


  return 0;
}
