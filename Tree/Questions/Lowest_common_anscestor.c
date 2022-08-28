#include<stdio.h>
#include<stdlib.h>

//---------------------------------------------------------
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
//---------------------------------------------------------
struct Binary_node* Lowest_common_anscestor(struct Binary_node* root, int n1, int n2){
    if(root == NULL){
        return NULL;
    }
    if(root->data == n1 || root->data == n2){
        return root;
    }
    struct Binary_node* left = Lowest_common_anscestor(root->left,n1,n2);
    struct Binary_node* right = Lowest_common_anscestor(root->right,n1,n2);

    if(left == NULL){   return right;}
    if(right == NULL){  return left;}
    
    return root;
}
//---------------------------------------------------------
int main(){struct Binary_node* head;
    head = Create_node(5);
    struct Binary_node* left, *left11, *left12;
    left = Create_node(3);
    left11 = Create_node(1);
    left12 = Create_node(4);
    struct Binary_node* right, *right11, *right12;
    right = Create_node(8);
    right11 = Create_node(6);
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
    printf("%d\n",Lowest_common_anscestor(head,1,4)->data);
    printf("It's address:- %d",Lowest_common_anscestor(head,1,4));
    return 0;
}