#ifndef DATASTRUCTURES_S_LINKED_LIST_H
#define DATASTRUCTURES_S_LINKED_LIST_H

#include <stdbool.h>
struct Node {
    int data;
    struct Node *next;
};

typedef struct Node Node;

typedef struct {
    Node *first;
    Node *last;
    int size;
} LinkedList;

struct LinkedListLib {
    LinkedList *(*create_linked_list)(void);
    void (*add_front)(LinkedList *list, int value);
    void (*add_back)(LinkedList *list, int value);
    int (*index_of)(LinkedList *list, int value);
    bool (*contains)(LinkedList *list, int value);
    void (*remove_front)(LinkedList *list);
    void (*remove_back)(LinkedList *list);
    void (*remove_at)(LinkedList *list, int index);
    int (*size)(LinkedList *list);
    int *(*to_array)(LinkedList *list);
    void (*reverse)(LinkedList *list);
    void (*reverse_recursive)(LinkedList *list, Node *head);
    bool (*is_empty)(LinkedList *list);
    Node *(*get_node_at)(LinkedList *list, int index);
    Node *(*get_node_at_from_end)(LinkedList *list, int index);
    void (*print)(LinkedList *list);
    void (*print_recursive)(Node *head);
    void (*print_reverse_recursive)(Node *head);
};

extern const struct LinkedListLib linkedListLib;

#endif // DATASTRUCTURES_S_LINKED_LIST_H
