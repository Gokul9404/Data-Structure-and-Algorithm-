/*
    Traversal in Binary Tree is done different ways, but unlike stack, queue, array we cannot Traverse Binary Tree like them.

    Traversal in Binary Tree is done in wyas like :- InOrder, PostOrder, PreOrder

    InOrder:- we traverse through left sub-tree -> root -> right sub-tree

    PostOrder:- we traverse through left sub-tree -> right sub-tree -> root
    
    PreOrder:- we traverse through root -> left sub-tree -> right sub-tree

    Level Order :-  we traverse through level-by-level
                    Time-Complxcity :- O(n); SpaceComplexcity :- Avg/Worst:-O(n): Best:-O(1) 
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
//---------------------------------------------------------------------------------------
void PreOrder(struct Binary_node* root){
    if(root != NULL){
        printf("%d ", root->data);
        PreOrder(root->left);
        PreOrder(root->right);
    }
}
//---------------------------------------------------------------------------------------
void PostOrder(struct Binary_node* root){
    if(root != NULL){
        PostOrder(root->left);
        PostOrder(root->right);
        printf("%d ", root->data);
    }
}
//---------------------------------------------------------------------------------------
void InOrder(struct Binary_node* root){     // Inorder can also used as depth first travel
    if(root != NULL){
        InOrder(root->left);
        printf("%d ", root->data);
        InOrder(root->right);
    }
}
//---------------------------------------------------------------------------------------
struct Que_Node *front = NULL, *rear = NULL;

struct Que_Node{
    struct Binary_node* BT_node;
    struct Que_Node* next;
};

struct Que_Node* New_Node(struct Binary_node* new_node){
    struct Que_Node* node = (struct Que_Node*) malloc(sizeof(struct Que_Node));
    node->BT_node = new_node;    
    node->next = NULL;
    return node;
};

void Enqueue(struct Binary_node* new_node){
    if(new_node!=NULL){
    struct Que_Node* node = New_Node(new_node);
    if (front == NULL){
        front = node;
        rear = node;
    }
    else{
        rear->next = node;
        rear = node;
    }}
}

struct Binary_node* Dequeue(){
    struct Binary_node* ptr = NULL;
    if (front == NULL){
        printf("Queue is Empty\n");
    }
    else{
        ptr = front->BT_node;
        front = front->next;
    }
    return ptr;
}

void Free_up_pointer(struct Que_Node* ptr){
    free(ptr);
}

void Level_order_trversal(struct Binary_node* root){        // Bradth First travel
    if(root!=NULL){
        struct Binary_node* Cur_ptr=NULL;
        int val=0;
        Enqueue(root);
        while (front!=NULL && rear!=NULL){
            Cur_ptr = Dequeue();
            val = Cur_ptr->data;
            printf("%d ", val);
            Enqueue(Cur_ptr->left);
            Enqueue(Cur_ptr->right);
        }  
    }
}
//---------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------
int main(){
    /*
    Here created binary tree is like below:-
                    1 
                3       2
              5   7   4   6
    */
    struct Binary_node* root_node;
    root_node = Create_node(1);
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

    root_node->left = left;
    root_node->right = right;
    left->left = left11;
    left->right = left12;
    right->left = right11;
    right->right = right12;

    printf("\nPreOrder Traversal :- ");
    PreOrder(root_node);
    // PreOrder traversal of tree is :- 1 3 5 7 2 4 6 

    printf("\nPostOrder Traversal :- ");
    PostOrder(root_node);
    // PostOrder traversal of tree is :- 5 7 3 4 6 2 1

    printf("\nInOrder Traversal :- ");
    InOrder(root_node);
    // InOrder traversal of tree is :- 5 7 3 1 4 6 2

    printf("\nLevel_order Traversal :- ");
    Level_order_trversal(root_node);


    return 0;
}
