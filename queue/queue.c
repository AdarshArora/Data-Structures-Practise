// Implementation of Queue Data structure using Array
// Methods - isEmpty(), isFull(), enqueue(), dequeue, peek(), display()


#include <stdio.h>
#include <stdlib.h>

struct queue{
    int size;
    int front;
    int back;
    int *arr;
};
int isFull(struct queue *q){
    if(q->back==q->size-1){
        return 1;
    }return 0;
}
int isEmpty(struct queue *q){
    if(q->front==q->back){
        return 1;
    }return 0;
}


void enqueue(struct queue *q, int data){
    if(isFull(q)){
        printf("Queue Full\n");
        return;
    }else{
        q->back++;
        q->arr[q->back]= data;
    }
}

int dequeue(struct queue *q){
    if(isEmpty(q)){
        printf("Queue empty cant remove elements\n");
        return -1;
    }else{
        q->front++;
        return q->arr[q->front];

    }
}

int firstVal(struct queue *q){
    return q->arr[q->front+1];
}
int lastVal(struct queue *q){
    return q->arr[q->back];
}
void display(struct queue *q){
    for(int i=q->front+1; i<=q->back; i++){
        printf("%d ",q->arr[i]);
    }
}

void peek(struct queue *q, int pos){
    printf("Element at Position %d is : %d\n",pos,q->arr[q->front+pos]);
}

int main()
{
    struct queue *q = (struct queue*)malloc(sizeof(struct queue));
    q->size = 100;
    q->front = q->back = -1;
    q->arr = (int*)malloc(q->size*sizeof(int));

    enqueue(q,5);
    enqueue(q,10);
    enqueue(q,15);
    enqueue(q,20);
    display(q);

    printf("\nElement removed: %d\n",dequeue(q));
    printf("Element removed: %d\n",dequeue(q));
    peek(q,1);
    peek(q,2);

    display(q);








 return 0;
}