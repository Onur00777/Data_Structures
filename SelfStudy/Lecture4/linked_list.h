#ifndef LINKEDLIST_H
#define LINKEDLIST_H
typedef struct NodeSt {
    long data;
    int priority;
    struct NodeSt* next;
} Node;

typedef struct LinkedListSt{
    Node* head;
}List, LinkedList;

void construct_llist(List* const t);
void destruct_llist(List* const t);
void add_llist(List* const t, long const data, int const priority);
Node* get_llist(List* const t, unsigned n);
unsigned len_llist(List const* const t);
void insert_llist (List* const t, long
const data, int const priority, unsigned n);
void remFront_llist (List* const t);
void remove_llist (List* const t, unsigned n);
Node* search_llist (List* const list ,
long const data, int const priority);

#endif