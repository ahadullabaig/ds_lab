#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int hashTable[SIZE];

// Initialize all slots to -1 (indicating empty)
void init()
{
    for(int i = 0; i < SIZE; i++)
        hashTable[i] = -1;
}

void insert(int key)
{
    int index = key % SIZE;
    int i = index;

    // Linear Probing: Find the next empty slot
    while(hashTable[i] != -1)
    {
        // Check if the key already exists (optional, prevents duplicates)
        if(hashTable[i] == key)
        {
            printf("Key %d already exists\n", key);
            return;
        }

        i = (i + 1) % SIZE;

        // If we wrapped around and came back to start, table is full
        if(i == index)
        {
            printf("Hash Table is Full!\n");
            return;
        }
    }

    hashTable[i] = key;
    printf("Inserted %d at index %d\n", key, i);
}

void search(int key)
{
    int index = key % SIZE;
    int i = index;

    // Probe to find the key
    while(hashTable[i] != -1)
    {
        if(hashTable[i] == key)
        {
            printf("Key %d found at index %d\n", key, i);
            return;
        }

        i = (i + 1) % SIZE;

        // If we wrapped around, the key isn't here
        if(i == index)
            break;
    }

    printf("Key %d not found\n", key);
}

void display()
{
    printf("\nHash Table:\n");
    for(int i = 0; i < SIZE; i++)
    {
        if(hashTable[i] != -1)
            printf("Index %d: %d\n", i, hashTable[i]);
        else
            printf("Index %d: --\n", i);
    }
    printf("\n");
}

int main()
{
    init();

    int choice = 1;

    while(choice)
    {
        printf("\nenter 1 to insert\n");
        printf("enter 2 to search\n");
        printf("enter 3 to display\n");
        printf("choice: ");

        scanf("%d", &choice);

        switch(choice)
        {
            int x;

            case 1:
                printf("\nenter the number: ");
                scanf("%d", &x);
                insert(x);
                break;

            case 2:
                printf("\nenter the number: ");
                scanf("%d", &x);
                search(x);
                break;

            case 3:
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
