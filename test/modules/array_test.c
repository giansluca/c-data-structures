#include "../../src/array/dynamic_array.h"
#include "../unity/unity.h"
#include <stddef.h>
#include <stdio.h>

void it_should_insert_elements() {
    // given
    int initial_capacity = 3;
    DynamicArray *array = dynamicArrayLib.create_array(initial_capacity);

    // when insert first three values
    dynamicArrayLib.add(array, 7);
    dynamicArrayLib.add(array, -2);
    dynamicArrayLib.add(array, 9);

    TEST_ASSERT_TRUE(dynamicArrayLib.is_present(array, 7));
    TEST_ASSERT_FALSE(dynamicArrayLib.is_present(array, -7));

    TEST_ASSERT_EQUAL_INT(3, array->capacity);
    TEST_ASSERT_EQUAL_INT(3, array->count);
    TEST_ASSERT_EQUAL_INT(7, array->elements[0]);
    TEST_ASSERT_EQUAL_INT(-2, array->elements[1]);
    TEST_ASSERT_EQUAL_INT(9, array->elements[2]);

    // when insert the fourth value, the array resize happens and capacity goes to 6
    dynamicArrayLib.add(array, 12);

    TEST_ASSERT_EQUAL_INT(6, array->capacity);
    TEST_ASSERT_EQUAL_INT(4, array->count);
    TEST_ASSERT_EQUAL_INT(12, array->elements[3]);

    // when insert other values, another resize happens and capacity goes to 12
    dynamicArrayLib.add(array, 1);
    dynamicArrayLib.add(array, 120);
    dynamicArrayLib.add(array, -70);

    TEST_ASSERT_EQUAL_INT(12, array->capacity);
    TEST_ASSERT_EQUAL_INT(7, array->count);
    TEST_ASSERT_EQUAL_INT(1, array->elements[4]);
    TEST_ASSERT_EQUAL_INT(120, array->elements[5]);
    TEST_ASSERT_EQUAL_INT(-70, array->elements[6]);

    // when insert other values, last capacity resize to 24
    dynamicArrayLib.add(array, 1001);
    dynamicArrayLib.add(array, 1002);
    dynamicArrayLib.add(array, 1004);
    dynamicArrayLib.add(array, 1005);
    dynamicArrayLib.add(array, 1006);
    dynamicArrayLib.add(array, 1007);

    TEST_ASSERT_EQUAL_INT(24, array->capacity);
    TEST_ASSERT_EQUAL_INT(13, array->count);
}

void it_should_insert_and_remove_elements_at_index() {
    // given
    int initial_capacity = 10;
    DynamicArray *array = dynamicArrayLib.create_array(initial_capacity);

    dynamicArrayLib.add(array, 7);
    dynamicArrayLib.add(array, -2);
    dynamicArrayLib.add(array, 12);
    dynamicArrayLib.add(array, 230);

    TEST_ASSERT_EQUAL_INT(4, array->count);
    TEST_ASSERT_EQUAL_INT(7, array->elements[0]);
    TEST_ASSERT_EQUAL_INT(-2, array->elements[1]);
    TEST_ASSERT_EQUAL_INT(12, array->elements[2]);
    TEST_ASSERT_EQUAL_INT(230, array->elements[3]);

    // when insert at index 1
    dynamicArrayLib.add_at(array, 999, 1);

    TEST_ASSERT_EQUAL_INT(5, array->count);
    TEST_ASSERT_EQUAL_INT(7, array->elements[0]);
    TEST_ASSERT_EQUAL_INT(999, array->elements[1]);
    TEST_ASSERT_EQUAL_INT(-2, array->elements[2]);
    TEST_ASSERT_EQUAL_INT(12, array->elements[3]);
    TEST_ASSERT_EQUAL_INT(230, array->elements[4]);

    // when insert at index 0
    dynamicArrayLib.add_at(array, 888, 0);
    TEST_ASSERT_EQUAL_INT(6, array->count);
    TEST_ASSERT_EQUAL_INT(888, array->elements[0]);
    TEST_ASSERT_EQUAL_INT(7, array->elements[1]);
    TEST_ASSERT_EQUAL_INT(999, array->elements[2]);
    TEST_ASSERT_EQUAL_INT(-2, array->elements[3]);
    TEST_ASSERT_EQUAL_INT(12, array->elements[4]);
    TEST_ASSERT_EQUAL_INT(230, array->elements[5]);

    // when insert illegal index
    dynamicArrayLib.add_at(array, 150, -3);
    dynamicArrayLib.add_at(array, 150, 30);
    TEST_ASSERT_EQUAL_INT(6, array->count);

    // when remove at index 0
    dynamicArrayLib.remove_at(array, 1);

    TEST_ASSERT_EQUAL_INT(5, array->count);
    TEST_ASSERT_EQUAL_INT(888, array->elements[0]);
    TEST_ASSERT_EQUAL_INT(999, array->elements[1]);
    TEST_ASSERT_EQUAL_INT(-2, array->elements[2]);
    TEST_ASSERT_EQUAL_INT(12, array->elements[3]);
    TEST_ASSERT_EQUAL_INT(230, array->elements[4]);

    // when remove illegal index
    dynamicArrayLib.remove_at(array, -1);
    dynamicArrayLib.remove_at(array, 20);
    TEST_ASSERT_EQUAL_INT(5, array->count);
}

void it_should_find_element_by_value() {
    // given
    int initial_capacity = 10;
    DynamicArray *array = dynamicArrayLib.create_array(initial_capacity);

    dynamicArrayLib.add(array, 7);
    dynamicArrayLib.add(array, -2);
    dynamicArrayLib.add(array, 9);

    // when
    int first_element_index = dynamicArrayLib.index_of(array, 7);
    int second_element_index = dynamicArrayLib.index_of(array, -2);
    int third_element_index = dynamicArrayLib.index_of(array, 9);
    int no_element_index = dynamicArrayLib.index_of(array, 1000);

    // then
    TEST_ASSERT_EQUAL_INT(0, first_element_index);
    TEST_ASSERT_EQUAL_INT(1, second_element_index);
    TEST_ASSERT_EQUAL_INT(2, third_element_index);
    TEST_ASSERT_EQUAL_INT(-1, no_element_index);
}

void it_should_find_the_max_element() {
    // given
    int initial_capacity = 10;
    DynamicArray *array = dynamicArrayLib.create_array(initial_capacity);

    dynamicArrayLib.add(array, 7);
    dynamicArrayLib.add(array, -2);
    dynamicArrayLib.add(array, 9);

    // when
    int max = dynamicArrayLib.max(array);

    TEST_ASSERT_EQUAL_INT(9, max);
}

void it_should_reverse_the_array() {
    // given
    int initial_capacity = 10;
    DynamicArray *array = dynamicArrayLib.create_array(initial_capacity);

    dynamicArrayLib.add(array, 7);
    dynamicArrayLib.add(array, -2);
    dynamicArrayLib.add(array, 9);
    dynamicArrayLib.add(array, 800);

    TEST_ASSERT_EQUAL_INT(7, array->elements[0]);
    TEST_ASSERT_EQUAL_INT(-2, array->elements[1]);
    TEST_ASSERT_EQUAL_INT(9, array->elements[2]);
    TEST_ASSERT_EQUAL_INT(800, array->elements[3]);

    // when
    dynamicArrayLib.reverse(array);

    // then
    TEST_ASSERT_EQUAL_INT(800, array->elements[0]);
    TEST_ASSERT_EQUAL_INT(9, array->elements[1]);
    TEST_ASSERT_EQUAL_INT(-2, array->elements[2]);
    TEST_ASSERT_EQUAL_INT(7, array->elements[3]);
}

void it_should_find_common_elements() {
    // given
    int initial_capacity = 3;
    DynamicArray *array = dynamicArrayLib.create_array(initial_capacity);

    dynamicArrayLib.add(array, 7);
    dynamicArrayLib.add(array, -2);
    dynamicArrayLib.add(array, 9);
    dynamicArrayLib.add(array, 1);
    dynamicArrayLib.add(array, 10);
    dynamicArrayLib.add(array, 19);
    dynamicArrayLib.add(array, 35);
    dynamicArrayLib.add(array, 1550);
    dynamicArrayLib.add(array, -900);
    dynamicArrayLib.add(array, 6);

    int array_to_compare_1[] = {120, 2, 9, 32, 67, 2, 3, 4, 5, 6, 70, 1, 1, 1};
    size_t array_to_compare_size_1 = sizeof(array_to_compare_1) / sizeof(array_to_compare_1[0]);
    int expected_result_1[3] = {9, 1, 6};

    int array_to_compare_2[] = {7, -2, 9, 1, 10, 19, 35, 1551, -900, 6};
    size_t array_to_compare_size_2 = sizeof(array_to_compare_2) / sizeof(array_to_compare_2[0]);
    int expected_result_2[9] = {7, -2, 9, 1, 10, 19, 35, -900, 6};

    int array_to_compare_3[] = {999};
    size_t array_to_compare_size_3 = sizeof(array_to_compare_3) / sizeof(array_to_compare_3[0]);

    // when
    DynamicArray *result_1 = dynamicArrayLib.find_commons(array, array_to_compare_1, array_to_compare_size_1);
    DynamicArray *result_2 = dynamicArrayLib.find_commons(array, array_to_compare_2, array_to_compare_size_2);
    DynamicArray *result_3 = dynamicArrayLib.find_commons(array, array_to_compare_3, array_to_compare_size_3);

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
