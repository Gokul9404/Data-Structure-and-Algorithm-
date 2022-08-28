/*
    Time Complexcity :- O(n)
*/
#include<stdio.h>
#include<stdlib.h>

//---------------------------------------------------------------------------------------
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
//---------------------------------------------------------------------------------------
int is_BST(struct Binary_node* root){
    static struct Binary_node* prev = NULL;
    if(root != NULL){
        if(!is_BST(root->left)){
            return 0;
        }
        if(prev!=NULL && root->data <= prev->data){
            return 0;
        }
        prev = root;
        return is_BST(root->right);
    }
    else{
        return 1;
    }
}

int main(){
    //-----------------------------------------------------------------------------------
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
    head->left = left;
    head->right = right;
    left->left = left11;
    left->right = left12;
    right->left = right11;
    right->right = right12;
    /*
    Here created Binary Search Tree is:-
                        5 
                    3       8
                1   4      6   11
    It's InOrder Traversal is:- 1 3 4 5 6 8 11
    */
    printf("\nInOrder Traversal :- ");
    InOrder(head);
    //-----------------------------------------------------------------------------------
    printf("\nThe tree is BST (0: False/ 1: True):- ");
    printf("%d",is_BST(head));
    return 0;
}
