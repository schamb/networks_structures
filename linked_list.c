#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/resource.h>
#include <sys/types.h>
#include <wait.h>
#include "linked_list.h"

struct linkedlist* new_linked_list(int cap){
    struct linkedlist* l = malloc(sizeof(struct linkedlist));
    // l->tail = NULL;
    l->cap = cap;
    l->length = 0;
    return l;
}

void add(pid_t p, struct linkedlist* l, int line_num){
    struct node* n = malloc(sizeof(struct node));
    n->pid = p;
    n->line = line_num;
    n->next = NULL;
    if(l->length == 0) l->tail = n;
    else{
        n->next = l->tail;
        l->tail = n;
    }
    l->length++;
}

int remove_pid(pid_t p, struct linkedlist* l){
    struct node* prev = l->tail;
    if(prev->pid == p){
        l->tail = prev->next;
        int line = prev->line;
        l->length--;
        free(prev);
        return line;
    }

    for(int i = 1; i < l->length; i++){
        if(prev->next->pid == p){
            struct node* temp = prev->next;
            prev->next = prev->next->next;
            int line = temp->line;
            free(temp);
            l->length--;
            return line;
        }
        prev = prev->next;
    }
    return -1;
}

void free_list(struct linkedlist* l){
    if(l->length==0){
        free(l);
        return;
    }
    struct node* curr = l->tail;

    for(int i = 0; i < l->length; i++){
        struct node* next = curr->next;
        free(curr);
        curr = next;
    }
    free(curr);
    free(l);
}

void print_procs(struct linkedlist* l){
    struct node* curr = l->tail;
    for(int i = 0; i < l->length; i++){
        printf("%d ", curr->pid);
        curr = curr->next;
    }
    printf("\n");
}