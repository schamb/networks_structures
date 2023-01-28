#ifndef SOCKETTABLE_H
#define SOCKETTABLE_H

#include<sys/types.h>

typedef struct clientSock {
    struct clientSock *next;
    int socketNum;
    char handleName[100];
    int handleLength;
    int validFlag;
    int connectionFlag;
} clientSock;

typedef struct sockTable {
    struct clientSock *tail;
    int tableLength; //num items
} sockTable;

sockTable *newSockTable();
struct clientSock *newClientSock();
void setupSock(struct clientSock *cs, int socketNum, char *handleName);
void addClientToSockTable(sockTable *st, int socketNum, char *handleName);
void removeClientSock(sockTable *st, int socketNum);
void freeSockTable(sockTable *st);
void freeClientSock(struct clientSock *cs);
void printSocks(sockTable * st);

#endif