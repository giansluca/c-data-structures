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
} LinkedList;

LinkedList *create_linked_list();
void add_item_first(LinkedList *list, int item);
void add_item_last(LinkedList *list, int item);
int index_of_item(LinkedList *list, int item);
bool list_contains(LinkedList *list, int item);
void remove_item_first(LinkedList *list);
void remove_item_last(LinkedList *list);
void remove_item_at(LinkedList *list, int index);
int list_size(LinkedList *list);
int *convert_list_to_array(LinkedList *list, int arraySize);
void reverse_list(LinkedList *list);
void reverse_list_recursive(LinkedList *list, Node *head);
bool is_list_empty(LinkedList *list);
Node *get_node_at_index(LinkedList *list, int index);
Node *get_node_at_index_from_end(LinkedList *list, int index);
void print_linked_list(LinkedList *list);
void print_linked_list_recursive(Node *head);
void print_linked_list_reverse_recursive(Node *head);

#endif // DATASTRUCTURES_S_LINKED_LIST_H
