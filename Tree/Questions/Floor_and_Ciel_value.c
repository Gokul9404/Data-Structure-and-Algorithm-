#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
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
//---------------------------------------------------------------------------------------
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
int Find_floor(struct Binary_node* root, int key){
    int ans = INT_MAX;
    while (root != NULL){
        if (root->data == key){
            return root->data;
        }
        if (root->data > key){
            root = root->left;
        }
        else{
            ans = root->data;
            root = root->right;
        }
    }
    return ans;
}


int Find_ceil(struct Binary_node* root, int key){
    int ans = INT_MIN;
    while (root != NULL){
        if (root->data == key){
            return root->data;
        }
        if (root->data > key){
            ans = root->data;
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
    return ans;
}
//-----------------------------------------------------------------------------------

int main(){
    struct Binary_node* head;
    head = Create_node(5);
    struct Binary_node* left;
    left = Create_node(3);
    struct Binary_node* right;
    right = Create_node(8);
    head->left = left;
    head->right = right;
    //-----------------------------------------------------------------------------------
    Insert(head,11);
    Insert(head,4);
    Insert(head,2);
    Insert(head,1);
    Insert(head,12);
    Insert(head,6);   
    Insert(head,9);   
    /*
    Here created Binary Search Tree is:-
                        5 
                    3       8
                2     4   6     11 
            1                 9     12
    */
    //-----------------------------------------------------------------------------------
    printf("Floor value of %d is :- %d\n",10,Find_floor(head,10));
    printf("Floor value of %d is :- %d\n",10,Find_ceil(head,10));
    return 0;
}
