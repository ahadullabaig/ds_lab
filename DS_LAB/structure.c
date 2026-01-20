#include <stdio.h>

#define size 3

struct Student 
{
    char name[20];
    char USN[10];
    int sem;
} s[size];

void accept()
{
    for(int i=0; i<size; i++)
    {
        printf("\nenter name: ");
        scanf("%s", s[i].name);

        printf("enter USN: ");
        scanf("%s", s[i].USN);

        printf("enter sem: ");
        scanf("%d", &s[i].sem);
    }
}

void display()
{
    for(int i=0; i<size; i++)
    {
        printf("\nName: %s\n", s[i].name);
        
        printf("USN: %s\n", s[i].USN);
        
        printf("Semester: %d\n", s[i].sem);
    }
}

int main()
{
    int choice = 1;

    while(choice)
    {
        printf("\nenter 1 to accept details\n");
        printf("enter 2 to view details\n");
        printf("choice: ");

        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                accept();
                break;

            case 2:
                display();
                break;

            default: printf("Wrong Input!\n");
        }

        printf("\ndo u want to continue?\n");
        printf("1: yes\n2: no\nchoice: ");
        scanf("%d", &choice);

        choice = (choice == 1) ? 1 : 0;
    }

    return 0;
}
