/*Q5) [10 pts] — Singly Linked Lists
Consider the following node definition for a singly linked integer list.
typedef struct Node {
    int data;
    struct Node* next;
} NODE;

Implement the function with the signature below.
void insert_after(NODE* head, int target, int value);

This function inserts a new node containing value immediately after the first occurrence of target in the linked list.
If target is not found or the list is empty, the function should leave the list unchanged.
The function must dynamically allocate memory for the new node. */

#include <stdlib.h>

void insert_after(NODE* head, int target, int value) {
    NODE* current = head;

    while (current != NULL && current->data != target) {
        current = current->next;
    }

    if (current == NULL)
        return;

    NODE* new_node = malloc(sizeof(NODE));

    if (new_node == NULL)
        return;

    new_node->data = value;
    new_node->next = current->next;
    current->next = new_node;
}