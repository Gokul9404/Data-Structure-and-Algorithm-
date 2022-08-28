/*
    Height of a Tree => No. of edges in longest-path from Root to leaf-node

    Depth of a node => no. of edges in path from root to the node itself.

    Time Complexcity :- O(n)
*/
/*                      
                        5   -> height=3; depth=0
height=2; depth=1;<- 3      7
                  2  4    6  11
                1 -> height=0; depth=3;             
*/
//---------------------------------------------------------------------------------------
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
int Max(int a, int b){
    if(a > b){
        return a;
    }
    return b;
}

int Find_height(struct Binary_node* root){
    int left_height = 0, right_height = 0;
    if(root!=NULL){
        left_height = Find_height(root->left);
        right_height = Find_height(root->right);
        return (Max(left_height,right_height) + 1);
    }
    else{
       return -1; 
    }
}

int main(){
    struct Binary_node* head;
    head = Create_node(5);
    struct Binary_node* left;
    left = Create_node(3);
    struct Binary_node* right;
    right = Create_node(7);
    head->left = left;
    head->right = right;
    Insert(head,11);
    Insert(head,4);
    Insert(head,2);
    Insert(head,1);
    Insert(head,6);
    printf("\nInOrder Traversal :- ");
    InOrder(head);
    //-----------------------------------------------------------------------------------
    printf("\n%d",Find_height(head));

    return 0;
}