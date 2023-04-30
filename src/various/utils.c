#include <stdbool.h>
#include <stdio.h>

void swap_int_array(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void print_int_array(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d\n", array[i]);
    }
}

int is_present(int array[], int size, int element) {
    bool is_present = false;

    for (int i = 0; i < size; i++) {
        if (array[i] == element) {
            is_present = true;
        }
    }

    return is_present;
}
