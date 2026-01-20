#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size1 = 5, size2 = 5;

    int* arr1 = (int*) malloc(size1 * sizeof(int));

    int* arr2 = (int*) calloc(size2, sizeof(int));

    int choice = 1;

    while(choice)
    {
        printf("\nenter 1 to insert values in array 1\n");
        printf("enter 2 to insert values in array 2\n");
        printf("enter 3 to display array 1\n");
        printf("enter 4 to display array 2\n");
        printf("enter 5 to realloc array 1\n");
        printf("enter 6 to realloc array 2\n");
        printf("enter chocie: ");

        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("\nenter values: ");
                
                for(int i=0; i<size1; i++)
                {
                    scanf("%d", &arr1[i]);
                }
                break;

            case 2:
                printf("\nenter values: ");

                for(int i=0; i<size2; i++)
                {
                    scanf("%d", &arr2[i]);
                }
                break;

            case 3:
                printf("\narray 1 values: ");

                for(int i=0; i<size1; i++)
                {
                    printf("%d ", arr1[i]);
                }

                printf("\n");
                break;

            case 4:
                printf("\narray 2 values: ");

                for(int i=0; i<size2; i++)
                {
                    printf("%d ", arr2[i]);
                }

                printf("\n");
                break;

            case 5:
                printf("\nenter the new size: ");
                scanf("%d", &size1);
                
                arr1 = (int*) realloc(arr1, size1*sizeof(int));
                break;

            case 6:
                printf("\nenter the new size: ");
                scanf("%d", &size2);
                
                arr2 = (int*) realloc(arr2, size2*sizeof(int));
                break;

            default: printf("Wrong Input !\n");
        }

        printf("\ndo u want to continue?\n");
        printf("1: yes\n2: no\nchoice: ");
        scanf("%d", &choice);

        choice = (choice == 1) ? 1 : 0;
    }

    free(arr1);

    free(arr2);

    return 0;
}
