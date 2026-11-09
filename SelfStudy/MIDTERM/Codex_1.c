/*Q1) [15 pts] — Linked Lists
Consider the following node definition for a singly linked integer list.
typedef struct Node {
    int data;
    struct Node* next;
} NODE;

Implement the function with the signature below.
void remove_duplicates(NODE** list_head);

This function removes all duplicate values from the linked list, keeping only the first occurrence of each value.

The original order of the remaining nodes must be preserved. The memory allocated for removed nodes must be freed.

You may assume that the list is not sorted. Do not use additional arrays or other data structures.

What is the Big-O time complexity of your implementation?*/

typedef struct Node {
    int data;
    struct Node* next;
} NODE;

void remove_duplicates(NODE** list_head){
    if(*list_head == NULL) return;

    NODE* current = *list_head;

    while(current != NULL){
        NODE* prev = current;
        NODE* tracker = current->next;
        while(tracker != NULL){
            if(tracker->data == current->data){
                prev->next = tracker->next;
                free(tracker);
                tracker = prev->next;
            }else{
                prev = tracker;
                tracker = tracker->next;
            }

        }  
        current = current->next;
         
}