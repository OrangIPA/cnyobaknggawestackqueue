#include <stdio.h>

#include "stack.h"

void test();

int main() {
    test();
}

void test() {
    stack_t stack = stack_new(sizeof(int));

    int a = 1;
    int b = 2;
    printf("push: %d\n", stack_push(&stack, &a));
    printf("push: %d\n", stack_push(&stack, &b));
    printf("pop: %d\n", *(int*)stack_pop(&stack));
    printf("pop: %d\n", *(int*)stack_pop(&stack));
}