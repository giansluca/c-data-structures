#include "array_stack.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

ArrayStack *create_arr_stack(int length) {
    // allocate space for the struct
    ArrayStack *ArrayStack = malloc(sizeof(ArrayStack));
    ArrayStack->capacity = length;
    ArrayStack->count = 0;

    // allocate space for the array
    ArrayStack->items = malloc(length * sizeof(int));

    // initialize array element to 0
    for (int i = 0; i < length; i++) {
        ArrayStack->items[i] = 0;
    }

    return ArrayStack;
}

void push(ArrayStack *ArrayStack, int value) {
    if (is_arr_stack_full(ArrayStack)) {
        printf("ArrayStack is full!");
        exit(-1);
    }

    ArrayStack->items[ArrayStack->count] = value;
    ArrayStack->count++;
}

int pop(ArrayStack *ArrayStack) {
    if (is_arr_stack_empty(ArrayStack)) {
        printf("ArrayStack is empty");
        exit(-1);
    }

    ArrayStack->count--;
    return ArrayStack->items[ArrayStack->count];
}

int peek(ArrayStack *ArrayStack) {
    if (is_arr_stack_empty(ArrayStack)) {
        printf("ArrayStack is empty");
        exit(-1);
    }

    return ArrayStack->items[ArrayStack->count - 1];
}

bool is_arr_stack_full(ArrayStack *ArrayStack) {
    return ArrayStack->count == ArrayStack->capacity;
}

bool is_arr_stack_empty(ArrayStack *ArrayStack) {
    return ArrayStack->count == 0;
}

void print_arr_stack(ArrayStack *ArrayStack) {
    int i;
    for (i = 0; i < ArrayStack->count; i++) {
        printf("%d\n", ArrayStack->items[i]);
    }
}
