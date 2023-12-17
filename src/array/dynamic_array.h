#include <stddef.h>

#ifndef DATASTRUCTURES_DYNAMIC_ARRAY_H
#define DATASTRUCTURES_DYNAMIC_ARRAY_H

typedef struct {
    int capacity;
    int count;
    int *items;
} DynamicArray;

DynamicArray *create_array(int initial_capacity);
void insert_item(DynamicArray *array, int item);
void insert_at(DynamicArray *array, int item, int index);
void remove_at(DynamicArray *array, int index);
int index_of(DynamicArray *array, int item);
int max_element(DynamicArray *array);
void reverse_array(DynamicArray *array);
int *find_commons_elements(DynamicArray *array, int array_to_compare[], size_t array_to_compare_size, int *result_count);
void print_dynamic_array(DynamicArray *array);

#endif // DATASTRUCTURES_DYNAMIC_ARRAY_H
