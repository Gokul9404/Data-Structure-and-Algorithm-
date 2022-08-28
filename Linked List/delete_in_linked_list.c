#include<stdio.h>
#include<stdlib.h>

struct Node{
    //  Basic Structure of the linked list containing data and next node address 
    int data;
    struct Node* next;
};

struct Node* New_Node(int daata){
    // Struct providing memory for the lined_list 'Node struct' and inserting data into the Node  
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node -> data = daata;
    node -> next = NULL;
    return node;
};

struct Node* head = NULL;

void head_insert();
void tail_insert();
void display();

void head_delete(){
    // Time-comlexcity :- 1
    struct Node* ptr;
    if(head == NULL){
        printf("\nList is empty\n");
    }
    else{
        ptr = head;
        head = ptr -> next;
        free(ptr);
        printf("\nHead of the List deleted\n");
    }
}

void last_delete(){
    // Time-complexcity:- o(n)
    struct Node *ptr, *ptr_p;
    ptr = head;
    if(ptr == NULL){
        printf("\nList is empty\n");
        
    }
    else if(ptr -> next = NULL){
        free(ptr);
        printf("\nList-deleted\n");
    }
    else{
        ptr =head;
        while (ptr->next != NULL){
            ptr_p = ptr;
            ptr = ptr->next;
        }
        ptr_p->next = NULL;
        free(ptr);
        printf("\nTail of the List deleted\n");
    }
}

int main(){
    head_insert();
    for(int i=0;i<2;i++){
        tail_insert();
    }
    display();
    head_delete();
    display();
    last_delete();
    display();
    return 0;
}

void head_insert(){
    // Time-complexcity :- 1
    int daata;
    printf("Enter the data to be inserted into the (new)head:-");
    scanf("%d",&daata);
    struct Node* ptr = New_Node(daata);
    ptr -> next = head;
    head = ptr;
}

void tail_insert(){
    // Time-complexcity :- o(n)
    int daata;
    struct Node* temp;
    printf("Enter the value to be instered into the node:-");
    scanf("%d",&daata);
    struct Node* ptr = New_Node(daata);
    if (head == NULL){
        head = ptr;
    }
    else{
        temp = head;
        while (temp -> next != NULL){
            temp = temp -> next;
        }
        temp -> next = ptr;
        ptr -> next = NULL;
    }
}

void display(){
    struct Node *ptr;
    int no = 0;
    ptr = head;
    if (ptr == NULL){
        printf("List is empty");
    }
    else{
        while (ptr != NULL){
            printf("Linked-list node[%d] data:- %d\n",no,ptr->data);
            ptr = ptr -> next;
            no++;
        }   
    }
}