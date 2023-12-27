#include <stdlib.h>
#include <string.h>

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

int stack_push(stack_t* stack, void* data, size_t size) {
    // early return if the size doesn't match
    if (stack->size_each != size) return -1;

    // call realloc if buffer size isn't enough
    if (stack->size_each * (stack->stack_count + 1) > stack->stack_size) {
        stack->data = realloc(stack->data, stack->size_each * stack->stack_count * 2);
    }

    memcpy((char*)stack->data + (stack->stack_count * stack->stack_size), data, stack->size_each);
    return 0;
}