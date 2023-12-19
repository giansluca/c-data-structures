#include <stdbool.h>
#include <stdio.h>

void swap_int_values(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void print_int_array(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d\n", array[i]);
    }
}
