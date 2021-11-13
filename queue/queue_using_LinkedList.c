#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *back = NULL;

int isFull(struct Node *newNode)
{
    if (newNode == NULL)
    {
        return 1;
    }
    return 0;
}

int isEmpty(struct Node *front)
{
    if (front == NULL)
    {
        return 1;
    }
    return 0;
}

void enqueue(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    if (isFull(newNode))
    {
        printf("Queue is Full\n");
    }
    else
    {
        newNode->data = data;
        newNode->next = NULL;
        if (front == NULL)
        { //pointing both front & back to first element (if queue/list is null).
            front = back = newNode;
        }
        back->next = newNode;
        back = newNode;
    }
}

int dequeue()
{
    int a = -1;
    if (isEmpty(front))
    {
        printf("Empty queue\n");
    }
    else
    {
        struct Node *temp = front;
        front = front->next;
        a = temp->data;
        free(temp);
    }
    return a;
}

void display()
{
    struct Node *temp = front;
    while (temp != NULL)
    {
        printf("%d--> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{

    enqueue(5);
    enqueue(10);
    enqueue(15);
    display();
    
    dequeue();

    display();

    return 0;
}