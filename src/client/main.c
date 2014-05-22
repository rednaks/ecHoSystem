#include "client.h"


void printHelp();


Client me;
int isLearning = 0;

void* learningThread(void *params) {

  isLearning = 1;
  int sockfd = *((int*)params);

  startLearningProcess(sockfd, &me);

  isLearning = 0;

}

int main(int argc, char **argv) {


  if(argc < 3) {
    printHelp();
    return -1;
  }

  me.id = atoi(argv[1]);
  me.threshold = atoi(argv[2]);
  //me.useNumber = atoi(argv[3]);

  int sockfd = Connect("localhost", 9999);

    if(sockfd >= 0) {
    pthread_t th;
    pthread_create(&th, NULL, learningThread, &sockfd);
    while(1) {
      printf("Do you want to simulate a use ?\n");
      printf("press 'y' to do so\n press 'n' to exit learn mode\n");
      char input;
      scanf(" %c", &input);
      printf("Inp %c\n",input);
      if(input == 'y' && isLearning)
      {
        me.useNumber++;
      }
    }
  } else {
    printf("Erreur : %d\n", sockfd);
  }


  return 0;
}

void printHelp() {
  printf("Usage : ./client id threshold usenumber\n");
}
