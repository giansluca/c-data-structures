#include "array_queue.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool is_full(ArrayQueue *queue);
bool is_empty(ArrayQueue *queue);

ArrayQueue *create_queue(int capacity) {
    ArrayQueue *new_queue = malloc(sizeof(ArrayQueue));
    new_queue->capacity = capacity;
    new_queue->count = 0;
    new_queue->rear = 0;
    new_queue->front = 0;
    new_queue->items = malloc(capacity * sizeof(int));

    // initialize array element to 0
    for (int i = 0; i < capacity; i++) {
        new_queue->items[i] = 0;
    }

    return new_queue;
}

void enqueue(ArrayQueue *queue, int value) {
    if (is_full(queue)) {
        printf("Queue is full!\n");
        return;
    }

    queue->items[queue->rear] = value;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->count++;
}

int dequeue(ArrayQueue *queue) {
    if (is_empty(queue)) {
        printf("Queue is empty!\n");
        return -1;
    }

    int item = queue->items[queue->front];
    queue->items[queue->front] = 0;
    queue->front = (queue->front + 1) % queue->capacity;
    queue->count--;

    return item;
}

int get_front(ArrayQueue *queue) {
    if (is_empty(queue)) {
        printf("Queue is empty!\n");
        return -1;
    }

    return queue->items[queue->front];
}

bool is_full(ArrayQueue *queue) {
    return queue->count == queue->capacity;
}

bool is_empty(ArrayQueue *queue) { return queue->count == 0; }

void print(ArrayQueue *queue) {
    for (int i = 0; i < queue->capacity; i++) {
        printf("%d\n", queue->items[i]);
    }
}

const struct arrayQueueLib ArrayQueueLib = {
    .create_queue = create_queue,
    .enqueue = enqueue,
    .dequeue = dequeue,
    .get_front = get_front,
    .is_full = is_full,
    .is_empty = is_empty,
    .print = print};
