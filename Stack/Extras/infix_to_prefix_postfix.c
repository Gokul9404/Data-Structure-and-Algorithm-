#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
/*
File include Push, Pop, Top, isEmpty, isFull, Precedence, isOperator, isParenthesis & infixtopostfix Functions
Used to convert Infix operation to Postfix operation
*/

struct stack{
    int size;
    int top;
    char *arr;
};

struct stack* Create_stack(int size_of_stack){
    struct stack *s;
    s = (struct stack *)malloc(sizeof(struct stack));
    s->size = size_of_stack;
    s->top = -1;
    s->arr = (char *)malloc(size_of_stack * sizeof(char));
    return s;
}

//---------------------------------------------------------------------------------------
int stackTop(struct stack* sp){
    return sp->arr[sp->top];
}
 
int isEmpty(struct stack *ptr){
    if (ptr->top == -1){
        return 1;
    }
    else{
        return 0;
    }
}
 
int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1){
        return 1;
    }
    else{
        return 0;
    }
}
 
void push(struct stack* ptr, char val){
    if(isFull(ptr)){
        printf("Stack Overflow! Cannot push %d to the stack\n", val);
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}
 
char pop(struct stack* ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    }
    else{
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
//---------------------------------------------------------------------------------------
int isParenthesis(char a){
    if ( (a == '(') || (a== ')') || (a == '[') || (a == ']')|| (a == '{') || (a == '}') ){
        return 1;
    }   
    return 0;
}

int isOperator(char a){
    if ( (a == '+') || (a== '-') || (a == '*') || (a == '/')|| (a == '^') || (a == '}') || (isParenthesis(a)) ){
        return 1;
    }   
    return 0;
}

int precedence(char opr){
    if( (opr == '^') || (isParenthesis(opr)) ){
        return 3;
    }
    else if( (opr == '*') || (opr == '/') ){
        return 2;
    }
    else if( (opr == '+') || ( opr == '-' ) ) {
        return 1;
    }
    else{
        return 0;
    }
}

char* infixToPostfix(char* infix){
    struct stack * sp ;
    sp = Create_stack(100);
    char * postfix = (char *) malloc((strlen(infix)+1) * sizeof(char));
    int i=0; // Track infix traversal
    int j = 0; // Track postfix addition 
    while (infix[i]!='\0'){
        if(!isOperator(infix[i])){
            postfix[j] = infix[i];
            j++;
            i++;
        }
        else{
            if(precedence(infix[i])> precedence(stackTop(sp))){
                push(sp, infix[i]);
                i++;
            }
            else{
                postfix[j] = pop(sp);
                j++;
            }
        }
    }
    while (!isEmpty(sp))    {
        postfix[j] = pop(sp);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}

int main(){
    char * infix = "x-y/z-k*d";
    printf("postfix is %s", infixToPostfix(infix));
    return 0;
}
