#ifndef STACK_H
#define STACK_H

#include <stdlib.h>

struct stack_t {
    void* data;
    size_t size_each;
    size_t stack_count;
    size_t stack_size;
};

typedef struct stack_t stack_t;

stack_t stack_new(size_t el_size);

int stack_push(stack_t* stack, void* data);

void* stack_pop(stack_t* stack);

#endif