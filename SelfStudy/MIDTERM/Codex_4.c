/*Q4) [10 pts] — Singly Linked Lists
Consider the following node definition for a singly linked integer list.
typedef struct Node {
    int data;
    struct Node* next;
} NODE;


Implement the function with the signature below.
void delete_first(NODE** list_head, int value);


This function searches for the first occurrence of value in the linked list and deletes that node.

The function should modify the links between nodes and free the memory allocated for the deleted node.

If the value is not found or the list is empty, the list should remain unchanged.

The function must correctly handle the case where the first node is deleted.*/
#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;
} NODE;

void delete_first(NODE** list_head, int value) {

    if (list_head == NULL || *list_head == NULL)
        return;

    // İlk düğümü kontrol et
    if ((*list_head)->data == value) {
        NODE* temp = *list_head;
        *list_head = temp->next;
        free(temp);
        return;
    }

    NODE* before = *list_head;
    NODE* current = before->next;

    while (current != NULL) {
        NODE* after = current->next;

        if (current->data == value) {
            before->next = after;
            free(current);
            return;
        }

        before = current;
        current = after;
    }
}

void append(NODE** head, int data) {
    NODE* new_node = malloc(sizeof(NODE));
    if (new_node == NULL) exit(1);

    new_node->data = data;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    NODE* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = new_node;
}

// Listeyi yazdırma
void print_list(NODE* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Kalan belleği temizleme
void free_list(NODE* head) {
    while (head != NULL) {
        NODE* next = head->next;
        free(head);
        head = next;
    }
}

int main(void) {
    NODE* head = NULL;

    append(&head, 10);
    append(&head, 20);
    append(&head, 30);
    append(&head, 40);
    append(&head, 20);

    printf("Original: ");
    print_list(head);

    printf("\nTest 1 - Delete middle node (30):\n");
    delete_first(&head, 30);
    print_list(head);

    printf("\nTest 2 - Delete head node (10):\n");
    delete_first(&head, 10);
    print_list(head);

    printf("\nTest 3 - Delete first occurrence of 20:\n");
    delete_first(&head, 20);
    print_list(head);

    printf("\nTest 4 - Value not found (99):\n");
    delete_first(&head, 99);
    print_list(head);

    printf("\nTest 5 - Delete last node (20):\n");
    delete_first(&head, 20);
    print_list(head);

    printf("\nTest 6 - Delete only remaining node (40):\n");
    delete_first(&head, 40);
    print_list(head);

    printf("\nTest 7 - Delete from empty list:\n");
    delete_first(&head, 10);
    print_list(head);

    free_list(head);

    return 0;
}