/*
    Binary Search Tree is a binary-tree that have certain properties to it:-
    |-> There are no-duplicate node values
    |-> All the right-node's-value are greater than than the root-node-value 
    |-> All the left-node's-value are lesser than than the root-node-value 
    |-> InOrder traversal of BST is always in ascending order
    |-> All the left & right nodes are BST  (this condition is by default true, just ignore it)
*/
/*
Here example of Binary Search Tree :-
                    5 
                3       8
            2   4      7   11
                     6      

InOrder Traversal is:- 2 3 4 5 6 7 8 11
*/
#include<stdio.h>
#include<stdlib.h>

struct Binary_node{
    int data;
    struct Binary_node* left;
    struct Binary_node* right;
};


struct Binary_node* Create_node(int dataa){
    struct Binary_node* node;
    node = (struct Binary_node *) malloc(sizeof(struct Binary_node));
    node->data = dataa;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void InOrder(struct Binary_node* root){
    if(root != NULL){
        InOrder(root->left);
        printf("%d ", root->data);
        InOrder(root->right);
    }
}

int main(){
    struct Binary_node* head;
    head = Create_node(5);

    struct Binary_node* left;
    left = Create_node(3);
    
    struct Binary_node* left11;
    left11 = Create_node(1);
    
    struct Binary_node* left12;
    left12 = Create_node(4);
    
    struct Binary_node* right;
    right = Create_node(8);

    struct Binary_node* right11;
    right11 = Create_node(6);
    
    struct Binary_node* right12;
    right12 = Create_node(11);
    /*
    Here created Binary Search Tree is:-
                        5 
                    3       8
                1   4      6   11
    It's InOrder Traversal is:- 1 3 4 5 6 8 11
    */
    head->left = left;
    head->right = right;
    
    left->left = left11;
    left->right = left12;

    right->left = right11;
    right->right = right12;

    printf("\nInOrder Traversal :- ");
    InOrder(head);

    return 0;
}
