#include <stdio.h>
#include <stdlib.h>

#include "socketTable.h"

int main(int argc, char* *argv){
    struct sockTable* st  = newSockTable();
    addClientToSockTable(st, 1, "shayna");
    addClientToSockTable(st, 2, "carl");
    addClientToSockTable(st, 3, "kenzie");

    printSocks(st);
    printf("---\n");
    removeClientSock(st, 2);
    printSocks(st);


    freeSockTable(st);
    return 0;
}
