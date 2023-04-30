#ifndef DATASTRUCTURES_ARRAY_QUEUE_H
#define DATASTRUCTURES_ARRAY_QUEUE_H

#include <stdbool.h>

typedef struct {
    int capacity;
    int rear;
    int front;
    int count;
    int *items;
} ArrayQueue;

ArrayQueue *create_queue(int capacity);
void enqueue(ArrayQueue *queue, int value);
int dequeue(ArrayQueue *queue);
int get_front(ArrayQueue *queue);
bool is_queue_full(ArrayQueue *queue);
bool is_queue_empty(ArrayQueue *queue);
void print_array_queue(ArrayQueue *queue);

#endif // DATASTRUCTURES_ARRAY_QUEUE_H
