#include "client.h"


void printHelp();

int main(int argc, char **argv) {


  if(argc < 4) {
    printHelp();
    return -1;
  }

  Client me;
  me.id = atoi(argv[1]);
  me.threshold = atoi(argv[2]);
  me.useNumber = atoi(argv[3]);

  int sockfd = Connect("localhost", 9999);

  if(sockfd >= 0) {
    startLearningProcess(sockfd, me);
  } else {
    printf("Erreur : %d\n", sockfd);
  }


  return 0;
}

void printHelp() {
  printf("Usage : ./client id threshold usenumber\n");
}
