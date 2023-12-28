#ifndef DATASTRUCTURES_ARRAY_STACK_H
#define DATASTRUCTURES_ARRAY_STACK_H

#include <stdbool.h>

typedef struct {
    int capacity;
    int count;
    int *items;
} ArrayStack;

ArrayStack *create_array_stack(int length);
void push(ArrayStack *stack, int value);
int pop(ArrayStack *stack);
int peek(ArrayStack *stack);
bool is_array_stack_full(ArrayStack *stack);
bool is_array_stack_empty(ArrayStack *stack);
void print_array_stack(ArrayStack *stack);
int *reverse_int_array(int array[], int size);

#endif // DATASTRUCTURES_ARRAY_STACK_H
