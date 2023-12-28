#include "../../src/stack/array_stack.h"
#include "../unity/unity.h"
#include <stdio.h>

void it_should_create_array_stack_add_and_remove_items() {
    // given
    ArrayStack *stack = ArrayStackLib.create_stack(5);

    TEST_ASSERT_EQUAL_INT(5, stack->capacity);
    TEST_ASSERT_EQUAL_INT(0, stack->count);

    // when push
    ArrayStackLib.push(stack, 45);
    ArrayStackLib.push(stack, 34);
    ArrayStackLib.push(stack, 2);
    ArrayStackLib.push(stack, 65);

    TEST_ASSERT_EQUAL_INT(5, stack->capacity);
    TEST_ASSERT_EQUAL_INT(4, stack->count);
    TEST_ASSERT_EQUAL_INT(45, *(stack->items));
    TEST_ASSERT_EQUAL_INT(34, *(stack->items + 1));
    TEST_ASSERT_EQUAL_INT(2, *(stack->items + 2));
    TEST_ASSERT_EQUAL_INT(65, *(stack->items + 3));

    // when pop
    int pop_item_1 = ArrayStackLib.pop(stack);
    TEST_ASSERT_EQUAL_INT(5, stack->capacity);
    TEST_ASSERT_EQUAL_INT(3, stack->count);
    TEST_ASSERT_EQUAL_INT(65, pop_item_1);

    // when peak
    int peak_item_1 = ArrayStackLib.peek(stack);
    TEST_ASSERT_EQUAL_INT(5, stack->capacity);
    TEST_ASSERT_EQUAL_INT(3, stack->count);
    TEST_ASSERT_EQUAL_INT(2, peak_item_1);

    // when pop again
    int pop_item_2 = ArrayStackLib.pop(stack);
    TEST_ASSERT_EQUAL_INT(5, stack->capacity);
    TEST_ASSERT_EQUAL_INT(2, stack->count);
    TEST_ASSERT_EQUAL_INT(2, pop_item_2);

    // when peak again
    int peak_item_2 = ArrayStackLib.peek(stack);
    TEST_ASSERT_EQUAL_INT(5, stack->capacity);
    TEST_ASSERT_EQUAL_INT(2, stack->count);
    TEST_ASSERT_EQUAL_INT(34, peak_item_2);
}

void it_should_reverse_an_array() {
    // given
    int array[] = {0, 1, 2, 3, 4, 5, 6, 7};
    int arraySize = sizeof(array) / sizeof(array[0]);

    // when
    int *reversed_array = ArrayStackLib.reverse_array(array, arraySize);

    // then
    TEST_ASSERT_EQUAL_INT(7, *(reversed_array));
    TEST_ASSERT_EQUAL_INT(6, *(reversed_array + 1));
    TEST_ASSERT_EQUAL_INT(5, *(reversed_array + 2));
    TEST_ASSERT_EQUAL_INT(4, *(reversed_array + 3));
    TEST_ASSERT_EQUAL_INT(3, *(reversed_array + 4));
    TEST_ASSERT_EQUAL_INT(2, *(reversed_array + 5));
    TEST_ASSERT_EQUAL_INT(1, *(reversed_array + 6));
    TEST_ASSERT_EQUAL_INT(0, *(reversed_array + 7));
}

int main() {
    UNITY_BEGIN();

    RUN_TEST(it_should_create_array_stack_add_and_remove_items);
    RUN_TEST(it_should_reverse_an_array);

    return UNITY_END();
}

void setUp(void) {
    //
}

void tearDown(void) {
    //
}