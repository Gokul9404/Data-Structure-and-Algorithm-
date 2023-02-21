#include <stdio.h>
#include <stdlib.h>

struct Queuue
{
    int size;
    int front;
    int rear;
    int *array_of_queue;
};

struct Queuue *Create_queue(int size)
{
    struct Queuue *queue;
    queue = (struct Queuue *)malloc(sizeof(struct Queuue));
    queue->size = size;
    queue->front = queue->rear = -1;
    queue->array_of_queue = (int *)malloc(queue->size * sizeof(int));
    return queue;
};

int isFull(struct Queuue *q)
{
    if (q->rear == q->size - 1)
    {
        return 1;
    }
    return 0;
}

int isEmpty(struct Queuue *q)
{
    if (q->front == -1 && q->rear == -1)
    {
        return 1;
    }
    return 0;
}

void Enqueue(struct Queuue *q, int val)
{
    if (isFull(q))
    {
        printf("Queue is Full\n");
    }
    else if (q->front == -1 && q->rear == -1)
    {
        q->front = q->rear = 0;
        q->array_of_queue[q->rear] = val;
    }
    else
    {
        q->rear++;
        q->array_of_queue[q->rear] = val;
    }
}

int Dequeue(struct Queuue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is Empty; nothing to remove\n");
        return -1;
    }
    else if (q->front == q->size)
    {
        printf("Queue's array is Completely used; nothing to remove\n");
        return -1;
    }
    else
    {
        int item;
        item = q->array_of_queue[q->front];
        if (q->front == 0 && q->rear == 0)
        {
            q->front = q->rear = -1;
        }
        else
        {
            q->front++;
        }
        return item;
    }
}

int main()
{
    struct Queuue *queue;
    queue = Create_queue(4);

    // Enqueing the value
    Enqueue(queue, 53);

    printf("%d\n", Dequeue(queue));
    return 0;
}