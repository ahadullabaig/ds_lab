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
    else
    {
        root -> right = insert(root -> right, data);
    }

    return root;
}

Node* search(Node* root, int key)
{
    if(root == NULL || root->data == key)
    {
        return root; // Returns the Node if found, or NULL if not
    }

    if(key < root->data)
    {
        return search(root->left, key);
    }
    else
    {
        return search(root->right, key);
    }
}

// Helper function to find the smallest node in a subtree
Node* minValueNode(Node* node)
{
    Node* current = node;

    // Loop down to find the leftmost leaf
    while (current && current->left != NULL)
        current = current->left;

    return current;
}

Node* deleteNode(Node* root, int key)
{
    // Base Case: Empty tree
    if (root == NULL) return root;

    // 1. SEARCH for the node to delete
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);

    // 2. IF FOUND (root->data == key), delete it
    else
    {
        // Case 1 & 2: Node with only one child or no child
        if (root->left == NULL)
        {
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        // Case 3: Node with two children
        Node* temp = minValueNode(root->right);

        root->data = temp->data;

        root->right = deleteNode(root->right, temp->data);
    }
    
    return root;
}

int main()
{
    Node* root = NULL;
    
    int choice = 1;

    while(choice)
    {
        printf("\nenter 1 to insert\n");
        printf("enter 2 to search\n");
        printf("enter 3 to delete\n");
        printf("choice: ");

        scanf("%d", &choice);

        switch(choice)
        {
            int x;
            Node* found;

            case 1:
                printf("\nenter the number to insert: ");
                scanf("%d", &x);
                root = insert(root, x);
                break;

            case 2:
                printf("\nenter the number to search: ");
                scanf("%d", &x);
                found = search(root, x);
                if(found)
                    printf("Element %d found in tree.\n", x);
                else
                    printf("Element %d not found.\n", x);
                break;

            case 3:
                printf("\nenter the number to delete: ");
                scanf("%d", &x);
                root = deleteNode(root, x);
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
