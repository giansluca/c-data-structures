#include <stdbool.h>
#include <stdio.h>

void swap_int_values(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

bool is_int_value_present(int array[], int size, int value) {
    bool is_present = false;

    for (int i = 0; i < size; i++) {
        if (array[i] == value) {
            is_present = true;
        }
    }

    return is_present;
}

void print_int_array(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d\n", array[i]);
    }
}
