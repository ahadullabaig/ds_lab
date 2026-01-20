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
    int choice = 1;

    while(choice)
    {
        printf("\nenter 1 to insert at beginning\n");
        printf("enter 2 to insert at end\n");
        printf("enter 3 to delete at beginning\n");
        printf("enter 4 to delete at end\n");
        printf("enter 5 to display\n");
        printf("choice: ");

        scanf("%d", &choice);

        switch(choice)
        {
            int x;

            case 1:
                printf("\nenter the number: ");
                scanf("%d", &x);
                insBeg(x);
                break;

            case 2:
                printf("\nenter the number: ");
                scanf("%d", &x);
                insEnd(x);
                break;

            case 3:
                delBeg();
                break;

            case 4:
                delEnd();
                break;

            case 5:
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
