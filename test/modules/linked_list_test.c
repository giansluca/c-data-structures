#include "../../src/linked_list/s_linked_list.h"
#include "../unity/unity.h"
#include <stdio.h>

void it_should_insert_elements_at_beginning_and_at_end() {
    // given
    SLinkedList *list = create_linked_list();

    // when
    add_first(list, 18);
    add_first(list, 23);
    add_first(list, 500);

    Node *node_1 = get_node_at_index(list, 1);
    TEST_ASSERT_EQUAL_INT(500, node_1->data);

    Node *node_2 = get_node_at_index(list, 2);
    TEST_ASSERT_EQUAL_INT(23, node_2->data);

    Node *node_3 = get_node_at_index(list, 3);
    TEST_ASSERT_EQUAL_INT(18, node_3->data);

    add_last(list, -90);
    add_last(list, 123);
    add_last(list, 44);

    Node *node_4 = get_node_at_index(list, 4);
    TEST_ASSERT_EQUAL_INT(-90, node_4->data);

    Node *node_5 = get_node_at_index(list, 5);
    TEST_ASSERT_EQUAL_INT(123, node_5->data);

    Node *node_6 = get_node_at_index(list, 6);
    TEST_ASSERT_EQUAL_INT(44, node_6->data);
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
