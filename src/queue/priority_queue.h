#include <stdbool.h>

#ifndef DATASTRUCTURES_PRIORITY_QUEUE_H
#define DATASTRUCTURES_PRIORITY_QUEUE_H

typedef struct {
    int capacity;
    int count;
    int *items;
} PriorityQueue;

struct PriorityQueueLib {
    PriorityQueue *(*create_queue)(int capacity);
    void (*enqueue)(PriorityQueue *queue, int value);
    int (*dequeue)(PriorityQueue *queue);
    bool (*is_full)(PriorityQueue *queue);
    bool (*is_empty)(PriorityQueue *queue);
    void (*print)(PriorityQueue *queue);
};

extern const struct PriorityQueueLib priorityQueueLib;

#endif // DATASTRUCTURES_PRIORITY_QUEUE_H
