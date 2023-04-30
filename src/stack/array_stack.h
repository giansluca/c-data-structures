#ifndef DATASTRUCTURES_ARRAY_STACK_H
#define DATASTRUCTURES_ARRAY_STACK_H

#include <stdbool.h>

typedef struct {
    int capacity;
    int count;
    int *items;
} ArrayStack;

ArrayStack *create_arr_stack(int length);
void push(ArrayStack *stack, int value);
int pop(ArrayStack *stack);
int peek(ArrayStack *stack);
bool is_arr_stack_full(ArrayStack *stack);
bool is_arr_stack_empty(ArrayStack *stack);
void print_arr_stack(ArrayStack *stack);

#endif // DATASTRUCTURES_ARRAY_STACK_H
