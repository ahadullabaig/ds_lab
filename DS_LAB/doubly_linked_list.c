#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    struct Node* prev;
    int data;
    struct Node* next;
} Node;

Node* head = NULL;

Node* createNode(int data)
{
    Node* node = (Node*) malloc(sizeof(Node));

    node -> prev = NULL;
    node -> data = data;
    node -> next = NULL;

    return node;
}

void insBeg(int data)
{
    Node* node = createNode(data);

    if(head == NULL)
    {
        head = node;
        return;
    }

    head -> prev = node;
    node -> next = head;
    head = node;
}

void insEnd(int data)
{
    Node* node = createNode(data);

    if(head == NULL)
    {
        head = node;
        return;
    }

    Node* temp = head;

    while(temp -> next != NULL)
        temp = temp -> next;

    temp -> next = node;
    node -> prev = temp;
}

void insKey(int data, int key)
{
    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    if(head -> data == key)
    {
        insBeg(data);
        return;
    }

    Node* temp = head;

    while(temp -> data != key && temp -> next != NULL)
        temp = temp -> next;

    if(temp -> data != key)
    {
        printf("Key not found!\n");
        return;
    }

    Node* node = createNode(data);

    node -> prev = temp -> prev;
    node -> next = temp;

    temp -> prev -> next = node;
    temp -> prev = node;
}

void delBeg()
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

    head = temp -> next;
    head -> prev = NULL;

    free(temp);
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

    while(temp -> next != NULL)
        temp = temp -> next;

    temp -> prev -> next = NULL;

    free(temp);
}

void delKey(int key)
{
    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    if(head -> data == key)
    {
        delBeg();
        return;
    }

    Node* temp = head;

    while(temp -> data != key && temp -> next != NULL)
        temp = temp -> next;

    if(temp -> data != key)
    {
        printf("Key not found!\n");
        return;
    }

    temp -> prev -> next = temp -> next;

    if(temp -> next != NULL)
        temp -> next -> prev = temp -> prev;

    free(temp);
}

void display()
{
    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    Node* temp = head;

    printf("Doubly Linked List: ");

    while(temp -> next != NULL)
    {
        printf("%d <-> ", temp -> data);
        temp = temp -> next;
    }

    printf("%d <-> NULL\n", temp -> data);
}

int main()
{
    insBeg(1);
    insEnd(2);
    insBeg(0);

    display();

    delBeg();
    
    display();

    insKey(4, 2);

    display();

    delKey(4);

    display();
}
