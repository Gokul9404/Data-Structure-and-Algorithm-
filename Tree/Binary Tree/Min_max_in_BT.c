#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

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
int Max_no(int a, int b){
    if(a > b){
        return a;
    }
    return b;
}

int Min_no(int a, int b){
    if(a < b){
        return a;
    }
    return b;
}

int Max_in_tree(struct Binary_node* root){
    if(root != NULL){
        Max_no(root->data, Max_no(Max_in_tree(root->left),Max_in_tree(root->right)));
    }
    else {
       return INT_MIN; 
    }
}

int Min_in_tree(struct Binary_node* root){
    if(root != NULL){
        Min_no(root->data, Min_no(Min_in_tree(root->left),Min_in_tree(root->right)));
    }
    else {
       return INT_MAX; 
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
    printf("Minimum element is %d\nMaximum element is %d",Min_in_tree(head),Max_in_tree(head));

    return 0;
}
