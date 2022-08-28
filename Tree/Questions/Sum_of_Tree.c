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

int sum_of_tree(struct Binary_node* root){
    if(root != NULL){
        return (sum_of_tree(root->left) + root->data + sum_of_tree(root->right) );
    }
    else {
       return 0; 
    }
}

int main(){
    /*
    Here created binary tree is like below:-
                    1 
                3       2
              5   7   4   6
    */
    struct Binary_node *root_node, *left, *right, *left12, *left11, *right11, *right12;
    root_node = Create_node(1);
    left = Create_node(3);
    left11 = Create_node(5);
    left12 = Create_node(7);
    right = Create_node(2);
    right11 = Create_node(4);
    right12 = Create_node(6);

    root_node->left = left;
    root_node->right = right;
    left->left = left11;
    left->right = left12;
    right->left = right11;
    right->right = right12;

    printf("%d",sum_of_tree(root_node));

    return 0;
}
