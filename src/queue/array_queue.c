#include "array_queue.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool is_array_queue_full(ArrayQueue *queue);
bool is_array_queue_empty(ArrayQueue *queue);

ArrayQueue *create_array_queue(int capacity) {
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

void enqueue_array_queue(ArrayQueue *queue, int value) {
    if (is_array_queue_full(queue)) {
        printf("Queue is full!\n");
        return;
    }

    queue->items[queue->rear] = value;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->count++;
}

int dequeue_array_queue(ArrayQueue *queue) {
    if (is_array_queue_empty(queue)) {
        printf("Queue is empty!\n");
        return -1;
    }

    int item = queue->items[queue->front];
    queue->items[queue->front] = 0;
    queue->front = (queue->front + 1) % queue->capacity;
    queue->count--;

    return item;
}

int get_array_queue_front_item(ArrayQueue *queue) {
    if (is_array_queue_empty(queue)) {
        printf("Queue is empty!\n");
        return -1;
    }

    return queue->items[queue->front];
}

bool is_array_queue_full(ArrayQueue *queue) {
    return queue->count == queue->capacity;
}

bool is_array_queue_empty(ArrayQueue *queue) { return queue->count == 0; }

void print_array_queue(ArrayQueue *queue) {
    for (int i = 0; i < queue->capacity; i++) {
        printf("%d\n", queue->items[i]);
    }
}

const struct ArrayQueueLib arrayQueueLib = {
    .create_queue = create_array_queue,
    .enqueue = enqueue_array_queue,
    .dequeue = dequeue_array_queue,
    .get_front = get_array_queue_front_item,
    .is_full = is_array_queue_full,
    .is_empty = is_array_queue_empty,
    .print = print_array_queue};
