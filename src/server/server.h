#ifndef SERVER_H
#define SERVER_H

#define MAX_CONNECTION              100
#define MAX_PENDING_CONNECTIONS     10

#define PORT_BIND_ERR               -2
#define LISTEN_ERR                  -3

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

#include "clientInfo.h"

ClientInfo ClientRang[MAX_CONNECTION];


int init_server(int portNum);

#endif
