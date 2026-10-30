#include <stdio.h>
#include "linked_list.h"

void construct_llist(List* const t){
    t->head = NULL; //Liste boş
}
void destruct_llist(List* const t){

}
void add_llist(List* const t, long const data, int const priority){
    Node* p = (Node*)malloc(sizeof(Node));
    p->data = data;
    p->priority = priority;
    p->next = t->head;
    t->head = p; //listenin başı artık p
}

Node* get_llist(List* const t, unsigned n){
    Node* p = t->head;
    while(p != NULL && n-- > 0){
        p = p->next;
    }
    return p;
}
unsigned len_llist(List const* const t);
void insert_llist (List* const t, long
const data, int const priority, unsigned n);
void remFront_llist (List* const t);
void remove_llist (List* const t, unsigned n);
Node* search_llist (List* const list ,
long const data, int const priority);
