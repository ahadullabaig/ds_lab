#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
} Node;

Node* head = NULL;

Node* createNode(int data)
{
    Node* node = (Node*) malloc(sizeof(Node));

    node -> data = data;
    node -> next = NULL;

    return node;
}

void insBeg(int data)
{
    Node* node = createNode(data);

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
    {
        temp = temp -> next;
    }

    temp -> next = node;
}

void insKey(int data, int key)
{
    if(head == NULL)
    {
        printf("\nList Empty!\n");
        return;
    }

    Node* temp = head;

    while(temp != NULL)
    {
        if(temp -> data == key)
        {
            Node* node = createNode(data);

            node -> next = temp -> next;

            temp -> next = node;

            return;
        }

        temp = temp -> next;
    }

    printf("\nKey Not Found !\n");
}

void delBeg()
{
    if(head == NULL)
    {
        return;
    }

    Node* temp = head;

    head = head -> next;

    free(temp);
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

    while(temp -> next -> next != NULL)
    {
        temp = temp -> next;
    }

    Node* last = temp -> next;

    temp -> next = NULL;

    free(last);
}

void delKey(int key)
{
    if(head == NULL)
    {
        printf("\nList Empty!\n");
        return;
    }

    if(head -> data == key)
    {
        Node* temp = head;

        head = head -> next;

        free(temp);

        return;
    }

    Node* temp = head;

    while(temp -> next != NULL)
    {
        if(temp -> next -> data == key)
        {
            Node* toDelete = temp -> next;

            temp -> next = toDelete -> next;

            free(toDelete);
            
            return;
        }

        temp = temp -> next;
    }

    printf("\nKey Not Found !\n");
}

void display()
{
    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    Node* temp = head;

    printf("Singly Linked List: ");

    while(temp != NULL)
    {
        printf("%d -> ", temp -> data);
        temp = temp -> next;
    }

    printf("NULL\n");
}

int main()
{
    int choice = 1;

    while(choice)
    {
        printf("\nenter 1 to insert at beginning\n");
        printf("enter 2 to insert at end\n");
        printf("enter 3 to insert after a key\n");
        printf("enter 4 to delete at beginning\n");
        printf("enter 5 to delete at end\n");
        printf("enter 6 to delete a key\n");
        printf("enter 7 to display\n");
        printf("choice: ");

        scanf("%d", &choice);

        switch(choice)
        {
            int x, k;

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
                printf("\nenter the number to insert: ");
                scanf("%d", &x);
                printf("enter the key after which to insert: ");
                scanf("%d", &k);
                insKey(x, k);
                break;

            case 4:
                delBeg();
                break;

            case 5:
                delEnd();
                break;

            case 6:
                printf("\nenter the key to delete: ");
                scanf("%d", &k);
                delKey(k);
                break;

            case 7:
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
