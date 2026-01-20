#include <stdio.h>

int main()
{
    int x = 0, y = 0;

    int* p1 = &x;

    int* p2 = &y;

    int choice = 1;

    while(choice)
    {
        printf("\nenter 1 to insert the value of x\n");
        printf("enter 2 to insert the value of y\n");
        printf("enter 3 to display the values of x & y\n");
        printf("enter 4 to add the values of x & y\n");
        printf("enter your choice: ");

        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("\nenter the value of x: ");
                scanf("%d", p1);
                break;

            case 2:
                printf("\nenter the value of y: ");
                scanf("%d", p2);
                break;

            case 3:
                printf("\nvalue of x: %d\n", *p1);
                printf("value of y: %d\n", *p2);
                break;

            case 4:
                int result = *p1 + *p2;
                printf("\nx + y = %d\n", result);
                break;

            default: printf("Wrong Input ! \n");
        }

        printf("\ndo u want to continue?\n");
        printf("1: yes\n2: no\nchoice: ");
        scanf("%d", &choice);

        choice = (choice == 1) ? 1 : 0;
    }

    return 0;
}
