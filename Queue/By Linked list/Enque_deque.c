#include<stdio.h>
#include<stdlib.h>

struct Que_Node *front = NULL, *rear = NULL;

struct Que_Node{
    //  Basic Structure of the linked list containing data and next node address 
    int data;
    struct Que_Node* next;
};

struct Que_Node* New_Node(int daata){
    // Struct providing memory for the lined_list 'Node struct' and inserting data into the Node  
    struct Que_Node* node = (struct Que_Node*) malloc(sizeof(struct Que_Node));
    node->data = daata;    
    node->next = NULL;
    return node;
};


void display(){
    struct Que_Node* ptr = front;
    if (ptr == NULL){
        printf("Queue Linked-List is empty");
    }
    else{
        int no = 0;
        while (ptr != NULL){
            printf("Queue Linked-list node[%d] data:- %d\n",no,ptr->data);
            ptr = ptr->next;
            no++;
        }   
    }
}

void Enqueue(int val){
    struct Que_Node* node = New_Node(val);
    if (front == NULL){
        front = node;
        rear = node;
    }
    else{
        rear->next = node;
        rear = node;
    }
}

int Dequeue(){
    int value = -1;
    struct Que_Node* ptr;

    if (front == NULL){
        printf("Queue is Empty\n");
    }
    else{
        ptr = front;
        front = front->next;
        value = ptr->data;
        free(ptr);
    }
    return value;
}

int main(){
    Enqueue(44);
    Enqueue(45);
    Enqueue(46);
    display();
    printf("%d\n",Dequeue());
    printf("%d\n",Dequeue());
    printf("%d\n",Dequeue());
    printf("%d\n",Dequeue());
    return 0;
}