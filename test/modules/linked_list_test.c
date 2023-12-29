#include "../../src/linked_list/linked_list.h"
#include "../unity/unity.h"
#include <stdio.h>

void it_should_insert_items_at_beginning_and_at_end() {
    // given
    LinkedList *list = linkedListLib.create_linked_list();

    // when add first
    linkedListLib.add_front(list, 18);
    linkedListLib.add_front(list, 23);
    linkedListLib.add_front(list, 500);

    Node *node_0 = linkedListLib.get_node_at(list, 0);
    TEST_ASSERT_EQUAL_INT(500, node_0->data);

    Node *node_1 = linkedListLib.get_node_at(list, 1);
    TEST_ASSERT_EQUAL_INT(23, node_1->data);

    Node *node_2 = linkedListLib.get_node_at(list, 2);
    TEST_ASSERT_EQUAL_INT(18, node_2->data);

    Node *node_null = linkedListLib.get_node_at(list, 99);
    TEST_ASSERT_NULL(node_null);

    // when add last
    linkedListLib.add_back(list, -90);
    linkedListLib.add_back(list, 123);
    linkedListLib.add_back(list, 44);

    Node *node_4 = linkedListLib.get_node_at(list, 3);
    TEST_ASSERT_EQUAL_INT(-90, node_4->data);

    Node *node_5 = linkedListLib.get_node_at(list, 4);
    TEST_ASSERT_EQUAL_INT(123, node_5->data);

    Node *node_6 = linkedListLib.get_node_at(list, 5);
    TEST_ASSERT_EQUAL_INT(44, node_6->data);

    // at this point list is: 500, 23, 18, -90. 123, 44
    // when get index of items
    TEST_ASSERT_EQUAL_INT(6, linkedListLib.size(list));

    int index_1 = linkedListLib.index_of(list, 500);
    int index_2 = linkedListLib.index_of(list, 18);
    int index_3 = linkedListLib.index_of(list, 44);
    int index_4 = linkedListLib.index_of(list, 999);
    TEST_ASSERT_EQUAL_INT(0, index_1);
    TEST_ASSERT_EQUAL_INT(2, index_2);
    TEST_ASSERT_EQUAL_INT(5, index_3);
    TEST_ASSERT_EQUAL_INT(-1, index_4);

    Node *node_from_end_1 = linkedListLib.get_node_at_from_end(list, 2);
    Node *node_from_end_2 = linkedListLib.get_node_at_from_end(list, 0);
    Node *node_from_end_null = linkedListLib.get_node_at_from_end(list, 99);
    TEST_ASSERT_EQUAL_INT(-90, node_from_end_1->data);
    TEST_ASSERT_EQUAL_INT(44, node_from_end_2->data);
    TEST_ASSERT_NULL(node_from_end_null);
}

void it_should_remove_items_at_beginning_and_at_end() {
    // given
    LinkedList *list = linkedListLib.create_linked_list();

    linkedListLib.add_back(list, 18);
    linkedListLib.add_back(list, 23);
    linkedListLib.add_back(list, 500);
    linkedListLib.add_back(list, -99);
    linkedListLib.add_back(list, 145);

    TEST_ASSERT_TRUE(linkedListLib.contains(list, 500));

    Node *node_0 = linkedListLib.get_node_at(list, 0);
    int size = linkedListLib.size(list);
    TEST_ASSERT_EQUAL_INT(18, node_0->data);
    TEST_ASSERT_EQUAL_INT(5, size);

    // when remove first
    linkedListLib.remove_front(list);

    node_0 = linkedListLib.get_node_at(list, 0);
    size = linkedListLib.size(list);
    TEST_ASSERT_EQUAL_INT(23, node_0->data);
    TEST_ASSERT_EQUAL_INT(4, size);
    TEST_ASSERT_FALSE(linkedListLib.contains(list, 18));
    TEST_ASSERT_FALSE(linkedListLib.is_empty(list));

    // then when remove last
    linkedListLib.remove_back(list);

    node_0 = linkedListLib.get_node_at(list, 0);
    size = linkedListLib.size(list);
    TEST_ASSERT_EQUAL_INT(23, node_0->data);
    TEST_ASSERT_EQUAL_INT(3, size);
    TEST_ASSERT_FALSE(linkedListLib.contains(list, 145));
    TEST_ASSERT_FALSE(linkedListLib.is_empty(list));

    // then when remove at index
    linkedListLib.remove_at(list, 1);

    node_0 = linkedListLib.get_node_at(list, 0);
    size = linkedListLib.size(list);
    TEST_ASSERT_EQUAL_INT(23, node_0->data);
    TEST_ASSERT_EQUAL_INT(2, size);
    TEST_ASSERT_FALSE(linkedListLib.contains(list, 500));
    TEST_ASSERT_FALSE(linkedListLib.is_empty(list));

    // then delete last two items
    linkedListLib.remove_front(list);
    linkedListLib.remove_front(list);

    node_0 = linkedListLib.get_node_at(list, 0);
    size = linkedListLib.size(list);
    TEST_ASSERT_NULL(node_0);
    TEST_ASSERT_EQUAL_INT(0, size);
    TEST_ASSERT_TRUE(linkedListLib.is_empty(list));
}

void it_should_reverse_and_convert_list_to_array() {
    // given
    LinkedList *list = linkedListLib.create_linked_list();

    linkedListLib.add_back(list, 18);
    linkedListLib.add_back(list, 23);
    linkedListLib.add_back(list, 500);
    linkedListLib.add_back(list, -99);
    linkedListLib.add_back(list, 145);

    // when convert to array
    int *array_1 = linkedListLib.to_array(list);
    int expected_result_1[5] = {18, 23, 500, -99, 145};
    TEST_ASSERT_EQUAL_INT_ARRAY(expected_result_1, array_1, 5);

    // when reverse list
    linkedListLib.reverse(list);
    int *array_2 = linkedListLib.to_array(list);
    int expected_result_2[5] = {145, -99, 500, 23, 18};
    TEST_ASSERT_EQUAL_INT_ARRAY(expected_result_2, array_2, 5);

    // reverse again (recursive function)
    linkedListLib.reverse_recursive(list, list->first);
    int *array_3 = linkedListLib.to_array(list);
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
