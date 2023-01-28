#ifndef TASK2_H
#define TASK2_H

struct list{
    //pointer to a pointer towards the first element in the array
    char **array;
    int capacity;
    int num_values;
} l;

void *checked_malloc(size_t size);
struct list *array_list_new();
struct list *add_to_end(struct list *l, char *add_str);
void free_list(struct list *l);

#endif
