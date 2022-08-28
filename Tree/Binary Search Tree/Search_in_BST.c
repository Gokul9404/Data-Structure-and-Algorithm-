/*
    Time-Complexcity--- 
        Avg/Best case:- O(logn)
        Worst case   :- O(n)
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
//---------------------------------------------------------------------------------------
struct Binary_node* Search(struct Binary_node* root, int key){
    if(root!=NULL){
        if(root->data == key){
            return root;
        }
        else if (root->data > key){
           return Search(root->left,key);
        }
        else if (root->data < key){
           return Search(root->right,key);
        }
    }
    else{
        return NULL;
    }
}

int main(){
    //-----------------------------------------------------------------------------------
    struct Binary_node* head;
    head = Create_node(50);
    struct Binary_node* left;
    left = Create_node(40);
    struct Binary_node* left11;
    left11 = Create_node(21);
    struct Binary_node* left12;
    left12 = Create_node(45);
    struct Binary_node* right;
    right = Create_node(60);
    struct Binary_node* right11;
    right11 = Create_node(56);    
    struct Binary_node* right12;
    right12 = Create_node(80);
    head->left = left;
    head->right = right;
    left->left = left11;
    left->right = left12;
    right->left = right11;
    right->right = right12;
    /*
    Here created Binary Search Tree is:-
                        50
                    40       60
                21  45     56  80
    */
    //-----------------------------------------------------------------------------------
    struct Binary_node* node=NULL;
    node = Search(head,56);
    if(node!=NULL){
        printf("element founded!!");
    }
    else{
        printf("!!element not founded!!");
    }
    return 0;
}
