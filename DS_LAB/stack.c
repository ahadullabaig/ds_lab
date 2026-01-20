#include <stdio.h>

#define size 5

int stack[size];

int top = -1;

void push(int x)
{
    if(top == size-1)
    {
        printf("\nStack OverFlow!\n");
    }
    else
    {
        stack[++top] = x;
    }
}

void pop()
{
    if(top == -1)
    {
        printf("\nStack UnderFlow!\n");
    }
    else
    {
        printf("\npopping %d from stack\n", stack[top]);
        top--;
    }
}

void display()
{
    printf("\nStack:\n");

    for(int i=top; i>=0; i--)
    {
        printf("%d\n", stack[i]);
    }
}

int main()
{
    int choice = 1;

    while(choice)
    {
        printf("\nenter 1 to push\n");
        printf("enter 2 to pop\n");
        printf("enter 3 to display\n");
        printf("choice: ");

        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                int x;
                printf("\nenter the number: ");
                scanf("%d", &x);
                push(x);
                break;

            case 2:
                pop();
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
