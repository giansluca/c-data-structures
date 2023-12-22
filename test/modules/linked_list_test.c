#include "../../src/linked_list/linked_list.h"
#include "../unity/unity.h"
#include <stdio.h>

void it_should_insert_items_at_beginning_and_at_end() {
    // given
    LinkedList *list = create_linked_list();

    // when add first
    add_item_first(list, 18);
    add_item_first(list, 23);
    add_item_first(list, 500);

    Node *node_0 = get_node_at_index(list, 0);
    TEST_ASSERT_EQUAL_INT(500, node_0->data);

    Node *node_1 = get_node_at_index(list, 1);
    TEST_ASSERT_EQUAL_INT(23, node_1->data);

    Node *node_2 = get_node_at_index(list, 2);
    TEST_ASSERT_EQUAL_INT(18, node_2->data);

    Node *node_null = get_node_at_index(list, 99);
    TEST_ASSERT_NULL(node_null);

    // when add last
    add_item_last(list, -90);
    add_item_last(list, 123);
    add_item_last(list, 44);

    Node *node_4 = get_node_at_index(list, 3);
    TEST_ASSERT_EQUAL_INT(-90, node_4->data);

    Node *node_5 = get_node_at_index(list, 4);
    TEST_ASSERT_EQUAL_INT(123, node_5->data);

    Node *node_6 = get_node_at_index(list, 5);
    TEST_ASSERT_EQUAL_INT(44, node_6->data);

    // at this point list is: 500, 23, 18, -90. 123, 44
    // when get index of items
    TEST_ASSERT_EQUAL_INT(6, list_size(list));

    int index_1 = index_of_item(list, 500);
    int index_2 = index_of_item(list, 18);
    int index_3 = index_of_item(list, 44);
    int index_4 = index_of_item(list, 999);
    TEST_ASSERT_EQUAL_INT(0, index_1);
    TEST_ASSERT_EQUAL_INT(2, index_2);
    TEST_ASSERT_EQUAL_INT(5, index_3);
    TEST_ASSERT_EQUAL_INT(-1, index_4);

    Node *node_from_end_1 = get_node_at_index_from_end(list, 2);
    Node *node_from_end_2 = get_node_at_index_from_end(list, 0);
    Node *node_from_end_null = get_node_at_index_from_end(list, 99);
    TEST_ASSERT_EQUAL_INT(-90, node_from_end_1->data);
    TEST_ASSERT_EQUAL_INT(44, node_from_end_2->data);
    TEST_ASSERT_NULL(node_from_end_null);
}

void it_should_remove_items_at_beginning_and_at_end() {
    // given
    LinkedList *list = create_linked_list();

    add_item_last(list, 18);
    add_item_last(list, 23);
    add_item_last(list, 500);
    add_item_last(list, -99);
    add_item_last(list, 145);

    TEST_ASSERT_TRUE(list_contains(list, 500));

    Node *node_0 = get_node_at_index(list, 0);
    int size = list_size(list);
    TEST_ASSERT_EQUAL_INT(18, node_0->data);
    TEST_ASSERT_EQUAL_INT(5, size);

    // when remove first
    remove_item_first(list);

    node_0 = get_node_at_index(list, 0);
    size = list_size(list);
    TEST_ASSERT_EQUAL_INT(23, node_0->data);
    TEST_ASSERT_EQUAL_INT(4, size);
    TEST_ASSERT_FALSE(list_contains(list, 18));
    TEST_ASSERT_FALSE(is_list_empty(list));

    // then when remove last
    remove_item_last(list);

    node_0 = get_node_at_index(list, 0);
    size = list_size(list);
    TEST_ASSERT_EQUAL_INT(23, node_0->data);
    TEST_ASSERT_EQUAL_INT(3, size);
    TEST_ASSERT_FALSE(list_contains(list, 145));
    TEST_ASSERT_FALSE(is_list_empty(list));

    // then when remove at index
    remove_item_at(list, 1);
    print_linked_list(list);

    node_0 = get_node_at_index(list, 0);
    size = list_size(list);
    TEST_ASSERT_EQUAL_INT(23, node_0->data);
    TEST_ASSERT_EQUAL_INT(2, size);
    TEST_ASSERT_FALSE(list_contains(list, 500));
    TEST_ASSERT_FALSE(is_list_empty(list));

    // then delete last two items
    remove_item_first(list);
    remove_item_first(list);

    node_0 = get_node_at_index(list, 0);
    size = list_size(list);
    TEST_ASSERT_NULL(node_0);
    TEST_ASSERT_EQUAL_INT(0, size);
    TEST_ASSERT_TRUE(is_list_empty(list));
}

void it_should_reverse_and_convert_list_to_array() {
    // given
    LinkedList *list = create_linked_list();

    add_item_last(list, 18);
    add_item_last(list, 23);
    add_item_last(list, 500);
    add_item_last(list, -99);
    add_item_last(list, 145);

    // when convert to array
    int *array_1 = convert_list_to_array(list, list->size);
    int expected_result_1[5] = {18, 23, 500, -99, 145};
    TEST_ASSERT_EQUAL_INT_ARRAY(expected_result_1, array_1, 5);

    // when reverse list
    reverse_list(list);
    int *array_2 = convert_list_to_array(list, list->size);
    int expected_result_2[5] = {145, -99, 500, 23, 18};
    TEST_ASSERT_EQUAL_INT_ARRAY(expected_result_2, array_2, 5);

    // reverse again (recursive function)
    reverse_list_recursive(list, list->first);
    int *array_3 = convert_list_to_array(list, list->size);
    int expected_result_3[5] = {18, 23, 500, -99, 145};
    TEST_ASSERT_EQUAL_INT_ARRAY(expected_result_3, array_3, 5);
}

int main() {
    UNITY_BEGIN();

    RUN_TEST(it_should_insert_items_at_beginning_and_at_end);
    RUN_TEST(it_should_remove_items_at_beginning_and_at_end);
    RUN_TEST(it_should_reverse_and_convert_list_to_array);

    return UNITY_END();
}

void setUp(void) {
    //
}

void tearDown(void) {
    //
}
