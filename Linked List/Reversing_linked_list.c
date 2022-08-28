#include<stdio.h>
#include<stdlib.h>
//---------------------------------------------------------------------------------------
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
//---------------------------------------------------------------------------------------
void reverse_itrative(){
    struct Node* temp = NULL, *prev = NULL;
    struct Node* cur = head;
    while(cur != NULL){
        temp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = temp;
    }
    head = prev;
}
//---------------------------------------------------------------------------------------
void reverse_recursive(struct Node* cur_ptr){
    if(cur_ptr->next==NULL){
        head = cur_ptr;
        return;
    }
    reverse_recursive(cur_ptr->next);
    struct Node* next_ptr =  cur_ptr->next;
    
    next_ptr->next = cur_ptr;
    cur_ptr->next = NULL;
}
//---------------------------------------------------------------------------------------
int main(){
    for (int i = 0; i < 3; i++){
        tail_insert();
    }   
    display();
    reverse_itrative(head);
    printf("\n");
    display();
    printf("\n");
    reverse_recursive(head);
    display();
    return 0;
}