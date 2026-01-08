#include <stdio.h>
#include <stdlib.h>

typedef struct Stack
{
    int data;
    struct Stack* next;
} Stack;

Stack* top = NULL;

Stack* createNode(int x)
{
    Stack* node = (Stack*) malloc(sizeof(Stack));

    node -> data = x;
    node -> next = NULL;

    return node;
}

void push(int x)
{
    Stack* node = createNode(x);

    if(top == NULL)
    {
        top = node;
        return;
    }

    node -> next = top;
    top = node;
}

void pop()
{
    if(top == NULL)
        return;

    Stack* temp = top;

    top = top -> next;

    free(temp);
}

void peek()
{
    if(top == NULL)
    {
        printf("Stack Empty!\n");
        return;
    }

    printf("Top Element: %d\n", top -> data);
}

void display()
{
    if(top == NULL)
    {
        printf("Stack Empty!\n");
        return;
    }

    printf("Stack:\n");

    Stack* temp = top;

    while(temp != NULL)
    {
        printf("%d\n", temp -> data);

        temp = temp -> next;
    }
}
