#include <stdio.h>
int main()
{
    // NAME: Sahil Singh
    // ROLL: 2005535
    int i, j, r1, c1, c = 0, p = 1, s = 0;
    printf("Enter number of rows: ");
    scanf("%d", &r1);
    printf("Enter number of columns: ");
    scanf("%d", &c1);

    int a[r1][c1];
    printf("Enter Matrix:\n");
    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c1; j++)
        {
            scanf("%d", &a[i][j]);
            if (a[i][j] > 0 || a[i][j] < 0)
                c = c + 1;
        }
    }
    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c1; j++)
        {
            if (i == j)
                p = p * a[i][j];
        }
    }
    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c1; j++)
        {
            if (j > i)
                s = s + a[i][j];
        }
    }
    printf("\nMatrix Formed:\n");
    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c1; j++)
        {
            printf("%d ", a[i][j]);
            if (j == c1 - 1)
                printf("\n");
        }
    }
    printf("\nNumber of Non Zero Elements: %d\n", c);
    printf("Sum of Elements above Leading Diagonal: %d\n", s);
    printf("Elements Below Leading Diagonal: ");
    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c1; j++)
        {
            if (j < i)
                printf("%d ", a[i][j]);
        }
    }
    printf("\nProduct of Diagonal: %d\n", p);
    return 0;
}
