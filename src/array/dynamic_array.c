#include "dynamic_array.h"
#include "../various/utils.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

void extend_items_array(DynamicArray *array);

DynamicArray *create_array(int initial_capacity) {
    // allocate space for the struct
    DynamicArray *new_array = malloc(sizeof(DynamicArray));
    new_array->capacity = initial_capacity;
    new_array->count = 0;

    // allocate space for the array
    new_array->items = malloc(initial_capacity * sizeof(int));

    // initialize array element to 0
    for (int i = 0; i < initial_capacity; i++) {
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
    int index = array->count;
    array->items[index] = item;
    array->count++;
}

void insert_at(DynamicArray *array, int item, int index) {
    // validate the index
    if (index < 0 || index >= array->count) {
        printf("Illegal index: %d\n", index);
        return;
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
        printf("Illegal index: %d\n", index);
        return;
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
        swap_int_values(&array->items[start], &array->items[end]);
        start++;
        end--;
    }
}

/*
 * New array capacity = count + capacity (every extension will be the double)
 */
void extend_items_array(DynamicArray *array) {
    // create new array with extended capacity
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

int *find_commons_elements(DynamicArray *array, int array_to_compare[], size_t array_to_compare_size, int *result_count) {
    // get size for the result array and allocate space as the max result possible
    int result_size = array->count;
    int *result = malloc(result_size * sizeof(int));

    // loop over the arrays to find intersections
    for (int i = 0; i < array->count; i++) {
        int element = array->items[i];

        for (int j = 0; j < array_to_compare_size; j++) {
            if (array_to_compare[j] == element) {
                // if value is not already present
                if (!is_int_value_present(result, *result_count, element)) {
                    // increase pointer count and add the value to he result array
                    result[*result_count] = element;
                    *result_count += 1;
                }
            }
        }
    }
    return result;
}

void print_dynamic_array(DynamicArray *array) {
    for (int i = 0; i < array->count; i++) {
        printf("%d\n", array->items[i]);
    }
}
