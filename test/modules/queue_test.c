#include "../../src/queue/array_queue.h"
#include "../../src/queue/priority_queue.h"
#include "../unity/unity.h"
#include <stdio.h>

// ARRAY QUEUE
void it_should_create_array_queue_add_and_remove_items() {
    // given
    ArrayQueue *queue = create_array_queue(5);

    // when add items
    enqueue_item(queue, 10);
    enqueue_item(queue, 20);
    enqueue_item(queue, -30);

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
    int item_1 = dequeue_item(queue);

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
    enqueue_item(queue, 99);
    enqueue_item(queue, 200);
    enqueue_item(queue, 3500);

    TEST_ASSERT_EQUAL_INT(5, queue->capacity);
    TEST_ASSERT_EQUAL_INT(5, queue->count);
    TEST_ASSERT_EQUAL_INT(1, queue->front);
    TEST_ASSERT_EQUAL_INT(1, queue->rear);

    int first_3 = queue->items[queue->front];
    int last_3 = queue->items[queue->rear - 1];
    TEST_ASSERT_EQUAL_INT(20, first_3);
    TEST_ASSERT_EQUAL_INT(3500, last_3);

    int front = get_front_item(queue);
    TEST_ASSERT_EQUAL_INT(20, front);
}

// PRIORITY QUEUE

int main() {
    UNITY_BEGIN();

    RUN_TEST(it_should_create_array_queue_add_and_remove_items);

    return UNITY_END();
}

void setUp(void) {
    //
}

void tearDown(void) {
    //
}