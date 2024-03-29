#include "priority_queue.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool is_priority_queue_full(PriorityQueue *p_queue);
bool is_priority_queue_empty(PriorityQueue *p_queue);
int _shift_priority_queue_items(PriorityQueue *p_queue, int value);

PriorityQueue *create_priority_queue(int capacity) {
    PriorityQueue *p_queue = malloc(sizeof(PriorityQueue));
    p_queue->capacity = capacity;
    p_queue->count = 0;
    p_queue->items = malloc(capacity * sizeof(int));

    // initialize array element to 0
    for (int i = 0; i < capacity; i++) {
        p_queue->items[i] = 0;
    }

    return p_queue;
}

void enqueue_priority_queue(PriorityQueue *p_queue, int value) {
    if (is_priority_queue_full(p_queue)) {
        printf("Queue is full!");
        return;
    }

    int index = _shift_priority_queue_items(p_queue, value);
    p_queue->items[index] = value;
    p_queue->count++;
}

int dequeue_priority_queue(PriorityQueue *p_queue) {
    if (is_priority_queue_empty(p_queue)) {
        printf("Queue is empty!");
        return -1;
    }

    p_queue->count--;
    int item = p_queue->items[p_queue->count];

    return item;
}

bool is_priority_queue_full(PriorityQueue *p_queue) {
    return p_queue->count == p_queue->capacity;
}

bool is_priority_queue_empty(PriorityQueue *p_queue) { return p_queue->count == 0; }

void print_priority_queue(PriorityQueue *p_queue) {
    for (int i = 0; i < p_queue->capacity; i++) {
        printf("%d\n", p_queue->items[i]);
    }
}

/*
 * Shift items to insert new item in the correct priority order
 */
int _shift_priority_queue_items(PriorityQueue *p_queue, int value) {
    int i;
    for (i = p_queue->count - 1; i >= 0; i--) {
        if (p_queue->items[i] > value)
            p_queue->items[i + 1] = p_queue->items[i];
        else
            break;
    }

    return i + 1;
}

const struct PriorityQueueLib priorityQueueLib = {
    .create_queue = create_priority_queue,
    .enqueue = enqueue_priority_queue,
    .dequeue = dequeue_priority_queue,
    .is_full = is_priority_queue_full,
    .is_empty = is_priority_queue_empty,
    .print = print_priority_queue};
