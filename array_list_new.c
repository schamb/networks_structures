#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <stdint.h>
#include "task2.h"

// struct list{
//     //pointer to a pointer towards the first element in the array
//     char **array;
//     int capacity;
//     int num_values;
// } l;

void *checked_malloc(size_t size) {
    void *ptr;
    // number of "sizeof(char)'s" (1) in bytes
    ptr = malloc(size);
    if (ptr == NULL) {
        perror("malloc; not enough space.");
        exit(1);
    }
    return ptr;
}

struct list *array_list_new() {
    //initialize array size and reset num values 
    struct list *l = NULL;
    //l->capacity = arraysize;
    size_t arraysize = 100;
    //allocate space for list structure
    l = checked_malloc(sizeof(struct list));
    //allocate space for size of array in list structure
    l->array = checked_malloc(sizeof(char*) * arraysize);
    //capacity is set to the size of list structure
    l->capacity = arraysize;
    l->num_values = 0;
    return l;
}

struct list *add_to_end(struct list *l, char *add_str) {
    //if capacity is reached
    if (l->capacity == l->num_values) {
        //reallocate space for each element needed with new ptr
        char **new_l;
        new_l = realloc(l->array, sizeof(char*) * (l->capacity + 1));
        //reassign and update array data to newly allocated space
        l->array = new_l;
        l->capacity += 1;
        l->array[l->num_values] = add_str;
        l->num_values += 1;
    }
    else {
        //if capacity is not reached, add value to index of greatest value
        l->array[l->num_values] = add_str;
        //update num values
        l->num_values += 1;
    }
    return l;
}

void free_list(struct list *l) {
    free(l->array);
    free(l);
}

int main(void) {
    array_list_new();
    return 0;
}