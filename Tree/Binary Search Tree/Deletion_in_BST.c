/*
    Deletion in BST
        When deleting a non-leaf node or root node it requires a Inorder Predesescor or InOrder Successor.
        Thus when deleting a non-leaf node or root node we do a InOreder travarsal such that we get a bigger(inorder-post) value and a smaller(inorder-pre) value than the value/node-value to be deleted,
        then we seek for leaf node in b/w these two value, the node which is a leaf-node is replaced by the node-to-delete.
*/
/*                      
                        5
                    3       8
                  2  4    7  11
                1        6     12
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
//---------------------------------------------------------------------------------------
struct Binary_node* InorderPredessor(struct Binary_node* root){
    root = root->left;
    while (root->right != NULL){
        root = root->right;
    }
    return root;
}

struct Binary_node* Delete_node(struct Binary_node* root, int key){
    struct Binary_node* iPre;   
    if(root == NULL){
        return NULL;
    }
    if(root->left == NULL && root->right == NULL){
        free(root);
        return NULL;
    }

    if(root->data > key){
        root->left = Delete_node(root->left, key);
    }
    else if(root->data < key){
        root->right = Delete_node(root->right, key);
    }
    else{
        iPre = InorderPredessor(root);
        root->data = iPre->data;
        root->left = Delete_node(root->left, iPre->data);
    }
    return root;
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
    /*
    Here created Binary Search Tree is:-
                        5 
                    3       8
    It's InOrder Traversal is:- 3 5 8
    */
    printf("InOrder Traversal :- ");
    InOrder(head);
    Insert(head,11);
    Insert(head,4);
    Insert(head,2);
    Insert(head,1);
    Insert(head,12);
    Insert(head,6);
    Insert(head,7);
    /*                  5
                    3      8
                  2  4    7  11
                1        6     12
    After insetion InOrder Traversal :- 1 2 3 4 5 6 7 8 11 12
    */
    printf("\nInOrder Traversal :- ");
    InOrder(head);
    //-----------------------------------------------------------------------------------
    Delete_node(head, 8);
    /*                  5
                    3      7
                  2  4    6  11
                1              12
    After insetion InOrder Traversal :- 1 2 3 4 5 6 7 11 12
    */
    printf("\nInOrder Traversal :- ");
    InOrder(head);

    return 0;
}