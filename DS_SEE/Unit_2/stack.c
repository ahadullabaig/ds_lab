#include <stdio.h>
#include <stdlib.h>

#define size 10

int* stack;

int top = -1;

void push(int x)
{
    if(top == size-1)
    {
        printf("Stack OverFlow!\n");
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
        printf("Stack UnderFlow!\n");
    }
    else
    {
        --top;
    }
}

void display()
{
    if(top == -1)
    {
        printf("Stack Empty!\n");
        return;
    }

    printf("Stack:\n");

    for(int i=top; i>=0; i--)
        printf("%d\n", stack[i]);
}

int main()
{
    stack = (int*) malloc(size*sizeof(int));

    push(10);
    push(20);
    push(30);

    display();

    pop();

    display();
}
