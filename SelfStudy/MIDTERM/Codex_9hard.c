/*Q9) [20 pts] — Doubly Linked Lists & Sorting
Suppose you are given a doubly linked list containing n distinct integers in arbitrary order.

The only operation you are allowed to use for rearranging the list is move_to_front: this operation removes a selected node from its current position and moves it to the beginning of the list.
For example:
Original list:
4 <-> 8 <-> 2 <-> 6 <-> 1
move_to_front(head, 6):

6 <-> 4 <-> 8 <-> 2 <-> 1

You are given the following node definition:
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} NODE;

Assume that the following function is already implemented:
void move_to_front(NODE** head, NODE* node);

This function moves the given node to the beginning of the list by modifying the pointers. You do not need to implement it.
Q9-a) [15 pts]
Write a function in C that sorts the doubly linked list in ascending order, using only the move_to_front operation to rearrange its nodes.
void sort_list(NODE** head);*/
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} NODE;
void move_to_front(NODE** head, NODE* node);

void sort_list(NODE** head){
    NODE* boundary = *head;
    while(boundary!=NULL){
        NODE*current=boundary;
        NODE*max_node = current;
        while(current != NULL){
            if(current->data > max_node->data){
                max_node = current;
            }
            current = current->next;
        }
        move_to_front(*head, max_node);
        boundary = boundary->next;
    }
    
}
