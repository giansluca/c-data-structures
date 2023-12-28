#include "../../src/queue/array_queue.h"
#include "../../src/queue/priority_queue.h"
#include "../unity/unity.h"
#include <stdio.h>

// ARRAY QUEUE
void it_should_create_array_queue_add_and_remove_items() {
    // given
    ArrayQueue *queue = arrayQueueLib.create_queue(5);

    // when add items
    arrayQueueLib.enqueue(queue, 10);
    arrayQueueLib.enqueue(queue, 20);
    arrayQueueLib.enqueue(queue, -30);

    TEST_ASSERT_EQUAL_INT(5, queue->capacity);
    TEST_ASSERT_EQUAL_INT(3, queue->count);
    TEST_ASSERT_EQUAL_INT(0, queue->front);
    TEST_ASSERT_EQUAL_INT(3, queue->rear);
    TEST_ASSERT_EQUAL_INT(10, queue->items[0]);
    TEST_ASSERT_EQUAL_INT(20, queue->items[1]);
    TEST_ASSERT_EQUAL_INT(-30, queue->items[2]);

    int first_1 = queue->items[queue->front];
    int last_1 = queue->items[queue->rear - 1];
    TEST_ASSERT_EQUAL_INT(10, first_1);
    TEST_ASSERT_EQUAL_INT(-30, last_1);

    // when remove items
    int item_1 = arrayQueueLib.dequeue(queue);

    TEST_ASSERT_EQUAL_INT(10, item_1);
    TEST_ASSERT_EQUAL_INT(5, queue->capacity);
    TEST_ASSERT_EQUAL_INT(2, queue->count);
    TEST_ASSERT_EQUAL_INT(1, queue->front);
    TEST_ASSERT_EQUAL_INT(3, queue->rear);

    int first_2 = queue->items[queue->front];
    int last_2 = queue->items[queue->rear - 1];
    TEST_ASSERT_EQUAL_INT(20, first_2);
    TEST_ASSERT_EQUAL_INT(-30, last_2);

    // when add again
    arrayQueueLib.enqueue(queue, 99);
    arrayQueueLib.enqueue(queue, 200);
    arrayQueueLib.enqueue(queue, 3500);

    TEST_ASSERT_EQUAL_INT(5, queue->capacity);
    TEST_ASSERT_EQUAL_INT(5, queue->count);
    TEST_ASSERT_EQUAL_INT(1, queue->front);
    TEST_ASSERT_EQUAL_INT(1, queue->rear);

    int first_3 = queue->items[queue->front];
    int last_3 = queue->items[queue->rear - 1];
    TEST_ASSERT_EQUAL_INT(20, first_3);
    TEST_ASSERT_EQUAL_INT(3500, last_3);

    int front = arrayQueueLib.get_front(queue);
    TEST_ASSERT_EQUAL_INT(20, front);
}

// PRIORITY QUEUE
void it_should_create_priority_queue_add_and_remove_items() {
    // given
    PriorityQueue *queue = priorityQueueLib.create_queue(5);

    // when add
    priorityQueueLib.enqueue(queue, 10);
    priorityQueueLib.enqueue(queue, 20);
    priorityQueueLib.enqueue(queue, -30);
    priorityQueueLib.enqueue(queue, 100);
    priorityQueueLib.enqueue(queue, -99);

    TEST_ASSERT_EQUAL_INT(5, queue->capacity);
    TEST_ASSERT_EQUAL_INT(5, queue->count);
    TEST_ASSERT_EQUAL_INT(-99, queue->items[0]);
    TEST_ASSERT_EQUAL_INT(-30, queue->items[1]);
    TEST_ASSERT_EQUAL_INT(10, queue->items[2]);
    TEST_ASSERT_EQUAL_INT(20, queue->items[3]);
    TEST_ASSERT_EQUAL_INT(100, queue->items[4]);
    TEST_ASSERT_TRUE(priorityQueueLib.is_full(queue));

    // when remove
    int item_1 = priorityQueueLib.dequeue(queue);
    TEST_ASSERT_EQUAL_INT(5, queue->capacity);
    TEST_ASSERT_EQUAL_INT(4, queue->count);
    TEST_ASSERT_EQUAL_INT(100, item_1);
    TEST_ASSERT_FALSE(priorityQueueLib.is_empty(queue));

    int item_2 = priorityQueueLib.dequeue(queue);
    TEST_ASSERT_EQUAL_INT(5, queue->capacity);
    TEST_ASSERT_EQUAL_INT(3, queue->count);
    TEST_ASSERT_EQUAL_INT(20, item_2);
    TEST_ASSERT_FALSE(priorityQueueLib.is_empty(queue));

    int item_3 = priorityQueueLib.dequeue(queue);
    TEST_ASSERT_EQUAL_INT(5, queue->capacity);
    TEST_ASSERT_EQUAL_INT(2, queue->count);
    TEST_ASSERT_EQUAL_INT(10, item_3);
    TEST_ASSERT_FALSE(priorityQueueLib.is_empty(queue));

    int item_4 = priorityQueueLib.dequeue(queue);
    TEST_ASSERT_EQUAL_INT(5, queue->capacity);
    TEST_ASSERT_EQUAL_INT(1, queue->count);
    TEST_ASSERT_EQUAL_INT(-30, item_4);
    TEST_ASSERT_FALSE(priorityQueueLib.is_empty(queue));

    int item_5 = priorityQueueLib.dequeue(queue);
    TEST_ASSERT_EQUAL_INT(5, queue->capacity);
    TEST_ASSERT_EQUAL_INT(0, queue->count);
    TEST_ASSERT_EQUAL_INT(-99, item_5);
    TEST_ASSERT_TRUE(priorityQueueLib.is_empty(queue));
}

int main() {
    UNITY_BEGIN();

    RUN_TEST(it_should_create_array_queue_add_and_remove_items);
    RUN_TEST(it_should_create_priority_queue_add_and_remove_items);

    return UNITY_END();
}

void setUp(void) {
    //
}

void tearDown(void) {
    //
}