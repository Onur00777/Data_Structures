/*
Bağlı liste (Linked List); verilerin bellekte yan yana değil, her birinin bir sonrakinin bellek adresini (işaretçisini) cebinde taşıyarak birbirine bağlandığı dinamik bir veri yapısıdır.
*/

/*
Düğümlerden (Node) Oluşur
Bağlı listedeki her elemana düğüm (node) denir. Standart bir düğüm iki parçadan ibarettir:

Veri (Data): Saklamak istediğin sayı, metin veya nesne.
Bağ (Next Pointer): Bir sonraki düğümün RAM'deki adresi.
*/

#include <stdio.h>

typedef struct Node{
    int data;
    struct Node* next;
} Node;

Node* add_to_linked_list(Node* head, int value);
int read_from_linked_list(Node* head, int index);
Node* remove_from_linked_list(Node* head, int index);
void destroy_linked_list(Node* head);

Node* add_to_linked_list(Node* head, int value){
    //TÜR* isim = (TÜR*)malloc(sizeof(TÜR));
    Node* new = (Node*)malloc(sizeof(Node));

    new->data = value;
    new->next = head;
    return new;
}

int read_from_linked_list(Node* head, int index){
    Node* current = head;
    int count = 0;

    while(current != 0){
        if(count == index){
            return current->data;
        }
        count++;
        current = current -> next;
    }
}

Node* remove_from_linked_list(Node* head, int index){

}

void destroy_linked_list(Node* head){
    Node* current = head;
    while(current != NULL){
        Node* temp = current->next;
        free(current);
        current = temp;
    }
}


int main(){

    return 0;
}

