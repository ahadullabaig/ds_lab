#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    struct Node* prev;
    int data;
    struct Node* next;
} Node;

Node* head = NULL;

Node* createNode(int x)
{
    Node* node = (Node*) malloc(sizeof(Node));

    node -> prev = NULL;
    node -> data = x;
    node -> next = NULL;

    return node;
}

void insBeg(int x)
{
    Node* node = createNode(x);

    if(head == NULL)
    {
        head = node;
        return;
    }

    node -> next = head;

    head -> prev = node;

    head = node;
}

void delEnd()
{
    if(head == NULL)
    {
        return;
    }

    if(head -> next == NULL)
    {
        free(head);
        head = NULL;
        return;
    }

    Node* temp = head;

    while(temp -> next != NULL)
    {
        temp = temp -> next;
    }

    temp -> prev -> next = NULL;

    free(temp);
}
