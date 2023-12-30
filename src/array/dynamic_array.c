#include "dynamic_array.h"
#include "../various/utils.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

void add_dynamic_array(DynamicArray *array, int value);
bool dynamic_array_is_present(DynamicArray *array, int element);
void _extend_array(DynamicArray *array);

DynamicArray *create_array(int initial_capacity) {
    DynamicArray *new_array = malloc(sizeof(DynamicArray));
    new_array->capacity = initial_capacity;
    new_array->count = 0;
    new_array->elements = malloc(initial_capacity * sizeof(int));

    // initialize array element to 0
    for (int i = 0; i < initial_capacity; i++) {
        new_array->elements[i] = 0;
    }

    return new_array;
}

void add_dynamic_array(DynamicArray *array, int value) {
    // if array is full, extend the array.
    if (array->count == array->capacity) {
        _extend_array(array);
    }

    // insert new element
    int index = array->count;
    array->elements[index] = value;
    array->count++;
}

void add_dynamic_array_at(DynamicArray *array, int value, int index) {
    // validate the index
    if (index < 0 || index >= array->count) {
        printf("Illegal index: %d\n", index);
        return;
    }

    // if array is full, extend the array.
    if (array->count == array->capacity) {
        _extend_array(array);
    }

    // shift elements to create the hole.
    for (int i = array->count - 1; i >= index; i--) {
        array->elements[i + 1] = array->elements[i];
    }

    array->elements[index] = value;
    array->count++;
}

void remove_dynamic_array_at(DynamicArray *array, int index) {
    // validate the index
    if (index < 0 || index >= array->count) {
        printf("Illegal index: %d\n", index);
        return;
    }

    // shift elements to fill the hole
    for (int i = index; i < array->count - 1; i++) {
        array->elements[i] = array->elements[i + 1];
    }

    // decrement count
    array->count--;
}

int dynamic_array_index_of(DynamicArray *array, int value) {
    for (int i = 0; i < array->count; i++) {
        if (array->elements[i] == value) {
            return i;
        }
    }

    return -1;
}

int dynamic_array_max(DynamicArray *array) {
    int max = array->elements[0];

    for (int i = 0; i < array->count; i++) {
        if (array->elements[i] > max) {
            max = array->elements[i];
        }
    }

    return max;
}

void reverse_dynamic_array(DynamicArray *array) {
    int start = 0;
    int end = array->count - 1;

    while (start < end) {
        // swap start with end
        swap_int_values(&array->elements[start], &array->elements[end]);
        start++;
        end--;
    }
}

DynamicArray *dynamic_array_find_commons(DynamicArray *array, int array_to_compare[], size_t array_to_compare_size) {
    // get size for the result array and allocate space as the max result possible
    DynamicArray *result = malloc(sizeof(DynamicArray));
    result->capacity = array->capacity;
    result->count = 0;
    result->elements = malloc(array->count * sizeof(int));

    // loop over the arrays to find intersections
    for (int i = 0; i < array->count; i++) {
        int element = array->elements[i];

        for (int j = 0; j < array_to_compare_size; j++) {
            if (array_to_compare[j] == element) {
                if (dynamic_array_is_present(result, element))
                    continue;

                add_dynamic_array(result, element);
            }
        }
    }
    return result;
}

bool dynamic_array_is_present(DynamicArray *array, int value) {
    bool is_present = false;

    for (int i = 0; i < array->count; i++) {
        if (array->elements[i] == value) {
            is_present = true;
        }
    }

    return is_present;
}

void print_dynamic_array(DynamicArray *array) {
    for (int i = 0; i < array->count; i++) {
        printf("%d\n", array->elements[i]);
    }
}

/*
 * New array capacity = count + capacity (every extension will be the double)
 */
void _extend_array(DynamicArray *array) {
    // create new array with extended capacity
    int new_capacity = array->count + array->capacity;
    int *new_elements = malloc(new_capacity * sizeof(int));

    // copy elements of current elements array to new_elements array
    for (int i = 0; i < array->count; i++) {
        new_elements[i] = array->elements[i];
    }

    // set new elements array to current elements array
    free(array->elements);
    array->elements = new_elements;
    array->capacity = new_capacity;
}

const struct DynamicArrayLib dynamicArrayLib = {
    .create_array = create_array,
    .add = add_dynamic_array,
    .add_at = add_dynamic_array_at,
    .remove_at = remove_dynamic_array_at,
    .index_of = dynamic_array_index_of,
    .max = dynamic_array_max,
    .reverse = reverse_dynamic_array,
    .find_commons = dynamic_array_find_commons,
    .is_present = dynamic_array_is_present,
    .print = print_dynamic_array};
