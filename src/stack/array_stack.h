#ifndef DATASTRUCTURES_ARRAY_STACK_H
#define DATASTRUCTURES_ARRAY_STACK_H

#include <stdbool.h>

typedef struct {
    int capacity;
    int count;
    int *items;
} ArrayStack;

struct arrayStackLib {
    ArrayStack *(*create_stack)(int length);
    void (*push)(ArrayStack *stack, int value);
    int (*pop)(ArrayStack *stack);
    int (*peek)(ArrayStack *stack);
    bool (*is_full)(ArrayStack *stack);
    bool (*is_empty)(ArrayStack *stack);
    int *(*reverse_array)(int array[], int length);
    void (*print)(ArrayStack *stack);
};

extern const struct arrayStackLib ArrayStackLib;

#endif // DATASTRUCTURES_ARRAY_STACK_H
