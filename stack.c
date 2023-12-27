#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "stack.h"

stack_t stack_new(size_t el_size) {
    stack_t new_stack;

    const unsigned int INIT_SIZE = 1;

    new_stack.size_each = el_size;
    new_stack.stack_count = 0;
    new_stack.stack_size = INIT_SIZE;
    new_stack.data = malloc(new_stack.size_each * new_stack.stack_size);

    return new_stack;
}

int stack_push(stack_t* stack, void* data) {
    // call realloc if buffer size isn't enough
    if (stack->size_each * (stack->stack_count + 1) > stack->size_each * stack->stack_size) {
        stack->data = realloc(stack->data, stack->size_each * stack->stack_count * 2);
    }

    memcpy((char*)stack->data + (stack->stack_count * stack->size_each), data, stack->size_each);
    stack->stack_count += 1;
    return 0;
}

void* stack_pop(stack_t* stack) {
    if (stack->stack_count < 1) {
        return NULL;
    }

    void* ret = malloc(stack->size_each);
    if (ret == NULL) {
        return NULL;
    }
    memcpy(ret, (char*)stack->data + ((stack->stack_count - 1) * stack->size_each), stack->size_each);
    stack->stack_count -= 1;
    
    return ret;
}