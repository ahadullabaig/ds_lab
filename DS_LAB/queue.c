#include <stdio.h>

#define size 5

int q[size];

int front = -1, rear = -1;

void enqueue(int x)
{
    if(front == -1)
    {
        front = rear = 0;
        q[rear] = x;
    }
    else if(rear == size - 1)
    {
        printf("\nQueue OverFlow!\n");
    }
    else 
    {
        q[++rear] = x;
    }
}

void dequeue()
{
    if(front == -1)
    {
        printf("\nQueue UnderFlow!\n");
    }
    else if(front == rear)
    {
        printf("\ndequeue %d from queue\n", q[front]);
        front = rear = -1;
    }
    else
    {
        printf("\ndequeue %d from queue\n", q[front]);
        front++;
    }
}

void display()
{
    printf("\nQueue: ");

    for(int i=front; i<=rear; i++)
    {
        printf("%d ", q[i]);
    }

    printf("\n");
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
