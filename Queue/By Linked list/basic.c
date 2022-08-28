/*
----Queue----
    -> Data structure that is based on First-In First-Out (FIFO)
    -> Can be implimented by array, linked list
*/
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
    node->data = daata;    node->next = NULL;
    return node;
};

int main(){

    return 0;
}