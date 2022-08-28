#include<stdio.h>
#include<stdlib.h>

struct edge_list_node{
    int data;       // Storing the integer value of the vertecies
    struct edge_list_node* next;
};

struct vertex_list{
    int vertex_no;       // Storing the integer value of the vertecies in the vertex list and it's value
    char vertex_name;
    struct vertex_list* next;
    struct edge_list_node* edge_list_head;
};

struct vertex_list* New_vertex_connection(int vertex_no, char vertex){
    struct vertex_list* node = (struct vertex_list*) malloc(sizeof(struct vertex_list));
    node->vertex_no = vertex_no;
    node->vertex_name = vertex;
    node->edge_list_head = NULL;
    node->next = NULL;
    return node;
};

struct vertex_list* head = NULL;

struct edge_list_node* New_edge_connection(int vertex_no){
    struct edge_list_node* node = (struct edge_list_node*) malloc(sizeof(struct edge_list_node));
    node->data = vertex_no;
    node->next = NULL;
    return node;
};

void insert_vertex(struct vertex_list* vertex_list){
    // Time-complexcity :- o(n)
    int vertex_no;
    char vertex_name;
    struct vertex_list* temp;
    printf("\nEnter the vertex name:-");
    scanf("%c",&vertex_name);
    printf("Enter the vertex value:-");
    scanf("%d",&vertex_no);
    struct vertex_list* ptr = New_vertex_connection(vertex_no,vertex_name);
    if (vertex_list == NULL){
        vertex_list = ptr;
    }
    else{
        temp = vertex_list;
        while (temp ->next != NULL){
            temp = temp->next;
        }
        temp->next = ptr;
        ptr->next = NULL;
    }
}

void display_vertex(struct vertex_list* vertex_list){
    struct vertex_list *ptr;
    int no = 0;
    ptr = vertex_list;
    if (ptr == NULL){
        printf("List is empty");
    }
    else{
        while (ptr != NULL){
            printf("Vertex-list node Integer no::%d and data:- %c\n",ptr->vertex_no,ptr->vertex_name);
            ptr = ptr->next;
            no++;
        }   
    }
}

void delete_last_vertex(struct vertex_list* vertex_list){
    // Time-complexcity:- o(n)
    struct vertex_list *ptr, *ptr_p;
    ptr = vertex_list;
    if(ptr == NULL){
        printf("\nList is empty\n");
    }
    else if(ptr->next = NULL){
        free(ptr);
        printf("\nList-deleted\n");
    }
    else{
        while (ptr->next != NULL){
            ptr_p = ptr;
            ptr = ptr->next;
        }
        ptr_p->next = NULL;
        free(ptr);
        printf("\nTail of the List deleted\n");
    }
}

void insert_edge(struct vertex_list* vertex_list,int from_vertex_no){
    // Time-complexcity :- o(n)
    struct edge_list_node* vertex_edge_list=NULL;

    struct vertex_list *ptr;
    ptr = vertex_list;
    if (ptr == NULL){
        printf("Vertex edge List is empty");
        return;
    }
    else{
        while (ptr != NULL){
            if (ptr->vertex_no == from_vertex_no){
                vertex_edge_list = ptr->edge_list_head;
                break;
            }
            ptr = ptr->next;
        }   
    }

    int to_vertex_no;
    struct edge_list_node* temp;
    printf("Enter the new vertex edge connection :-");
    scanf("%d",&to_vertex_no);
    struct edge_list_node* new_ver_con = New_edge_connection(to_vertex_no);
    if (vertex_edge_list == NULL){
        vertex_edge_list = new_ver_con;
    }
    else{
        temp = vertex_edge_list;
        while (temp ->next != NULL){
            temp = temp->next;
        }
        temp->next = new_ver_con;
        new_ver_con->next = NULL;
    }
}

void display_edge(struct edge_list_node* vertex_edge_list){
    struct edge_list_node *ptr;
    int no = 0;
    ptr = vertex_edge_list;
    if (ptr == NULL){
        printf("List is empty");
    }
    else{
        while (ptr != NULL){
            printf("Linked-list node[%d] data:- %d\n",no,ptr->data);
            ptr = ptr->next;
            no++;
        }   
    }
}

void delete_last_edge(struct edge_list_node* vertex_edge_list){
    // Time-complexcity:- o(n)
    struct edge_list_node *ptr, *ptr_p;
    ptr = vertex_edge_list;
    if(ptr == NULL){
        printf("\nList is empty\n");
    }
    else if(ptr->next = NULL){
        free(ptr);
        printf("\nList-deleted\n");
    }
    else{
        while (ptr->next != NULL){
            ptr_p = ptr;
            ptr = ptr->next;
        }
        ptr_p->next = NULL;
        free(ptr);
        printf("\nTail of the List deleted\n");
    }
}

int main(){
    return 0;
}
