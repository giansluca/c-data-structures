#include <stdbool.h>

#ifndef DATASTRUCTURES_PRIORITY_QUEUE_H
#define DATASTRUCTURES_PRIORITY_QUEUE_H

typedef struct {
    int capacity;
    int count;
    int *items;
} PriorityQueue;

PriorityQueue *create_priority_queue(int capacity);
void add_p_queue(PriorityQueue *p_queue, int item);
int remove_p_queue(PriorityQueue *p_queue);
bool is_p_queue_full(PriorityQueue *p_queue);
bool is_p_queue_empty(PriorityQueue *p_queue);
void print_priority_queue(PriorityQueue *p_queue);

#endif // DATASTRUCTURES_PRIORITY_QUEUE_H
