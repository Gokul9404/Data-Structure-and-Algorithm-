#include<stdio.h>
#include<stdlib.h>


// For linked list implementation the code is below:::::-
// TIme complexcity to search, delete, and match will be :- O(n)
struct edge_list_node{
    int data;       // Storing the integer value of the vertecies
    struct edge_list_node* next;
};

struct vetex_list{
    int vertex_no;       // Storing the integer value of the vertecies in the vertex list and it's value
    char *vertex;
    struct vertex_list* next;
    struct edge_list_node* head;
};


struct edge_list_node* New_edge_connection(int vertex_no){
    struct edge_list_node* node = (struct edge_list_node*) malloc(sizeof(struct edge_list_node));
    node -> data = vertex_no;
    node -> next = NULL;
    return node;
};

struct edge_list_node* head = NULL;

void insert(){
    // Time-complexcity :- o(n)
    int vertex_no;
    struct edge_list_node* temp;
    printf("Enter the value to be instered into the node:-");
    scanf("%d",&vertex_no);
    struct edge_list_node* ptr = New_edge_connection(vertex_no);
    if (head == NULL){
        head = ptr;
    }
    else{
        temp = head;
        while (temp -> next != NULL){
            temp = temp -> next;
        }
        temp -> next = ptr;
        ptr -> next = NULL;
    }
}

void display(){
    struct edge_list_node *ptr;
    int no = 0;
    ptr = head;
    if (ptr == NULL){
        printf("List is empty");
    }
    else{
        while (ptr != NULL){
            printf("Linked-list node[%d] data:- %d\n",no,ptr->data);
            ptr = ptr -> next;
            no++;
        }   
    }
}

void delete(){
    // Time-complexcity:- o(n)
    struct edge_list_node *ptr, *ptr_p;
    ptr = head;
    if(ptr == NULL){
        printf("\nList is empty\n");
        
    }
    else if(ptr -> next = NULL){
        free(ptr);
        printf("\nList-deleted\n");
    }
    else{
        ptr =head;
        while (ptr->next != NULL){
            ptr_p = ptr;
            ptr = ptr->next;
        }
        ptr_p->next = NULL;
        free(ptr);
        printf("\nTail of the List deleted\n");
    }
}

//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
// For AVL Tree implementation :::--
// Time complexcity for search , delete and match is :- O(log n)
// Just implement the avl tree with head node address stored in the Vertex list node


int main(){
    return 0;
}
