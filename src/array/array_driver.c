#include "../various/utils.h"
#include "dynamic_array.h"
#include <stdio.h>
#include <stdlib.h>

int *find_commons_elements(DynamicArray *array, int compare_array[],
                           int compare_len, int *result_count);

/**
 * Dynamic Array
 * In arrays data are stored in a contiguous block of memory.
 * Access time complexity is constant: O(1).
 * Inserting an element at beginning, time complexity: O(n) --> because i need
 * to shift all elements. Inserting an element at end, time complexity: O(1),
 * but if array is full i need to copy all the values in the new array --> time
 * complexity: O(n). Insert Inserting an element at n position, time complexity:
 * O(n) --> because of the shift.
 */

void array_driver() {
    int length = 3;

    // create array
    DynamicArray *array = create_array(length);

    // insert
    insert_item(array, 7);
    insert_item(array, 2);
    insert_item(array, 9);
    insert_item(array, 12);
    insert_item(array, 1);
    insert_item(array, 120);
    insert_item(array, -70);
    print_dynamic_array(array);
    printf("***\n");

    // delete
    remove_at(array, 0);
    print_dynamic_array(array);
    printf("***\n");

    // search
    printf("index of searched item is: %d\n", index_of(array, 120));
    printf("***\n");

    // insert at
    insert_at(array, 400, 1);
    print_dynamic_array(array);
    printf("***\n");

    // max
    int max = max_element(array);
    printf("Max is: %d\n", max);
    printf("***\n");

    // reverse
    reverse_array(array);
    print_dynamic_array(array);
    printf("***\n");

    // find commons elements
    int compare_array[] = {120, 2, 9, 32, 67, 2, 3, 4, 5, 6, 70, 1, 1, 1};
    int compare_array_len = sizeof(compare_array) / sizeof(compare_array[0]);
    int r_count = 0;
    int *result_count = &r_count;
    int *result_common = find_commons_elements(array, compare_array,
                                               compare_array_len, result_count);
    print_int_array(result_common, *result_count);

    // free memory
    free(result_common);
    free(array);
}

/*
 * Find common elements with another array
 */
int *find_commons_elements(DynamicArray *array, int compare_array[],
                           int compare_len, int *result_count) {
    // get size for the result array and allocate space
    int result_size = array->count;
    int *result_common = malloc(result_size * sizeof(int));

    // loop over the arrays to find intersections
    for (int i = 0; i < array->count; i++) {
        int element = array->items[i];

        for (int j = 0; j < compare_len; j++) {
            // compare elements
            if (compare_array[j] == element) {
                // if value is not already present
                if (!is_present(result_common, *result_count, element)) {
                    // increase pointer count and add the value to he result
                    // array
                    result_common[*result_count] = element;

                    *result_count += 1;
                }
            }
        }
    }
    return result_common;
}
