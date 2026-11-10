typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} NODE;
/*
This function searches for the first occurrence of value in the list and swaps that node with the node immediately following it.

The function should modify the links between nodes. Swapping the data values is not allowed.

If the value is not found or the corresponding node is the last node of the list, the list should remain unchanged.
The function must correctly handle the case where the first node is swapped.
*/
void swap_adjacent(NODE** list_head, int value){
    if(*list_head == NULL)return;

    NODE* current = *list_head;
    while(current->next != NULL){
        if(current->data == value){
            NODE* first = current;
            NODE* second = first->next;
            NODE* third = second->next;
            NODE* minus_first = first->prev;

            first->next = third;
            first->prev = second;
            second->next = first;
            second->prev = minus_first;

            if (third != NULL)
                third->prev = first;
            if (minus_first != NULL)
                minus_first->next = second;
            else
                *list_head = second;
            return;
        }
        current = current->next;
    }
}
/*
void swap_adjacent(NODE** head, int value) {

    if (head == NULL || *head == NULL)
        return;

    NODE* first = *head;

    while (first != NULL && first->data != value)
        first = first->next;

    if (first == NULL || first->next == NULL)
        return;

    NODE* second = first->next;
    NODE* before = first->prev;
    NODE* after = second->next;

    first->next = after;
    first->prev = second;

    second->next = first;
    second->prev = before;

    if (after != NULL)
        after->prev = first;

    if (before != NULL)
        before->next = second;
    else
        *head = second;
} */