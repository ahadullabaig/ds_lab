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

void inorder(Node* root)
{
    if(root == NULL) return;

    inorder(root->left);

    printf("%d ", root->data);

    inorder(root->right);
}

int main()
{
    Node* root = NULL;
    root = insert(root, 50); 
    insert(root, 30); insert(root, 20); insert(root, 40);
    insert(root, 70); insert(root, 60); insert(root, 80);

    printf("Original: ");
    inorder(root); 
    printf("\n");

    // Test Deletion
    root = deleteNode(root, 20); // Delete Leaf
    root = deleteNode(root, 30); // Delete Node with 1 child
    root = deleteNode(root, 50); // Delete Root (2 children)

    printf("After Deletion: ");
    inorder(root);
    printf("\n");
}
