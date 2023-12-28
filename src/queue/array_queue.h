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

struct arrayQueueLib {
    ArrayQueue *(*create_queue)(int capacity);
    void (*enqueue)(ArrayQueue *queue, int value);
    int (*dequeue)(ArrayQueue *queue);
    int (*get_front)(ArrayQueue *queue);
    bool (*is_full)(ArrayQueue *queue);
    bool (*is_empty)(ArrayQueue *queue);
    void (*print)(ArrayQueue *queue);
};

extern const struct arrayQueueLib ArrayQueueLib;

#endif // DATASTRUCTURES_ARRAY_QUEUE_H
