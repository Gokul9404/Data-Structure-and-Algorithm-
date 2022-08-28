#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* New_Node(int daata){
    // Struct providing memory for the lined_list 'Node struct' and inserting data into the Node  
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = daata;
    node->next = NULL;
    return node;
};

struct Node* head = NULL;

void head_insert(){
    // Time-complexcity :- 1
    int daata;
    printf("Enter the data to be inserted into the (new)head");
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

struct Node* Combine(struct Node *head1, struct Node *head2){
    if (head1 == NULL && head2 == NULL){ return NULL; }
    if (head1 == NULL){ return head2; }
    if (head2 == NULL){ return head1; }

    struct Node* nextl1, *nextl2;
    nextl1 = head1->next;
    nextl2 = head2->next;
    
    head1->next = head2;

    head2->next = Combine(nextl1,nextl2); 

    return head1;
}

int main(){
    head_insert();
    for (int i = 0; i < 5; i++){
        tail_insert();
    }
    display();
    int value;
    printf("Enter value to find in linked-list:-");
    scanf("%d",&value);
    int z = is_in_list(value);
    printf("%d",z);
    return 0;
}