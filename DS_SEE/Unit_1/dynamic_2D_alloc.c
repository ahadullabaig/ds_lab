#include <stdio.h>
#include <stdlib.h>

void accept(int **a, int r, int c)
{
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            scanf("%d", &a[i][j]);
}

void display(int **a, int r, int c)
{
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
}

int main()
{
    int **a;
    int r, c;

    scanf("%d %d", &r, &c);

    a = (int **)malloc(r * sizeof(int *));
    for(int i = 0; i < r; i++)
        a[i] = (int *)malloc(c * sizeof(int));

    accept(a, r, c);
    display(a, r, c);

    for(int i = 0; i < r; i++)
        free(a[i]);
    free(a);

    return 0;
}
