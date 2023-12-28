#include "array_stack.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

ArrayStack *create_array_stack(int length) {
    ArrayStack *ArrayStack = malloc(sizeof(ArrayStack));
    ArrayStack->capacity = length;
    ArrayStack->count = 0;
    ArrayStack->items = malloc(length * sizeof(int));

    // initialize array element to 0
    for (int i = 0; i < length; i++) {
        ArrayStack->items[i] = 0;
    }

    return ArrayStack;
}

void push(ArrayStack *ArrayStack, int value) {
    if (is_array_stack_full(ArrayStack)) {
        printf("ArrayStack is full!");
        return;
    }

    ArrayStack->items[ArrayStack->count] = value;
    ArrayStack->count++;
}

int pop(ArrayStack *ArrayStack) {
    if (is_array_stack_empty(ArrayStack)) {
        printf("ArrayStack is empty");
        return -1;
    }

    ArrayStack->count--;
    return ArrayStack->items[ArrayStack->count];
}

int peek(ArrayStack *ArrayStack) {
    if (is_array_stack_empty(ArrayStack)) {
        printf("ArrayStack is empty");
        return -1;
    }

    return ArrayStack->items[ArrayStack->count - 1];
}

bool is_array_stack_full(ArrayStack *ArrayStack) {
    return ArrayStack->count == ArrayStack->capacity;
}

bool is_array_stack_empty(ArrayStack *ArrayStack) {
    return ArrayStack->count == 0;
}

void print_array_stack(ArrayStack *ArrayStack) {
    int i;
    for (i = 0; i < ArrayStack->count; i++) {
        printf("%d\n", ArrayStack->items[i]);
    }
}

int *reverse_int_array(int array[], int size) {
    // push all array element in a stack
    ArrayStack *stack = create_array_stack(size);

    for (int i = 0; i < size; i++)
        push(stack, array[i]);

    // pop the stack to the new reversed array
    int *reversed_array = malloc(size * sizeof(int));

    for (int j = 0; j < size; j++)
        reversed_array[j] = pop(stack);

    free(stack);

    return reversed_array;
}
