#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/resource.h>
#include <sys/types.h>
#include <wait.h>
#include <string.h>
//#include "linked_list.h"
#include "socketTable.h"


struct sockTable *newSockTable() {
    sockTable *st = malloc(sizeof(sockTable));
    st->tableLength = 0;
    return st;
}

clientSock *newClientSock() {
    clientSock *cs = malloc(sizeof(clientSock));
    cs->socketNum = 0;
    //cs->handleName = malloc(sizeof(char *));
    return cs;
}

void setupSock(clientSock *cs, int socketNum, char *handleName) {
    cs->socketNum = socketNum;
    cs->handleLength = strlen(handleName);
    memcpy(cs->handleName, handleName, strlen(handleName) + 1);
}

void addClientToSockTable(sockTable *st, int socketNum, char *handleName) {
    clientSock *cs = newClientSock();
    setupSock(cs, socketNum, handleName);
    
    if(st->tableLength == 0) {
        st->tail = cs;
    }
    else {
        cs->next = st->tail;
        st->tail = cs;
    }
    st->tableLength++;
}

//possibly close connection?
void removeClientSock(sockTable *st, int socketNum){
    clientSock *prev = st->tail;
    if(prev->socketNum == socketNum){
        st->tail = prev->next;
        st->tableLength--;
        freeClientSock(prev);
    }

    for(int i = 1; i < st->tableLength; i++){
        if(prev->next->socketNum == socketNum){
            clientSock *temp = prev->next;
            prev->next = prev->next->next;
            freeClientSock(temp);
            st->tableLength--;
        }
        prev = prev->next;
    }
}

void freeSockTable(sockTable *st){
    if(st->tableLength==0){
        free(st);
        return;
    }
    clientSock *curr = st->tail;
    int len = st->tableLength;

    for(int i = 0; i < len; i++){
        clientSock *next = curr->next;
        freeClientSock(curr);
        curr = next;
    }
    //freeClientSock(curr);
    free(st);
}

void freeClientSock(clientSock *cs) {
    //free(cs->handleName);
    free(cs);
}

void printSocks(sockTable * st){
    clientSock *curr = st->tail;
    int len = st->tableLength;

    for(int i = 0; i < len; i++){
        clientSock *next = curr->next;
        printf("%d: Header name: %s, header length: %d\n",curr->socketNum, curr->handleName, curr->handleLength);
        curr = next;
    }
}