#include "priority_queue.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int shift_items_to_insert(PriorityQueue *p_queue, int item);

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

void add_p_queue(PriorityQueue *p_queue, int item) {
    if (is_p_queue_full(p_queue)) {
        printf("Queue is full!");
        exit(-1);
    }

    int index = shift_items_to_insert(p_queue, item);
    p_queue->items[index] = item;
    p_queue->count++;
}

/*
 * Shift items to insert new item in the correct priority order
 */
int shift_items_to_insert(PriorityQueue *p_queue, int item) {
    int i;
    for (i = p_queue->count - 1; i >= 0; i--) {
        if (p_queue->items[i] > item)
            p_queue->items[i + 1] = p_queue->items[i];
        else
            break;
    }

    return i + 1;
}

int remove_p_queue(PriorityQueue *p_queue) {
    if (is_p_queue_empty(p_queue)) {
        printf("Queue is empty!");
        exit(-1);
    }

    p_queue->count--;
    int item = p_queue->items[p_queue->count];

    return item;
}

bool is_p_queue_full(PriorityQueue *p_queue) {
    return p_queue->count == p_queue->capacity;
}

bool is_p_queue_empty(PriorityQueue *p_queue) { return p_queue->count == 0; }

void print_priority_queue(PriorityQueue *p_queue) {
    for (int i = 0; i < p_queue->capacity; i++) {
        printf("%d\n", p_queue->items[i]);
    }
}
