#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct node{
    struct node* next;
    pid_t pid;
    int line;
};

struct linkedlist{
    struct node* tail;
    int cap;
    int length;
};

struct linkedlist* new_linked_list(int cap);
void add(pid_t p, struct linkedlist* l, int line_num);
int remove_pid(pid_t p, struct linkedlist* l);
void free_list(struct linkedlist* l);
void print_procs(struct linkedlist* l);

#endif