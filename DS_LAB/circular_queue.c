#include <stdio.h>
#include <stdlib.h>

#define size 10

int front = -1, rear = -1;

int q[size];

void enqueue(int x)
{
    if((rear + 1) % size == front)
    {
        printf("Queue OverFlow!\n");
    }
    else if(front == -1)
    {
        front = rear = 0;
        q[rear] = x;
    }
    else
    {
        rear = (rear + 1) % size;
        q[rear] = x;
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
        printf("Queue Empty!");
        return;
    }

    printf("Circular Queue: ");
    
    int i = front;

    while(i != rear)
    {
        printf("%d ", q[i++]);

        if(i == size)
            i = 0;
    }

    printf("%d\n", q[i]);
}

int main()
{
    enqueue(1);
    enqueue(2);
    enqueue(3);

    display();

    dequeue();

    display();
}
