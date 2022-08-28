/*
Linked List
    A non-contigous list having no fixed size, having more mutabilty then array, based on the pointer and memory allocation.
*/
/*
    Head node -> [data, next_node_address]
                                 |
                                \/
                            next_node -> [data, next_node_address]
                                                     |
                                                    \/
                                                next_node -> [data, next_node_address]
                                                ......... tile the last node, where next_node_address => NULL
*/

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
};


int main()
{
    struct Node* head = New_Node(23);
    printf("%d",head-> data);
    return 0;
}