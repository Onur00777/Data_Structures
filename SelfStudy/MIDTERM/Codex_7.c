/*Q7) [10 pts] — Stack (Linked List Implementation)
Consider the following node definition for a stack implemented using a singly linked list.
typedef struct Node {
    int data;
    struct Node* next;
} NODE;

Implement the function with the signature below.
int pop(NODE** top);
This function removes the top element from the stack and returns its data value.
If the stack is empty, the function should return -1.
The memory allocated for the removed node must be freed.*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} NODE;
int pop(NODE** top){
    if(top == NULL || *top == NULL) return -1;
    NODE* current = *top;
    int data = (*top)->data; //current->data da olur
    *top = (*top)->next;
    free(current);
    return data;
}
