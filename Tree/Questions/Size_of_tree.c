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
//---------------------------------------------------------------------------------------
// Time & Space Complexcity :- O(n)
int Size_of_node(struct Binary_node* root){
    if(root != NULL){
        return (Size_of_node(root->left) + Size_of_node(root->right) + 1);
    }
    else {
       return 0; 
    }
}
//---------------------------------------------------------------------------------------
int main(){
    struct Binary_node* head;
    head = Create_node(1);
    struct Binary_node* left;
    left = Create_node(3);
    struct Binary_node* left11;
    left11 = Create_node(5);
    struct Binary_node* left12;
    left12 = Create_node(7);
    struct Binary_node* right;
    right = Create_node(2);
    struct Binary_node* right11;
    right11 = Create_node(4);
    struct Binary_node* right12;
    right12 = Create_node(6);
    head->left = left;
    head->right = right;
    left->left = left11;
    left->right = left12;
    right->left = right11;
    right->right = right12;
    /*
    Here created binary tree is like below:-
                    1 
                3       2
            5   7       4   6
    */

    printf("The size of the tree is :- %d",Size_of_node(head));
    return 0;
}
