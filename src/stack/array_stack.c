#include "array_stack.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool is_full(ArrayStack *ArrayStack);
bool is_empty(ArrayStack *ArrayStack);
ArrayStack *create_stack(int length);

ArrayStack *create_stack(int length) {
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
    if (is_full(ArrayStack)) {
        printf("ArrayStack is full!");
        return;
    }

    ArrayStack->items[ArrayStack->count] = value;
    ArrayStack->count++;
}

int pop(ArrayStack *ArrayStack) {
    if (is_empty(ArrayStack)) {
        printf("ArrayStack is empty");
        return -1;
    }

    ArrayStack->count--;
    return ArrayStack->items[ArrayStack->count];
}

int peek(ArrayStack *ArrayStack) {
    if (is_empty(ArrayStack)) {
        printf("ArrayStack is empty");
        return -1;
    }

    return ArrayStack->items[ArrayStack->count - 1];
}

bool is_full(ArrayStack *ArrayStack) {
    return ArrayStack->count == ArrayStack->capacity;
}

bool is_empty(ArrayStack *ArrayStack) {
    return ArrayStack->count == 0;
}

int *reverse_array(int array[], int length) {
    // push all array element in a stack
    ArrayStack *stack = create_stack(length);

    for (int i = 0; i < length; i++)
        push(stack, array[i]);

    // pop the stack to the new reversed array
    int *reversed_array = malloc(length * sizeof(int));

    for (int j = 0; j < length; j++)
        reversed_array[j] = pop(stack);

    free(stack);

    return reversed_array;
}

void print(ArrayStack *ArrayStack) {
    int i;
    for (i = 0; i < ArrayStack->count; i++) {
        printf("%d\n", ArrayStack->items[i]);
    }
}

const struct arrayStackLib ArrayStackLib = {
    .create_stack = create_stack,
    .push = push,
    .pop = pop,
    .peek = peek,
    .is_full = is_full,
    .is_empty = is_empty,
    .reverse_array = reverse_array,
    .print = print};
