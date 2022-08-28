/*
Stack
    LIFO format data structure, can be implemented by Array, Linked list
*/
#include<stdio.h>
#include<stdlib.h>

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

int main()
{
    return 0;
}