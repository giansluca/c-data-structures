#include "../../src/array/dynamic_array.h"
#include "../unity/unity.h"
#include <stddef.h>
#include <stdio.h>

void it_should_insert_elements() {
    // given
    int initial_capacity = 3;
    DynamicArray *array = create_array(initial_capacity);

    // when insert first three values
    insert_element(array, 7);
    insert_element(array, -2);
    insert_element(array, 9);

    TEST_ASSERT_EQUAL_INT(3, array->capacity);
    TEST_ASSERT_EQUAL_INT(3, array->count);
    TEST_ASSERT_EQUAL_INT(7, array->elements[0]);
    TEST_ASSERT_EQUAL_INT(-2, array->elements[1]);
    TEST_ASSERT_EQUAL_INT(9, array->elements[2]);

    // when insert the fourth value, the array resize happens and capacity goes to 6
    insert_element(array, 12);

    TEST_ASSERT_EQUAL_INT(6, array->capacity);
    TEST_ASSERT_EQUAL_INT(4, array->count);
    TEST_ASSERT_EQUAL_INT(12, array->elements[3]);

    // when insert other values, another resize happens and capacity goes to 12
    insert_element(array, 1);
    insert_element(array, 120);
    insert_element(array, -70);

    TEST_ASSERT_EQUAL_INT(12, array->capacity);
    TEST_ASSERT_EQUAL_INT(7, array->count);
    TEST_ASSERT_EQUAL_INT(1, array->elements[4]);
    TEST_ASSERT_EQUAL_INT(120, array->elements[5]);
    TEST_ASSERT_EQUAL_INT(-70, array->elements[6]);

    // when insert other values, last capacity resize to 24
    insert_element(array, 1001);
    insert_element(array, 1002);
    insert_element(array, 1004);
    insert_element(array, 1005);
    insert_element(array, 1006);
    insert_element(array, 1007);

    TEST_ASSERT_EQUAL_INT(24, array->capacity);
    TEST_ASSERT_EQUAL_INT(13, array->count);
}

void it_should_insert_and_remove_elements_at_index() {
    // given
    int initial_capacity = 10;
    DynamicArray *array = create_array(initial_capacity);

    insert_element(array, 7);
    insert_element(array, -2);
    insert_element(array, 12);
    insert_element(array, 230);

    TEST_ASSERT_EQUAL_INT(4, array->count);
    TEST_ASSERT_EQUAL_INT(7, array->elements[0]);
    TEST_ASSERT_EQUAL_INT(-2, array->elements[1]);
    TEST_ASSERT_EQUAL_INT(12, array->elements[2]);
    TEST_ASSERT_EQUAL_INT(230, array->elements[3]);

    // when insert at index 1
    insert_element_at(array, 999, 1);

    TEST_ASSERT_EQUAL_INT(5, array->count);
    TEST_ASSERT_EQUAL_INT(7, array->elements[0]);
    TEST_ASSERT_EQUAL_INT(999, array->elements[1]);
    TEST_ASSERT_EQUAL_INT(-2, array->elements[2]);
    TEST_ASSERT_EQUAL_INT(12, array->elements[3]);
    TEST_ASSERT_EQUAL_INT(230, array->elements[4]);

    // when insert at index 0
    insert_element_at(array, 888, 0);
    TEST_ASSERT_EQUAL_INT(6, array->count);
    TEST_ASSERT_EQUAL_INT(888, array->elements[0]);
    TEST_ASSERT_EQUAL_INT(7, array->elements[1]);
    TEST_ASSERT_EQUAL_INT(999, array->elements[2]);
    TEST_ASSERT_EQUAL_INT(-2, array->elements[3]);
    TEST_ASSERT_EQUAL_INT(12, array->elements[4]);
    TEST_ASSERT_EQUAL_INT(230, array->elements[5]);

    // when insert illegal index
    insert_element_at(array, 150, -3);
    insert_element_at(array, 150, 30);
    TEST_ASSERT_EQUAL_INT(6, array->count);

    // when remove at index 0
    remove_element_at(array, 1);

    TEST_ASSERT_EQUAL_INT(5, array->count);
    TEST_ASSERT_EQUAL_INT(888, array->elements[0]);
    TEST_ASSERT_EQUAL_INT(999, array->elements[1]);
    TEST_ASSERT_EQUAL_INT(-2, array->elements[2]);
    TEST_ASSERT_EQUAL_INT(12, array->elements[3]);
    TEST_ASSERT_EQUAL_INT(230, array->elements[4]);

    // when remove illegal index
    remove_element_at(array, -1);
    remove_element_at(array, 20);
    TEST_ASSERT_EQUAL_INT(5, array->count);
}

void it_should_find_element_by_value() {
    // given
    int initial_capacity = 10;
    DynamicArray *array = create_array(initial_capacity);

    insert_element(array, 7);
    insert_element(array, -2);
    insert_element(array, 9);

    // when
    int first_element_index = index_of_element(array, 7);
    int second_element_index = index_of_element(array, -2);
    int third_element_index = index_of_element(array, 9);
    int no_element_index = index_of_element(array, 1000);

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

    insert_element(array, 7);
    insert_element(array, -2);
    insert_element(array, 9);

    // when
    int max = max_array_element(array);

    TEST_ASSERT_EQUAL_INT(9, max);
}

void it_should_reverse_the_array() {
    // given
    int initial_capacity = 10;
    DynamicArray *array = create_array(initial_capacity);

    insert_element(array, 7);
    insert_element(array, -2);
    insert_element(array, 9);
    insert_element(array, 800);

    TEST_ASSERT_EQUAL_INT(7, array->elements[0]);
    TEST_ASSERT_EQUAL_INT(-2, array->elements[1]);
    TEST_ASSERT_EQUAL_INT(9, array->elements[2]);
    TEST_ASSERT_EQUAL_INT(800, array->elements[3]);

    // when
    reverse_array(array);

    // then
    TEST_ASSERT_EQUAL_INT(800, array->elements[0]);
    TEST_ASSERT_EQUAL_INT(9, array->elements[1]);
    TEST_ASSERT_EQUAL_INT(-2, array->elements[2]);
    TEST_ASSERT_EQUAL_INT(7, array->elements[3]);
}

void it_should_find_common_elements() {
    // given
    int initial_capacity = 3;
    DynamicArray *array = create_array(initial_capacity);

    insert_element(array, 7);
    insert_element(array, -2);
    insert_element(array, 9);
    insert_element(array, 1);
    insert_element(array, 10);
    insert_element(array, 19);
    insert_element(array, 35);
    insert_element(array, 1550);
    insert_element(array, -900);
    insert_element(array, 6);

    int array_to_compare_1[] = {120, 2, 9, 32, 67, 2, 3, 4, 5, 6, 70, 1, 1, 1};
    size_t array_to_compare_size_1 = sizeof(array_to_compare_1) / sizeof(array_to_compare_1[0]);
    int expected_result_1[3] = {9, 1, 6};

    int array_to_compare_2[] = {7, -2, 9, 1, 10, 19, 35, 1551, -900, 6};
    size_t array_to_compare_size_2 = sizeof(array_to_compare_2) / sizeof(array_to_compare_2[0]);
    int expected_result_2[9] = {7, -2, 9, 1, 10, 19, 35, -900, 6};

    int array_to_compare_3[] = {999};
    size_t array_to_compare_size_3 = sizeof(array_to_compare_3) / sizeof(array_to_compare_3[0]);

    // when
    DynamicArray *result_1 = find_commons_elements(array, array_to_compare_1, array_to_compare_size_1);
    DynamicArray *result_2 = find_commons_elements(array, array_to_compare_2, array_to_compare_size_2);
    DynamicArray *result_3 = find_commons_elements(array, array_to_compare_3, array_to_compare_size_3);

    // then
    TEST_ASSERT_EQUAL_INT_ARRAY(expected_result_1, result_1->elements, result_1->count);
    TEST_ASSERT_EQUAL_INT_ARRAY(expected_result_2, result_2->elements, result_2->count);
    TEST_ASSERT_EQUAL_INT(0, result_3->count);
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
