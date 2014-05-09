#ifndef CLIENT_INFO_H
#define CLIENT_INFO_H


typedef struct {
  int seuil;
  int moyenneUtilisation;
  char ip[15];

} ClientInfo;

#endif
