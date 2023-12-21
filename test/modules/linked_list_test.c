#include "../../src/linked_list/s_linked_list.h"
#include "../unity/unity.h"
#include <stdio.h>

void it_should_insert_elements_at_beginning_and_at_end() {
    // given
    SLinkedList *list = create_linked_list();

    // when add first
    add_first(list, 18);
    add_first(list, 23);
    add_first(list, 500);

    Node *node_0 = get_node_at_index(list, 0);
    TEST_ASSERT_EQUAL_INT(500, node_0->data);

    Node *node_1 = get_node_at_index(list, 1);
    TEST_ASSERT_EQUAL_INT(23, node_1->data);

    Node *node_2 = get_node_at_index(list, 2);
    TEST_ASSERT_EQUAL_INT(18, node_2->data);

    Node *node_null = get_node_at_index(list, 99);
    TEST_ASSERT_NULL(node_null);

    // when add last
    add_last(list, -90);
    add_last(list, 123);
    add_last(list, 44);

    Node *node_4 = get_node_at_index(list, 3);
    TEST_ASSERT_EQUAL_INT(-90, node_4->data);

    Node *node_5 = get_node_at_index(list, 4);
    TEST_ASSERT_EQUAL_INT(123, node_5->data);

    Node *node_6 = get_node_at_index(list, 5);
    TEST_ASSERT_EQUAL_INT(44, node_6->data);

    // at this point list is: 500, 23, 18, -90. 123, 44
    // when get index of item
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

int main() {
    UNITY_BEGIN();

    RUN_TEST(it_should_insert_elements_at_beginning_and_at_end);

    return UNITY_END();
}

void setUp(void) {
    //
}

void tearDown(void) {
    //
}
