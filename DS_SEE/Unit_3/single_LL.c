#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
} Node;

Node* head = NULL;

Node* createNode(int x)
{
    Node* node = (Node*) malloc(sizeof(Node));

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
    head = node;
}

void insAfter(int x, int key)
{
    if(head == NULL)
    {
        printf("Linked List Empty!\n");
        return;
    }

    Node* temp = head;

    while(temp != NULL)
    {
        if(temp -> data == key)
        {
            Node* node = createNode(x);

            node -> next = temp -> next;

            temp -> next = node;

            return;
        }

        temp = temp -> next;
    }

    printf("Key Not Found!\n");
}

void delEnd()
{
    if(head == NULL)
        return;

    if(head -> next == NULL)
    {
        free(head);
        head = NULL;
        return;
    }

    Node* temp = head;

    while(temp -> next -> next != NULL)
    {
        temp = temp -> next;
    }

    Node* last = temp -> next;

    temp -> next = NULL;

    free(last);
}
