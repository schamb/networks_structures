#include <stdio.h>
#include <stdlib.h>

#include "socketTable.h"

int main(int argc, char* *argv){
    struct sockTable* st  = newSockTable();
    addClientToSockTable(st, 1, "shayna");
    addClientToSockTable(st, 2, "carl");
    addClientToSockTable(st, 3, "kenzie");
    printf("List client handles\n");
    char **handles = listClientHandles(st);
    for (int i = 0; i < 3; i++) {
        printf("%s\n", handles[i]);
    }
    free(handles);

    //
    printf("handle name: %s\n", getHandleName(st, 2));

    char *invalidHandles[] = {"jon", "hane", "carl", "jake"};
    int numHandles = 4;
    char **returnStuff = checkValidHandles(st, invalidHandles, numHandles);
   // invalidHandles = checkValidHandles(st, invalidHandles);
    printf("List invalid handles\n");
    for (int i = 0; i < 3; i++) {
        printf("%s\n", returnStuff[i]);
    }
    free(returnStuff);

    // set/check valid and connect
    setValidity(st, 2, 14);
    printf("%d\n", checkValidity(st, 2));
    setConnection(st, 2, 1);
    printf("%d\n", checkConnection(st, 2));

    printSocks(st);
    printf("---\n");
    removeClientSock(st, 2);
    printSocks(st);


    freeSockTable(st);
    return 0;
}
