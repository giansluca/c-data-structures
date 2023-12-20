#ifndef DATASTRUCTURES_S_LINKED_LIST_H
#define DATASTRUCTURES_S_LINKED_LIST_H

#include <stdbool.h>

typedef struct Node Node;
struct Node {
    int data;
    struct Node *next;
};

typedef struct {
    Node *first;
    Node *last;
    int size;
} SLinkedList;

SLinkedList *create_linked_list();
void add_first(SLinkedList *list, int item);
void add_last(SLinkedList *list, int item);
int index_of_item(SLinkedList *list, int item);
bool contains(SLinkedList *list, int item);
void remove_first(SLinkedList *list);
void remove_last(SLinkedList *list);
void remove_at_index(SLinkedList *list, int index);
int size(SLinkedList *list);
int *to_array(SLinkedList *list, int arraySize);
void reverse(SLinkedList *list);
bool is_list_empty(SLinkedList *list);
Node *get_node_at_index(SLinkedList *list, int index);
Node *get_node_at_index_from_end(SLinkedList *list, int index);
void print_linked_list(SLinkedList *list);

#endif // DATASTRUCTURES_S_LINKED_LIST_H
