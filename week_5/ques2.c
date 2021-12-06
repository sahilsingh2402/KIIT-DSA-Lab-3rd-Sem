#include <stdio.h>
#include <stdlib.h>

typedef struct Node_535
{
    int data_535;
    struct Node_535 *link_535;
} Node_535;

void push_535(Node_535 **, int);
void disp_535(Node_535 *);
struct Node_535 *mergeTwoLists_535(Node_535 *, Node_535 *);

int main()
{
    Node_535 *l1 = NULL;
    Node_535 *l2 = NULL;
    char chos_535;

    printf("Insert elements in list 1:\n");
    do
    {
        int data_535;
        printf("Enter a element: ");
        scanf("%d", &data_535);
        push_535(&l1, data_535);
        printf("Insert another element?: ");
        scanf(" %c", &chos_535);
    } while (chos_535 == 'y' || chos_535 == 'Y');

    printf("\nInsert elements in list 2:\n");
    do
    {
        int data_535;
        printf("Enter a element: ");
        scanf("%d", &data_535);
        push_535(&l2, data_535);
        printf("Insert another element?: ");
        scanf(" %c", &chos_535);
    } while (chos_535 == 'y' || chos_535 == 'Y');

    Node_535 *l3 = mergeTwoLists_535(l1, l2);
    printf("\nMerged list:\n");
    disp_535(l3);
    return 0;
}

void push_535(Node_535 **head_535, int n)
{
    struct Node_535 *temp_535 = (struct Node_535 *)malloc(sizeof(struct Node_535));
    temp_535->data_535 = n;
    temp_535->link_535 = NULL;
    if (*head_535 == NULL)
    {
        *head_535 = temp_535;
        return;
    }
    Node_535 *ptr = *head_535;
    while (ptr->link_535 != NULL)
    {
        ptr = ptr->link_535;
    }
    ptr->link_535 = temp_535;
}

void disp_535(Node_535 *head_535)
{
    while (head_535 != NULL)
    {
        printf("%i->", head_535->data_535);
        head_535 = head_535->link_535;
    }
    printf("\b\b \n");
}

Node_535 *mergeTwoLists_535(Node_535 *l1, Node_535 *l2)
{
    if (!l1)
        return l2;
    else if (!l2)
        return l1;

    Node_535 *l3 = NULL;
    Node_535 *copyOfl3_535;

    while (l2 && l1)
    {
        Node_535 *temp_535 = (Node_535 *)malloc(sizeof(Node_535));
        temp_535->link_535 = NULL;

        if (l1->data_535 <= l2->data_535)
        {
            temp_535->data_535 = l1->data_535;
            l1 = l1->link_535;
        }
        else
        {
            temp_535->data_535 = l2->data_535;
            l2 = l2->link_535;
        }

        if (!l3)
            copyOfl3_535 = l3 = temp_535;
        copyOfl3_535->link_535 = temp_535;
        copyOfl3_535 = copyOfl3_535->link_535;

        if (!l1)
            copyOfl3_535->link_535 = l2;
        else if (!l2)
            copyOfl3_535->link_535 = l1;
    }
    return l3;
}

