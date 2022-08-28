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

void Insert(struct Binary_node* root,int key){
    struct Binary_node* prev = NULL;
    while (root != NULL){
        prev = root;
        if(key == root->data){
            printf("\nElement already exist\n");
            return;
        }
        else if(root->data > key){
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
    struct Binary_node* new_node = Create_node(key);
    if(key < prev->data){
        prev->left = new_node;
    }
    else{
        prev->right = new_node;
    }
}
//---------------------------------------------------------------------------------------
int Max_in_BST(struct Binary_node* root){
    if(root != NULL){
        struct Binary_node* cur = root;
        while (cur->right != NULL){
            cur = cur->right;
        }
        return cur->data;
    }
    else {
        printf("\nThe Tree is empty!\n");
       return -1;
    }
}

int Min_in_BST(struct Binary_node* root){
    if(root != NULL){
        struct Binary_node* cur = root;
        while (cur->left != NULL){
            cur = cur->left;
        }
        return cur->data;
    }
    else {
        printf("\nThe Tree is empty!\n");
       return -1;
    }
}

int main(){
    //-----------------------------------------------------------------------------------
    struct Binary_node* head;
    head = Create_node(5);
    struct Binary_node* left;
    left = Create_node(3);
    struct Binary_node* right;
    right = Create_node(8);
    head->left = left;
    head->right = right;
    printf("\nInOrder Traversal :- ");
    InOrder(head);
    Insert(head,11);
    Insert(head,4);
    Insert(head,2);
    Insert(head,1);
    Insert(head,12);
    Insert(head,6);
    // After insetion InOrder Traversal :- 1 2 3 4 5 6 8 11 12
    printf("\nInOrder Traversal :- ");
    InOrder(head);
    //-----------------------------------------------------------------------------------
    printf("\nMinimum element of BST:- %d\nMaximum element in BST:- %d",Min_in_BST(head),Max_in_BST(head));
    return 0;
}
