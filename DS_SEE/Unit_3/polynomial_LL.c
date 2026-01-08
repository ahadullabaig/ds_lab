#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int coeff;
    int exp;
    struct Node* next;
} Node;

Node* createNode()
{
    Node* node = (Node*) malloc(sizeof(Node));

    node -> coeff = 0;
    node -> exp = 0;
    node -> next = NULL;

    return node;
}

Node* addPoly(Node* p1, Node* p2)
{
    Node* result = NULL;
    Node* temp = NULL;

    while(p1 != NULL && p2 != NULL)
    {
        Node* node = createNode();

        if(p1 -> exp > p2 -> exp)
        {
            node -> coeff = p1 -> coeff;
            node -> exp = p1 -> exp;

            p1 = p1 -> next;
        }
        else if(p2 -> exp > p1 -> exp)
        {
            node -> coeff = p2 -> coeff;
            node -> exp = p2 -> exp;

            p2 = p2 -> next;
        }
        else
        {
            node -> coeff = p1 -> coeff + p2 -> coeff;
            node -> exp = p1 -> exp;

            p1 = p1 -> next;
            p2 = p2 -> next;
        }

        if(result == NULL)
        {
            result = node;
            temp = node;
        }
        else
        {
            temp -> next = node;
            temp = node;
        }
    }

    while(p1 != NULL)
    {
        Node* node = createNode();

        node -> coeff = p1 -> coeff;
        node -> exp = p1 -> exp;

        temp -> next = node;
        temp = node;

        p1 = p1 -> next;
    }

    while(p2 != NULL)
    {
        Node* node = createNode();

        node -> coeff = p2 -> coeff;
        node -> exp = p2 -> exp;

        temp -> next = node;
        temp = node;

        p2 = p2 -> next;
    }

    return result;
}
