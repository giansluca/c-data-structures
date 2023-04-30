#include "array_queue.h"
#include "priority_queue.h"
#include <stdio.h>

/**
 * Queue
 * All operation time complexity are O(1)
 */

void queue_driver() {
    ArrayQueue *queue = create_queue(5);
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    print_array_queue(queue);
    printf("*****\n");

    dequeue(queue);
    dequeue(queue);
    enqueue(queue, 40);
    enqueue(queue, 50);
    enqueue(queue, 60);
    enqueue(queue, 70);
    dequeue(queue);

    int value = get_front(queue);
    print_array_queue(queue);
    printf("front: %d\n", value);
    printf("*****\n");

    PriorityQueue *p_queue = create_priority_queue(5);
    add_p_queue(p_queue, 30);
    add_p_queue(p_queue, 50);
    add_p_queue(p_queue, 25);
    add_p_queue(p_queue, 35);
    print_priority_queue(p_queue);
    printf("*****\n");

    int item = remove_p_queue(p_queue);
    add_p_queue(p_queue, 10);
    print_priority_queue(p_queue);
    printf("item removed: %d\n", item);
}
