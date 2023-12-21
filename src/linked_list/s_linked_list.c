#include "s_linked_list.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

Node *_get_previous(SLinkedList *list, Node *node);

SLinkedList *create_linked_list() {
    SLinkedList *new_list = malloc(sizeof(SLinkedList));
    new_list->first = NULL;
    new_list->last = NULL;
    new_list->size = 0;

    return new_list;
}

void add_item_first(SLinkedList *list, int item) {
    Node *node = malloc(sizeof(Node));
    node->data = item;
    node->next = NULL;

    // check if the list is empty
    if (is_list_empty(list)) {
        list->first = node;
        list->last = node;
    } else {
        node->next = list->first;
        list->first = node;
    }

    list->size++;
}

void add_item_last(SLinkedList *list, int item) {
    Node *node = malloc(sizeof(Node));
    node->data = item;
    node->next = NULL;

    if (is_list_empty(list)) {
        list->first = node;
        list->last = node;
    } else {
        list->last->next = node;
        list->last = node;
    }

    list->size++;
}

int index_of_item(SLinkedList *list, int item) {
    int index = 0;
    Node *node = list->first;

    while (node != NULL) {
        if (node->data == item)
            return index;

        node = node->next;
        index++;
    }

    return -1;
}

bool list_contains(SLinkedList *list, int item) {
    return index_of_item(list, item) != -1;
}

void remove_first(SLinkedList *list) {
    if (is_list_empty(list)) {
        printf("List is already empty\n");
        return;
    }

    // if list has only one element
    if (list->first == list->last) {
        Node *temp = list->first;
        list->first = list->last = NULL;
        free(temp);
    } else {
        Node *temp = list->first;
        list->first = temp->next;
        free(temp);
    }

    list->size--;
}

void remove_last(SLinkedList *list) {
    if (is_list_empty(list)) {
        printf("List is already empty\n");
        return;
    }

    // if list has only one element
    if (list->first == list->last) {
        Node *temp = list->first;
        list->first = list->last = NULL;

        free(temp);
    } else {
        // get previous node
        Node *previous = _get_previous(list, list->last);
        previous->next = NULL;

        Node *temp = list->last;
        list->last = previous;

        free(temp);
    }

    list->size--;
}

void remove_at_index(SLinkedList *list, int index) {
    if (index >= list->size || index < 0) {
        printf("Invalid index\n");

        exit(-1);
    } else if (is_list_empty(list)) {
        printf("List is already empty\n");

        return;
    }

    // if list has only one element
    if (list->first == list->last) {
        Node *temp = list->first;
        list->first = list->last = NULL;

        free(temp);
    } else if (index == 0) {
        Node *temp = list->first;
        list->first = temp->next;

        free(temp);
    } else {
        Node *temp1 = list->first;

        int i;
        for (i = 0; i < index - 1; i++)
            temp1 = temp1->next;

        Node *temp2 = temp1->next;
        temp1->next = temp2->next;

        free(temp2);
    }
}

int list_size(SLinkedList *list) { return list->size; }

int *to_array(SLinkedList *list, int arraySize) {
    Node *current = list->first;
    int *array = malloc(arraySize * sizeof(int));

    int index = 0;
    while (current != NULL) {
        int value = current->data;
        array[index] = value;
        current = current->next;

        index++;
    }

    return array;
}

void reverse(SLinkedList *list) {
    Node *previous = list->first;
    Node *current = list->first->next;

    while (current != NULL) {
        Node *next = current->next;

        current->next = previous;
        previous = current;
        current = next;
    }

    list->last = list->first;
    list->last->next = NULL;
    list->first = previous;
}

bool is_list_empty(SLinkedList *list) {
    return list->first == NULL;
}

Node *get_node_at_index(SLinkedList *list, int index) {
    if (is_list_empty(list)) {
        printf("List is empty\n");
        return NULL;
    }

    Node *node = list->first;

    for (int i = 0; i < index; i++) {
        node = node->next;
        if (node == NULL) {
            printf("Invalid argument\n");
            return NULL;
        }
    }

    return node;
}

Node *get_node_at_index_from_end(SLinkedList *list, int index) {
    if (is_list_empty(list)) {
        printf("List is empty\n");
        return NULL;
    }

    Node *a = list->first;
    Node *b = list->first;

    for (int i = 0; i < index; i++) {
        b = b->next;
        if (b == NULL) {
            printf("Invalid argument\n");
            return NULL;
        }
    }

    while (b->next != NULL) {
        b = b->next;
        a = a->next;
    }

    return a;
}

void print_linked_list(SLinkedList *list) {
    Node *node = list->first;

    while (node != NULL) {
        printf("%d\n", node->data);
        node = node->next;
    }
}

Node *_get_previous(SLinkedList *list, Node *node) {
    Node *current = list->first;

    while (current != NULL) {
        if (current->next == node)
            return current;

        current = current->next;
    }

    return NULL;
}
