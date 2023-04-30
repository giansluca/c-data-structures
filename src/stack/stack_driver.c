#include "../various/utils.h"
#include "array_stack.h"
#include <stdio.h>
#include <stdlib.h>

int *reverse_int_array(int array[], int size);

/**
 * Stack (using array)
 * All operations time complexity are O(1)
 */

void stack_driver() {
    int length = 5;

    // create stack
    ArrayStack *stack = create_arr_stack(length);

    // push
    push(stack, 45);
    push(stack, 34);
    push(stack, 2);
    push(stack, 65);

    // pop
    printf("%d\n", pop(stack));
    printf("***\n");
    print_arr_stack(stack);
    printf("***\n");

    // peek
    int value = peek(stack);
    printf("%d\n", value);
    printf("***\n");

    // reverse int array
    int array[] = {0, 1, 2, 3, 4, 5, 6, 7};
    int arraySize = sizeof(array) / sizeof(array[0]);
    int *revArray = reverse_int_array(array, arraySize);
    print_int_array(revArray, arraySize);
    printf("***\n");
}

int *reverse_int_array(int array[], int size) {
    // push all array element in a stack
    ArrayStack *stack = create_arr_stack(size);

    for (int i = 0; i < size; i++)
        push(stack, array[i]);

    // pop the stack to the new reversed array
    int *new_array = malloc(size * sizeof(int));

    for (int j = 0; j < size; j++)
        new_array[j] = pop(stack);

    free(stack);

    return new_array;
}
