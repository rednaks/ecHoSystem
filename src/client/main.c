#include "client.h"



int main(int argc, char **argv) {

  // TODO

  int sockfd = se_connecter("localhost", 9999);

  printf("SOCK : %d\n", sockfd);


  return 0;
}
