
#include <stdio.h>
#include <stdlib.h>
struct node *create(struct node *start)
{
    int i, n, data;
    printf("Enter no of nodes:");
    scanf("%d", &n);

    start = NULL;
    if (n == 0)
        return start;
    printf("Enter element to enter:");
    scanf("%d", &data);
    start = add_beg(start, data);
    for (i = 2; i <= n; i++)
    {
        printf("enter to insert=\n");
        scanf("%d", &data);
        start = add_end(start, data);
    }
    return start;
}
