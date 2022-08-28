#include<stdio.h>
#include<stdlib.h>

//---------------------------------------------------------
int ans=0;
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
int Max(int a, int b){
    if(a > b){
        return a;
    }
    return b;
}

int Height(struct Binary_node* root){
    // Time Complexcity O(N)
    int left_height = 0, right_height = 0;
    if(root==NULL){
        return 0;
    }
    left_height = Height(root->left);
    right_height = Height(root->right);
    ans = Max(ans,1+left_height+right_height);  // This line will help to find the daimeter of the tree
    return (Max(left_height,right_height) + 1);
}
//---------------------------------------------------------
int daimeter(struct Binary_node* root){
    // Time Complexcity O(N^2)
    if (root == NULL){
        return 0;
    }
    int dl, dr, cur;
    dl = daimeter(root->left);
    dr = daimeter(root->right);
    cur = Height(root->left) + Height(root->right) + 1;
    return Max(cur, Max(dl,dr));
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
    Height(head);
    printf("%d",ans);
    printf("\n%d",daimeter(head));

    return 0;
}