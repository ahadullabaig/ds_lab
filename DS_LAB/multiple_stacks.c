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
            printf("\nStack OverFlow!");
    }
    else if(choice == 2)
    {
        if(top1+1 != top2)
            stack[--top2] = x;
        else
            printf("\nStack OverFlow!");
    }
}

void pop(int choice)
{
    if(choice == 1)
    {
        if(top1 != -1)
            top1--;
        else
            printf("\nStack UnderFlow!");
    }
    else if(choice == 2)
    {
        if(top2 != size)
            top2++;
        else
            printf("\nStack UnderFlow!");
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
        printf("\n");
    }
    else if(choice == 2)
    {
        printf("Stack 2:\n");
        for(int i=top2; i<size; i++)
        {
            printf("%d\n", stack[i]);
        }
        printf("\n");
    }   
}

int main()
{
    int choice = 1;

    while(choice)
    {
        printf("\nenter 1 to use stack 1\n");
        printf("enter 2 to use stack 2\n");
        printf("enter 3 to exit\n");
        printf("choice: ");
        scanf("%d", &choice);

        if(choice == 3)
        {
            break;
        }

        if(choice != 1 && choice != 2 && choice != 3)
        {
            printf("\nwrong input!\n");
            choice = 1;
            continue;
        }

        int action;
        printf("\nenter 1 to push\n");
        printf("enter 2 to pop\n");
        printf("enter 3 to display\n");
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
                display(choice);
                break;

            default: printf("\nwrong action input\n");
        }

        choice = 1;
    }
}
