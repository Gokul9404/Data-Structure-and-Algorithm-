/*
----Queue----
    -> Data structure that is based on First-In First-Out (FIFO)
    -> Can be implimented by array, linked list

    -> It uses the percentile operator(%) for the continous operation in the array of queue
*/

#include<stdio.h>
#include<stdlib.h>

struct Queuue{
    int size;
    int front;
    int rear;
    int *array_of_queue;
};

struct Queuue Create_queue(int size){
    struct Queuue queue;
    queue.size = size;
    queue.front = queue.rear = -1;
    queue.array_of_queue = (int *)malloc(queue.size * sizeof(int));
    return queue;
};


int main(){
    struct Queuue queue;
    queue = Create_queue(10);
    return 0;
}