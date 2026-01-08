#include <stdio.h>
#include <stdlib.h>

#define size 10

int front = -1, rear = -1;

int* Q;

void enqueue(int x)
{
    if((rear + 1) % size == front)
    {
        printf("Queue OverFlow!\n");
    }
    else if(front == -1)
    {
        front = rear = 0;
        Q[rear] = x;
    }
    else
    {
        rear = (rear + 1) % size;
        Q[rear] = x;
    }
}

void dequeue()
{
    if(front == -1)
    {
        printf("Queue UnderFlow!\n");
    }
    else if(front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % size;
    }
}

void display()
{
    if(front == -1)
    {
        printf("Queue Empty!\n");
        return;
    }

    printf("Circular Queue: ");

    int i = front;

    while(i != rear)
    {
        printf("%d ", Q[i]);

        i = (i+1) % size;
    }

    printf("%d\n", Q[i]);
}

int main()
{
    Q = (int*) malloc(size*sizeof(int));

    enqueue(10); enqueue(20); enqueue(30); enqueue(40);

    display();

    dequeue(); dequeue();

    display();

    return 0;
}
