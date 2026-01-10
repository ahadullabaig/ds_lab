#include <stdio.h>
#include <stdlib.h>

#define size 10

int top1 = -1, top2 = size;

int stack[size];

void push(int x, int choice)
{
    if(choice == 1)
    {
        if(top1+1 != top2)
            stack[++top1] = x;
        else
            printf("Stack OverFlow!");
    }
    else if(choice == 2)
    {
        if(top1+1 != top2)
            stack[--top2] = x;
        else
            printf("Stack OverFlow!");
    }
}

void pop(int choice)
{
    if(choice == 1)
    {
        if(top1 != -1)
            top1--;
        else
            printf("Stack UnderFlow!");
    }
    else if(choice == 2)
    {
        if(top2 != size)
            top2++;
        else
            printf("Stack UnderFlow!");
    }
}

void peek(int choice)
{
    if(choice == 1)
    {
        if(top1 != -1)
            printf("Top Element: %d\n", stack[top1]);
        else
            printf("Stack Empty!");
    }
    else if(choice == 2)
    {
        if(top2 != size)
            printf("Top Element: %d\n", stack[top2]);
        else
            printf("Stack Empty!");
    }
}

void display(int choice)
{
    if(choice == 1)
    {
        printf("\nStack 1:\n");
        for(int i=top1; i>=0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
    else if(choice == 2)
    {
        printf("Stack 2:\n");
        for(int i=top2; i<size; i++)
        {
            printf("%d\n", stack[i]);
        }
    }   
}

int main()
{
    int choice = 0;

    while(choice == 0)
    {
        printf("enter 1 to use stack 1\n");
        printf("enter 2 to use stack 2\n");
        printf("enter 3 to exit\n");
        printf("choice: ");
        scanf("%d", &choice);

        if(choice == 3)
        {
            return 0;
        }

        if(choice != 1 && choice != 2 && choice != 3)
        {
            printf("wrong input!\n");
            choice = 0;
            continue;
        }

        int action;
        printf("\nenter 1 to push\n");
        printf("enter 2 to pop\n");
        printf("enter 3 to peek\n");
        printf("enter 4 to display\n");
        printf("choice: ");
        scanf("%d", &action);

        switch(action)
        {
            case 1:
                int x;
                printf("\nenter value to push: ");
                scanf("%d", &x);
                push(x, choice);
                display(choice);
                break;

            case 2:
                pop(choice);
                display(choice);
                break;

            case 3:
                peek(choice);
                display(choice);
                break;

            case 4:
                display(choice);
                break;

            default: printf("wrong action input\n");
        }

        choice = 0;
    }
}
