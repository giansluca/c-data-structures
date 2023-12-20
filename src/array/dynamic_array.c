#include "dynamic_array.h"
#include "../various/utils.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

void _extend_array(DynamicArray *array);

DynamicArray *create_array(int initial_capacity) {
    // allocate space for the struct
    DynamicArray *new_array = malloc(sizeof(DynamicArray));
    new_array->capacity = initial_capacity;
    new_array->count = 0;

    // allocate space for the array
    new_array->elements = malloc(initial_capacity * sizeof(int));

    // initialize array element to 0
    for (int i = 0; i < initial_capacity; i++) {
        new_array->elements[i] = 0;
    }

    return new_array;
}

void insert_element(DynamicArray *array, int element) {
    // if array is full, extend the array.
    if (array->count == array->capacity) {
        _extend_array(array);
    }

    // insert new element
    int index = array->count;
    array->elements[index] = element;
    array->count++;
}

void insert_at(DynamicArray *array, int element, int index) {
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

    array->elements[index] = element;
    array->count++;
}

void remove_at(DynamicArray *array, int index) {
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

int index_of(DynamicArray *array, int element) {
    for (int i = 0; i < array->count; i++) {
        if (array->elements[i] == element) {
            return i;
        }
    }

    return -1;
}

int max_element(DynamicArray *array) {
    int max = array->elements[0];

    for (int i = 0; i < array->count; i++) {
        if (array->elements[i] > max) {
            max = array->elements[i];
        }
    }

    return max;
}

void reverse_array(DynamicArray *array) {
    int start = 0;
    int end = array->count - 1;

    while (start < end) {
        // swap start with end
        swap_int_values(&array->elements[start], &array->elements[end]);
        start++;
        end--;
    }
}

DynamicArray *find_commons_elements(DynamicArray *array, int array_to_compare[], size_t array_to_compare_size) {
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
                if (is_element_present(result, element))
                    continue;

                insert_element(result, element);
            }
        }
    }
    return result;
}

bool is_element_present(DynamicArray *array, int element) {
    bool is_present = false;

    for (int i = 0; i < array->count; i++) {
        if (array->elements[i] == element) {
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
