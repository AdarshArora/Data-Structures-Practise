// Circular queue implementation for effective space utilization
// Functions - enqueue(), dequeue(), isFull(), isEmpty()

#include <stdio.h>
#include <stdlib.h>

struct cqueue
{
    int size;
    int front;
    int back;
    int *arr;
};

int isFull(struct cqueue *q)
{
    if ((q->back + 1) % q->size == q->front)
    {
        return 1;
    }
    return 0;
}

int isEmpty(struct cqueue *q)
{
    if (q->front == q->back)
    {
        return 1;
    }
    return 0;
}

void enqueue(struct cqueue *q, int data)
{
    if (isFull(q))
    {
        printf("Queue is full cant add element\n");
        return;
    }
    else
    {
        q->back = (q->back + 1) % q->size; //incermenting using Circular increment
        q->arr[q->back] = data;
        printf("Enqued Element: %d\n", data);
    }
}

int dequeue(struct cqueue *q)
{
    int ele = -1;
    if(isEmpty(q))
    {
        printf("Queue is empty can't remove element\n");
    }
    else
    {
        q->front = (q->front + 1) % q->size;
        ele = q->arr[q->front];
    }
    return ele;
}

void display(struct cqueue *q){

    int i= q->front+1;
    printf("Elements-->");
    while(i<=q->back){
        
        printf("%d ",q->arr[i]);
        i = (i+1)%q->size;
    }
    
    printf("\n");
}

int main()
{
    struct cqueue *q = (struct cqueue *)malloc(sizeof(struct cqueue));
    q->size = 10;
    q->front = q->back = 0;
    q->arr = (int *)malloc(q->size * sizeof(int));

    enqueue(q,5);
    enqueue(q,10);
    enqueue(q,15);
    display(q);

    printf("Removed Element: %d\n",dequeue(q)); 
    printf("Removed Element: %d\n",dequeue(q));
    
    enqueue(q,30);
    enqueue(q,35);
    display(q);






    return 0;
}