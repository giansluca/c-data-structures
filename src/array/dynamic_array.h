#include <stdbool.h>
#include <stddef.h>

#ifndef DATASTRUCTURES_DYNAMIC_ARRAY_H
#define DATASTRUCTURES_DYNAMIC_ARRAY_H

typedef struct {
    int capacity;
    int count;
    int *elements;
} DynamicArray;

struct DynamicArrayLib {
    DynamicArray *(*create_array)(int length);
    void (*add)(DynamicArray *array, int value);
    void (*add_at)(DynamicArray *array, int value, int index);
    void (*remove_at)(DynamicArray *array, int index);
    int (*index_of)(DynamicArray *array, int value);
    int (*max)(DynamicArray *array);
    void (*reverse)(DynamicArray *array);
    DynamicArray *(*find_commons)(DynamicArray *array, int array_to_compare[], size_t array_to_compare_size);
    bool (*is_present)(DynamicArray *array, int value);
    void (*print)(DynamicArray *array);
};

extern const struct DynamicArrayLib dynamicArrayLib;

#endif // DATASTRUCTURES_DYNAMIC_ARRAY_H
