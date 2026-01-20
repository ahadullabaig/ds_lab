#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    struct Node* left;
    int data;
    struct Node* right;
} Node;

Node* createNode(int data)
{
    Node* node = (Node*) malloc(sizeof(Node));

    node->left = NULL;
    node->data = data;
    node->right = NULL;

    return node;
}

Node* insert(Node* root, int data)
{
    if(root == NULL) // Base Case: If the spot is empty, put the new node here!
    {
        return createNode(data);
    }

    if(data < root -> data)
    {
        root -> left = insert(root -> left, data);
    }
    else if(data > root -> data)
    {
        root -> right = insert(root -> right, data);
    }

    return root;
}

void inorder(Node* root) // Left -> Root -> Right
{
    if(root == NULL) return;

    inorder(root->left);

    printf("%d ", root->data);

    inorder(root->right);
}

void preorder(Node* root) // Root -> Left -> Right
{
    if(root == NULL) return;

    printf("%d ", root->data);

    preorder(root->left);      

    preorder(root->right);     
}

void postorder(Node* root) // Left -> Right -> Root
{
    if(root == NULL) return;

    postorder(root->left);     

    postorder(root->right);    

    printf("%d ", root->data); 
}

int main()
{
    Node* root = NULL;

    int choice = 1;

    while(choice)
    {
        printf("\nenter 1 to insert\n");
        printf("enter 2 for preorder traversal\n");
        printf("enter 3 for inorder traversal\n");
        printf("enter 4 for postorder traversal\n");
        printf("choice: ");

        scanf("%d", &choice);

        switch(choice)
        {
            int x;

            case 1:
                printf("\nenter the number: ");
                scanf("%d", &x);
                root = insert(root, x);
                break;

            case 2:
                printf("Preorder: ");
                preorder(root);
                printf("\n");
                break;

            case 3:
                printf("Inorder: ");
                inorder(root);
                printf("\n");
                break;

            case 4:
                printf("Postorder: ");
                postorder(root);
                printf("\n");
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
