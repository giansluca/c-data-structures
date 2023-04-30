#include "dynamic_array.h"
#include "../various/utils.h"
#include <stdio.h>
#include <stdlib.h>

void extend_items_array(DynamicArray *array);

DynamicArray *create_array(int length) {
    // allocate space for the struct
    DynamicArray *new_array = malloc(sizeof(DynamicArray));
    new_array->capacity = length;
    new_array->count = 0;

    // allocate space for the array
    new_array->items = malloc(length * sizeof(int));

    // initialize array element to 0
    for (int i = 0; i < length; i++) {
        new_array->items[i] = 0;
    }

    return new_array;
}

void insert_item(DynamicArray *array, int item) {
    // if array is full, extend the array.
    if (array->count == array->capacity) {
        extend_items_array(array);
    }

    // insert new element
    int count = array->count;
    array->items[count] = item;
    array->count++;
}

void insert_at(DynamicArray *array, int item, int index) {
    // validate the index
    if (index < 0 || index >= array->count) {
        printf("Illegal index\n");
        exit(-1);
    }

    // if array is full, extend the array.
    if (array->count == array->capacity) {
        extend_items_array(array);
    }

    // shift elements to create the hole.
    for (int i = array->count - 1; i >= index; i--) {
        array->items[i + 1] = array->items[i];
    }

    array->items[index] = item;
    array->count++;
}

void remove_at(DynamicArray *array, int index) {
    // validate the index
    if (index < 0 || index >= array->count) {
        printf("Illegal index\n");
        exit(-1);
    }

    // shift elements to fill the hole
    for (int i = index; i < array->count - 1; i++) {
        array->items[i] = array->items[i + 1];
    }

    // decrement count
    array->count--;
}

int index_of(DynamicArray *array, int item) {
    for (int i = 0; i < array->count; i++) {
        if (array->items[i] == item) {
            return i;
        }
    }

    return -1;
}

int max_element(DynamicArray *array) {
    int max = array->items[0];

    for (int i = 0; i < array->count; i++) {
        if (array->items[i] > max) {
            max = array->items[i];
        }
    }

    return max;
}

void reverse_array(DynamicArray *array) {
    int start = 0;
    int end = array->count - 1;

    while (start < end) {
        // swap start with end
        swap_int_array(&array->items[start], &array->items[end]);
        start++;
        end--;
    }
}

/*
 * Extend the items array capacity
 * new array capacity = count + capacity (every extension will be the double)
 */
void extend_items_array(DynamicArray *array) {
    // create new array with extended capacity (new array capacity the double of
    // the previous = count + capacity)
    int new_capacity = array->count + array->capacity;
    int *new_items = malloc(new_capacity * sizeof(int));

    // copy elements of current items array to new_items array
    for (int i = 0; i < array->count; i++) {
        new_items[i] = array->items[i];
    }

    // set new items array to current items array
    free(array->items);

    array->items = new_items;
    array->capacity = new_capacity;
}

void print_dynamic_array(DynamicArray *array) {
    for (int i = 0; i < array->count; i++) {
        printf("%d\n", array->items[i]);
    }
}
