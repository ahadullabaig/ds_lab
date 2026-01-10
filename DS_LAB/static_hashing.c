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

    // 1. Insertion
    insert(10); // Hash: 0 -> Index 0
    insert(20); // Hash: 0 -> Collision -> Index 1
    insert(30); // Hash: 0 -> Collision -> Index 2
    insert(4);  // Hash: 4 -> Index 4
    insert(12); // Hash: 2 -> Collision (30 is there) -> Index 3

    display();

    // 2. Searching
    search(20); // Should find at index 1
    search(99); // Should not find

    return 0;
}

