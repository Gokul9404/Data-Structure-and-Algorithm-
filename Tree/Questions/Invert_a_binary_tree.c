#include<stdio.h>
#include<stdlib.h>
//----------------------------------------------------------------------------------
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
//----------------------------------------------------------------------------------
void InOrder(struct Binary_node* root){
    if(root != NULL){
        InOrder(root->left);
        printf("%d ", root->data);
        InOrder(root->right);
    }
}
//----------------------------------------------------------------------------------
struct Binary_node*  Invert_BT(struct Binary_node* root){
    if(root == NULL){
        return root;
    }
    struct Binary_node *left, *right;
    left = Invert_BT(root->left);
    right = Invert_BT(root->right);

    root->left = right;
    root->right = left;

    return root;
}
//----------------------------------------------------------------------------------
int main(){
    /*  Here created binary tree is like below:-
                        1 
                    3       2
                5   7       4   6
    */
    struct Binary_node *head, *left, *left11, *left12, *right, *right11, *right12;
    head = Create_node(1);
    left = Create_node(3);
    left11 = Create_node(5);
    left12 = Create_node(7);
    right = Create_node(2);
    right11 = Create_node(4);
    right12 = Create_node(6);
    //------------------------------------------------------------------------------ 
    head->left = left;
    head->right = right;
    left->left = left11;
    left->right = left12;
    right->left = right11;
    right->right = right12;
    //------------------------------------------------------------------------------
    head = Invert_BT(head);
    PreOrder(head);
    return 0;
}
