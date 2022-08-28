#include<stdio.h>
#include<stdlib.h>

/*
This code-file include Stack implementation with the help of array.
Functions included Push, Pop, isFull, isEmpty, Peek, Top, Bottom
*/

struct stack{
    int size;
    int top;
    int *arr;
};

struct stack* Create_stack(int size_of_stack){
    struct stack *s;
    s = (struct stack *)malloc(sizeof(struct stack));
    s->size = size_of_stack;
    s->top = -1;
    s->arr = (int *) malloc( s->size * sizeof(int));
    return s;
}

int isEmpty(struct stack* stack_pointer){
    if (stack_pointer -> top == -1){
        return 1;
    } 
    return 0;
}

int isFull(struct stack* stack_pointer){
    if (stack_pointer -> top == (stack_pointer->size -1)){
        return 1;
    } 
    return 0;
}

int Push(struct stack* stack_pointer,int item){
    if( isFull(stack_pointer) ){
        printf("\n\tStack OverFlow!!\ncannot Push Item into the Stack\n");
        return -1;
    }
    else{
        stack_pointer-> top++;
        stack_pointer->arr[stack_pointer->top] = item;
        printf("\nItem Pushed into the Stack");
        return 1;
    }
}

int Pop(struct stack* stack_pointer){
    if(isEmpty(stack_pointer)){
        printf("\n\tStack UnderFlow!!\nStack is already empty\n");
        return -1;
    }
    else{
        int val;
        val = stack_pointer->top;
        stack_pointer->top = val - 1;
        printf("\nItem Poped from the Stack");
        return 1;
    }
}

void Peek(struct stack* stack_pointer, int i){
    if (isEmpty(stack_pointer)){
        printf("Stack is Empty!!");
    }
    else{
        int arry_indx = stack_pointer-> top - i + 1; // It representes the items from the top of stack
        if (arry_indx < 0){
            printf("Item not found");
        }
        else{
            printf("Item at top with index[%d]:- %d", i, stack_pointer-> arr[arry_indx]);
        }
    }
}

void Top(struct stack* stack_pointer){
    if (isEmpty(stack_pointer)){
        printf("\n\tStack is Empty!!!");
    }
    else{
        printf("The Value at the top of the stack is:- %d",stack_pointer->arr[stack_pointer->top]);
    }
}

void Bottom(struct stack* stack_pointer){
    if (isEmpty(stack_pointer)){
        printf("\n\tStack is Empty!!!");
    }
    else{
        printf("The Value at the bottom of the stack is:- %d",stack_pointer->arr[0]);
    }
}

int main(){
    struct stack *s;  // creating a pointer of the stack
    s = Create_stack(12);    // Dynamiclly allocating the memory for the stack via array
    printf("\n%d %d",isEmpty(s),isFull(s));
    Push(s,43);
    Push(s,34);
    printf("\n%d %d",isEmpty(s),isFull(s));
    Top(s);
    // Bottom(s);
    Pop(s);
    Pop(s);
    return 0;
}