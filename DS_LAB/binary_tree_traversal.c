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
    // Base Case: If the spot is empty, put the new node here!
    if(root == NULL)
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

// Right -> Left -> Root
void inorder(Node* root)
{
    if(root == NULL) return;

    inorder(root->left);

    printf("%d ", root->data);

    inorder(root->right);
}

// Root -> Left -> Right
void preorder(Node* root)
{
    if(root == NULL) return;

    printf("%d ", root->data); // Visit Root
    preorder(root->left);      // Visit Left
    preorder(root->right);     // Visit Right
}

// Left -> Right -> Root
void postorder(Node* root)
{
    if(root == NULL) return;

    postorder(root->left);     // Visit Left
    postorder(root->right);    // Visit Right
    printf("%d ", root->data); // Visit Root
}

int main()
{
    Node* root = NULL;
    root = insert(root, 50); 
    insert(root, 30); insert(root, 20); insert(root, 40);
    insert(root, 70); insert(root, 60); insert(root, 80);

    printf("Preorder: ");
    preorder(root); 
    printf("\n");

    printf("Inorder: ");
    inorder(root); 
    printf("\n");

    printf("Postorder: ");
    postorder(root); 
    printf("\n");
}
