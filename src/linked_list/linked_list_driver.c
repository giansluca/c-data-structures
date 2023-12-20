#include "../various/utils.h"
#include "s_linked_list.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Node *get_kth_from_end(SLinkedList *list, int k);
void print_middle_node(SLinkedList *list);
void reverse_rec(SLinkedList *list, Node *node);
void print_linked_list_rec(Node *head);
void print_linked_list_rev_rec(Node *head);

/**
 * Linked list
 * In a linked list data are not stored in a contiguous block of memory.
 * Average case access time complexity: O(n).
 * Insert an element at beginning, time complexity constant: O(1).
 * Insert an element at end, time complexity O(1) --> if i keep the reference to
 * the end, otherwise it is O(n). Insert Inserting an element at n position,
 * time complexity: O(n) --> need to travel at that position.
 *
 * Deleting element at beginning --> O(1)
 * Deleting element at end --> O(n) --> need to traverse the list to unlink the
 * last node from the node before it. Deleting element at n position --> O(n)
 */

void list_driver() {
    SLinkedList *list = create_linked_list();

    // add
    add_first(list, 18);
    add_first(list, 23);
    add_last(list, 90);

    add_first(list, 101);
    add_last(list, 45);
    add_first(list, 600);
    add_first(list, 189);
    print_linked_list(list);
    printf("***\n");

    // index Of
    printf("%d\n", index_of_element(list, 18));
    printf("***\n");

    // is present
    bool isPresent = contains(list, 90);
    printf("%s\n", isPresent ? "true" : "false");
    printf("***\n");

    // remove first
    remove_first(list);
    print_linked_list(list);
    printf("***\n");

    // remove last
    remove_last(list);
    print_linked_list(list);
    printf("***\n");

    // size
    printf("size: %d\n", size(list));

    // to array
    int *array = to_array(list, list->size);
    printf("***\n");
    print_int_array(array, list->size);

    // reverse
    reverse(list);
    printf("***\n");
    print_linked_list(list);
    reverse_rec(list, list->first);
    printf("***\n");
    print_linked_list(list);

    // kth node
    // Node *kth = get_kth_from_end(list, 2);
    // printf("***\n");
    // printf("%d\n", kth->data);
    // printf("***\n");

    // middle node
    print_middle_node(list);
    printf("***\n");
    print_linked_list(list);
    printf("***\n");
    print_linked_list_rec(list->first);
    printf("***\n");
    print_linked_list_rev_rec(list->first);
    printf("***-***\n");

    // remove at index
    SLinkedList *list2 = create_linked_list();
    add_first(list2, 18);
    add_first(list2, 23);
    add_first(list2, 238);
    print_linked_list(list2);
    remove_at_index(list2, 1);
    printf("***-***\n");
    print_linked_list(list2);
}

// Node *get_kth_from_end(SLinkedList *list, int k) {
//     if (is_list_empty(list)) {
//         printf("List is empty\n");
//         exit(-1);
//     }

//     Node *a = list->first;
//     Node *b = list->first;

//     for (int i = 0; i < k - 1; i++) {
//         b = b->next;
//         if (b == NULL) {
//             printf("Invalid argument\n");
//             exit(-1);
//         }
//     }

//     while (b->next != NULL) {
//         b = b->next;
//         a = a->next;
//     }

//     return a;
// }

void print_middle_node(SLinkedList *list) {
    if (is_list_empty(list)) {
        printf("List is empty\n");
        exit(-1);
    }

    Node *a = list->first;
    Node *b = list->first;

    while (b != list->last && b->next != list->last) {
        b = b->next->next;
        a = a->next;
    }

    if (b == list->last)
        printf("%d\n", a->data);
    else
        printf("%d %d\n", a->data, a->next->data);
}

void reverse_rec(SLinkedList *list, Node *node) {
    if (node->next == NULL) {
        list->last = list->first;
        list->first = node;

        return;
    }

    reverse_rec(list, node->next);

    Node *temp = node->next;
    temp->next = node;
    node->next = NULL;
}

void print_linked_list_rec(Node *head) {
    if (head == NULL)
        return;

    printf("%d\n", head->data);
    print_linked_list_rec(head->next);
}

void print_linked_list_rev_rec(Node *head) {
    if (head == NULL)
        return;

    print_linked_list_rev_rec(head->next);
    printf("%d\n", head->data);
}
