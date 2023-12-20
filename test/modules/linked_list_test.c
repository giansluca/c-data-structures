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

    add_last(list, -90);
    add_last(list, 123);
    add_last(list, 44);

    Node *node_1 = get_node_at_index_from_end(list, 1);
    // TODO
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
