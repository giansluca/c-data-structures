#include "../../src/array/dynamic_array.h"
#include "../unity/unity.h"
#include <stddef.h>
#include <stdio.h>

void it_should_insert_elements() {
    // given
    int initial_capacity = 3;
    DynamicArray *array = create_array(initial_capacity);

    // when insert first three values
    insert_item(array, 7);
    insert_item(array, -2);
    insert_item(array, 9);

    TEST_ASSERT_EQUAL_INT(3, array->capacity);
    TEST_ASSERT_EQUAL_INT(3, array->count);
    TEST_ASSERT_EQUAL_INT(7, array->items[0]);
    TEST_ASSERT_EQUAL_INT(-2, array->items[1]);
    TEST_ASSERT_EQUAL_INT(9, array->items[2]);

    // when insert the fourth value, the array resize happens and capacity goes to 6
    insert_item(array, 12);

    TEST_ASSERT_EQUAL_INT(6, array->capacity);
    TEST_ASSERT_EQUAL_INT(4, array->count);
    TEST_ASSERT_EQUAL_INT(12, array->items[3]);

    // when insert other values, another resize happens and capacity goes to 12
    insert_item(array, 1);
    insert_item(array, 120);
    insert_item(array, -70);

    TEST_ASSERT_EQUAL_INT(12, array->capacity);
    TEST_ASSERT_EQUAL_INT(7, array->count);
    TEST_ASSERT_EQUAL_INT(1, array->items[4]);
    TEST_ASSERT_EQUAL_INT(120, array->items[5]);
    TEST_ASSERT_EQUAL_INT(-70, array->items[6]);

    // when insert other values, last capacity resize to 24
    insert_item(array, 1001);
    insert_item(array, 1002);
    insert_item(array, 1004);
    insert_item(array, 1005);
    insert_item(array, 1006);
    insert_item(array, 1007);

    TEST_ASSERT_EQUAL_INT(24, array->capacity);
    TEST_ASSERT_EQUAL_INT(13, array->count);
}

void it_should_insert_and_remove_elements_at_index() {
    // given
    int initial_capacity = 10;
    DynamicArray *array = create_array(initial_capacity);

    insert_item(array, 7);
    insert_item(array, -2);
    insert_item(array, 12);
    insert_item(array, 230);

    TEST_ASSERT_EQUAL_INT(4, array->count);
    TEST_ASSERT_EQUAL_INT(7, array->items[0]);
    TEST_ASSERT_EQUAL_INT(-2, array->items[1]);
    TEST_ASSERT_EQUAL_INT(12, array->items[2]);
    TEST_ASSERT_EQUAL_INT(230, array->items[3]);

    // when insert at index 1
    insert_at(array, 999, 1);

    TEST_ASSERT_EQUAL_INT(5, array->count);
    TEST_ASSERT_EQUAL_INT(7, array->items[0]);
    TEST_ASSERT_EQUAL_INT(999, array->items[1]);
    TEST_ASSERT_EQUAL_INT(-2, array->items[2]);
    TEST_ASSERT_EQUAL_INT(12, array->items[3]);
    TEST_ASSERT_EQUAL_INT(230, array->items[4]);

    // when insert at index 0
    insert_at(array, 888, 0);
    TEST_ASSERT_EQUAL_INT(6, array->count);
    TEST_ASSERT_EQUAL_INT(888, array->items[0]);
    TEST_ASSERT_EQUAL_INT(7, array->items[1]);
    TEST_ASSERT_EQUAL_INT(999, array->items[2]);
    TEST_ASSERT_EQUAL_INT(-2, array->items[3]);
    TEST_ASSERT_EQUAL_INT(12, array->items[4]);
    TEST_ASSERT_EQUAL_INT(230, array->items[5]);

    // when insert illegal index
    insert_at(array, 150, -3);
    insert_at(array, 150, 30);
    TEST_ASSERT_EQUAL_INT(6, array->count);

    // when remove at index 0
    remove_at(array, 1);

    TEST_ASSERT_EQUAL_INT(5, array->count);
    TEST_ASSERT_EQUAL_INT(888, array->items[0]);
    TEST_ASSERT_EQUAL_INT(999, array->items[1]);
    TEST_ASSERT_EQUAL_INT(-2, array->items[2]);
    TEST_ASSERT_EQUAL_INT(12, array->items[3]);
    TEST_ASSERT_EQUAL_INT(230, array->items[4]);

    // when remove illegal index
    remove_at(array, -1);
    remove_at(array, 20);
    TEST_ASSERT_EQUAL_INT(5, array->count);
}

void it_should_find_element_by_value() {
    // given
    int initial_capacity = 10;
    DynamicArray *array = create_array(initial_capacity);

    insert_item(array, 7);
    insert_item(array, -2);
    insert_item(array, 9);

    // when
    int first_element_index = index_of(array, 7);
    int second_element_index = index_of(array, -2);
    int third_element_index = index_of(array, 9);
    int no_element_index = index_of(array, 1000);

    // then
    TEST_ASSERT_EQUAL_INT(0, first_element_index);
    TEST_ASSERT_EQUAL_INT(1, second_element_index);
    TEST_ASSERT_EQUAL_INT(2, third_element_index);
    TEST_ASSERT_EQUAL_INT(-1, no_element_index);
}

void it_should_find_the_max_element() {
    // given
    int initial_capacity = 10;
    DynamicArray *array = create_array(initial_capacity);

    insert_item(array, 7);
    insert_item(array, -2);
    insert_item(array, 9);

    // when
    int max = max_element(array);

    TEST_ASSERT_EQUAL_INT(9, max);
}

void it_should_reverse_the_array() {
    // given
    int initial_capacity = 10;
    DynamicArray *array = create_array(initial_capacity);

    insert_item(array, 7);
    insert_item(array, -2);
    insert_item(array, 9);
    insert_item(array, 800);

    TEST_ASSERT_EQUAL_INT(7, array->items[0]);
    TEST_ASSERT_EQUAL_INT(-2, array->items[1]);
    TEST_ASSERT_EQUAL_INT(9, array->items[2]);
    TEST_ASSERT_EQUAL_INT(800, array->items[3]);

    // when
    reverse_array(array);

    // then
    TEST_ASSERT_EQUAL_INT(800, array->items[0]);
    TEST_ASSERT_EQUAL_INT(9, array->items[1]);
    TEST_ASSERT_EQUAL_INT(-2, array->items[2]);
    TEST_ASSERT_EQUAL_INT(7, array->items[3]);
}

void it_should_find_common_elements() {
    // given
    int initial_capacity = 10;
    DynamicArray *array = create_array(initial_capacity);

    insert_item(array, 7);
    insert_item(array, -2);
    insert_item(array, 9);
    insert_item(array, 1);

    int array_to_compare[] = {120, 2, 9, 32, 67, 2, 3, 4, 5, 6, 70, 1, 1, 1};
    size_t array_to_compare_size = sizeof(array_to_compare) / sizeof(array_to_compare[0]);
    int expected_result[2] = {9, 1};

    // when
    int result_count = 0;
    int *result = find_commons_elements(array, array_to_compare, array_to_compare_size, &result_count);

    // then
    TEST_ASSERT_EQUAL_INT_ARRAY(expected_result, result, result_count);
}

int main() {
    UNITY_BEGIN();

    RUN_TEST(it_should_insert_elements);
    RUN_TEST(it_should_insert_and_remove_elements_at_index);
    RUN_TEST(it_should_find_element_by_value);
    RUN_TEST(it_should_find_the_max_element);
    RUN_TEST(it_should_reverse_the_array);
    RUN_TEST(it_should_find_common_elements);

    return UNITY_END();
}

void setUp(void) {
    //
}

void tearDown(void) {
    //
}
