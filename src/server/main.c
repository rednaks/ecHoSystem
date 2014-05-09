#include "server.h"


int main(int argc, char **argv) {

  int res = init_server(9999);
  printf("Res = %d\n", res);

  return 0;
}
