#include<stdio.h>
#include<stdlib.h>

struct Queuue{
    int size;
    int front;
    int rear;
    int *array_of_queue;
};

struct Queuue* Create_queue(int size){
    struct Queuue *queue;
    queue = (struct Queuue *)malloc(sizeof(struct Queuue));
    queue->size = size;
    queue->front = queue->rear = -1;
    queue->array_of_queue = (int *)malloc(queue->size * sizeof(int));
    return queue;
};

int isFull(struct Queuue *q){
    if ((q->rear + 1) % q->size == q->front) {
        return 1;
    }
    return 0;
}

int isEmpty(struct Queuue *q){
    if (q->front == q->rear){
        return 1;
    }
    return 0;
}

void Enqueue(struct Queuue *q,int val){
    if (isFull(q)){
        printf("Queue Overflow");
    }
    else{
        q->rear = ((q->rear + 1) % q->size);
        q->array_of_queue[q->rear] = val;
    }
}

int Dequeue(struct Queuue *q){
    int val = -1;
    if (isEmpty(q)){
        printf("Queue is Empty; nothing to remove\n");
    }
    else{
        q->front = ((q->front + 1) % q->size);
        val = q->array_of_queue[q->front];
    }
    return val;
}


int main(){
    struct Queuue *queue;
    queue = Create_queue(4);
    
    // Enqueing the value
    Enqueue(queue,53);
    
    // Dequeuing the Values
    printf("%d\n",Dequeue(queue));
    return 0;
}