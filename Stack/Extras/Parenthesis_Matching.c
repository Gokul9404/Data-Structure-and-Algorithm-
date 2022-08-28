/*
Program to-do the parenthesis matching on a given equation of maths...
*/

#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

struct stack* Create_stack(int size_of_stack){
    struct stack *s;
    s = (struct stack *)malloc(sizeof(struct stack));
    s->size = size_of_stack;
    s->top = -1;
    s->arr = (char *) malloc( s->size * sizeof(char));
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

int Push(struct stack* stack_pointer, char item){
    if( isFull(stack_pointer) ){
        // printf("\n\tStack OverFlow!!\ncannot Push Item into the Stack\n");
        return -1;
    }
    else{
        stack_pointer-> top++;
        stack_pointer->arr[stack_pointer->top] = item;
        // printf("\nItem Pushed into the Stack");
        return 1;
    }
}

int Pop(struct stack* stack_pointer){
    if(isEmpty(stack_pointer)){
        // printf("\n\tStack UnderFlow!!\nStack is already empty\n");
        return -1;
    }
    else{
        int val;
        val = stack_pointer->top;
        stack_pointer->top = val - 1;
        // printf("\nItem Poped from the Stack");
        return 1;
    }
}

int match_para(char a, char b){
    if ( (a == '(') && (b == ')') || (a == '[') && (b == ']') || ( a == '{') && (b == '}') ){
        return 1;
    }   
    return 0;
}


int parenthesis(char * exp){
    struct stack* sp;
    sp = Create_stack(15);
    char e;
    for(int i = 0; exp[i] != '\0'; i++){
        e = exp[i];
        if ((e == '(') || (e == '[') || (e == '{')) {
            Push(sp, e);
        }
        else if ((e == '}') || (e == ']') || (e == ')')) {
            if(isEmpty(sp)){
                printf("");
            }
            else{
                char stk_exp = sp->arr[sp->top];
                if (match_para(stk_exp, e)){
                    Pop(sp);
                }
            }
        }
    }
    if (isEmpty(sp)){
        return 1;
    }
    else{
        return 0;
    }
}

int main()
{
    char *chk = "{8*(9)}";
    if(parenthesis(chk)){
        printf("Parenthesis Matched!!");
    }
    else{
        printf("Parenthesis not matched");
    }
    return 0;
}