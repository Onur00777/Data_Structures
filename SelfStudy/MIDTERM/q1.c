/*Q1) [15 pts] Consider the following node definition for a single linked char list. 
 
typedef struct Node{ 
    char label; 
    struct Node* next; 
} NODE; 
 
Implement the add_to_list function with the signature below.  
 
void add_to_list(NODE** list_head, char data); 
 
This function adds a character at the end of the list. If the list is already empty (list_head pointer 
points to a NULL value), list head pointer pointed by the list_head parameter should be 
initalized. */

void add_to_list(NODE** list_head, char data){
    NODE* new_node = (NODE*)malloc(sizeof(NODE));
    new_node->label = data;
    new_node->next = NULL;

    if(*list_head==NULL){
        *list_head = new_node;
    }else{
        NODE* currnt = *list_head;
        while(currnt->next != NULL){
            currnt = currnt->next;
        }
        currnt->next = new_node;
    }

}