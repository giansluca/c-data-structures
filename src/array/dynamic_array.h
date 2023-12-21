#include <stdbool.h>
#include <stddef.h>

#ifndef DATASTRUCTURES_DYNAMIC_ARRAY_H
#define DATASTRUCTURES_DYNAMIC_ARRAY_H

typedef struct {
    int capacity;
    int count;
    int *elements;
} DynamicArray;

DynamicArray *create_array(int initial_capacity);
void insert_element(DynamicArray *array, int element);
void insert_element_at(DynamicArray *array, int element, int index);
void remove_element_at(DynamicArray *array, int index);
int index_of_element(DynamicArray *array, int element);
int max_array_element(DynamicArray *array);
void reverse_array(DynamicArray *array);
DynamicArray *find_commons_elements(DynamicArray *array, int array_to_compare[], size_t array_to_compare_size);
bool is_element_present(DynamicArray *array, int element);
void print_dynamic_array(DynamicArray *array);

#endif // DATASTRUCTURES_DYNAMIC_ARRAY_H
