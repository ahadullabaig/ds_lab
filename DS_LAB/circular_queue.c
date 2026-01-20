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
        printf("%d ", q[i]);

        i = (i+1) % size;
    }

    printf("%d\n", q[i]);
}

int main()
{
    int choice = 1;

    while(choice)
    {
        printf("\nenter 1 to enqueue\n");
        printf("enter 2 to dequeue\n");
        printf("enter 3 to display\n");
        printf("choice: ");

        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                int x;
                printf("\nenter the number: ");
                scanf("%d", &x);
                enqueue(x);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            default: printf("Wrong Input !\n");
        }

        printf("\ndo u want to continue?\n");
        printf("1: yes\n2: no\nchoice: ");
        scanf("%d", &choice);

        choice = (choice == 1) ? 1 : 0;
    }

    return 0;
}
