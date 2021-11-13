#include <stdio.h>
#include <stdlib.h>

struct DEqueue
{
    /* data */
    int size;
    int front;
    int back;
    int *arr;
};

int isFull(struct DEqueue *q)
{
    if (q->back == q->size - 1)
    {
        return 1;
    }
    return 0;
}

int isEmpty(struct DEqueue *q)
{
    if (q->front == q->back)
    {
        return 1;
    }
    return 0;
}

void enqueueBack(struct DEqueue *q, int data)
{
    if (isFull(q))
    {
        printf("DEqueue is full\n");
    }
    else
    {
        q->back++;
        q->arr[q->back] = data;
    }
}

void enqueueFront(struct DEqueue *q, int data)
{
    if (isFull(q))
    {
        printf("DEqueue is full\n");
    }
    else
    {
        if (q->front != -1)
        {
            q->arr[q->front--] = data;
        }
        else
        {
            printf("Can't add element from front now since front is -1\n");
        }
    }
}

int dequeueFront(struct DEqueue *q)
{
    if (isEmpty(q))
    {
        printf("Empty DEqueue cant remove\n");
        return -1;
    }
    else
    {
        q->front++;
        return q->arr[q->front];
    }
}

int dequeueBack(struct DEqueue *q)
{
    if (isEmpty(q))
    {
        printf("Empty DEqueue cant remove\n");
        return -1;
    }
    else
    {
        return q->arr[q->back--];
    }
}

void display(struct DEqueue *q)
{
    for (int i = q->front + 1; i <= q->back; i++)
    {
        printf("%d ", q->arr[i]);
    }
}

int main()
{
    struct DEqueue *q = (struct DEqueue *)malloc(sizeof(struct DEqueue));
    q->size = 100;
    q->back = q->front = -1;
    q->arr = (int *)malloc(q->size * sizeof(int));

    enqueueBack(q, 5);
    enqueueBack(q, 10);
    enqueueBack(q, 15);
    enqueueBack(q, 20);
    dequeueFront(q);
    enqueueFront(q,15);
    dequeueBack(q);
    enqueueBack(q,25);
    


    display(q);

    return 0;
}