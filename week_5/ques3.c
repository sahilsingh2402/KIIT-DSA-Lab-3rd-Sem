#include <stdio.h>
#include <stdlib.h>

typedef struct Node_535
{
    int coff_535;
    int expo_535;
    struct Node_535 *link_535;
} Node_535;

void push_535(Node_535 **, int, int);
void display_535(Node_535 *);
Node_535 *add_polynomial_535(Node_535 *, Node_535 *);

int main()
{
    Node_535 *l1 = NULL;
    Node_535 *l2 = NULL;
    char chos_535;
    printf("Enter first polynomial:\n");
    do
    {
        int expo_535, coff_535;
        printf("Enter coffecient and exponent: ");
        scanf("%d%d", &coff_535, &expo_535);
        push_535(&l1, coff_535, expo_535);
        printf("Insert another element?: ");
        scanf(" %c", &chos_535);
    } while (chos_535 == 'y' || chos_535 == 'Y');
    printf("\nEnter second polynomial:\n");
    do
    {
        int expo_535, coff_535;
        printf("Enter coffecient and exponent: ");
        scanf("%d%d", &coff_535, &expo_535);
        push_535(&l2, coff_535, expo_535);
        printf("Insert another element?: ");
        scanf(" %c", &chos_535);
    } while (chos_535 == 'y' || chos_535 == 'Y');
    Node_535 *l3 = add_polynomial_535(l1, l2);
    printf("\nThe resultant polynomial is:\n");
    display_535(l3);
    return 0;
}

void push_535(Node_535 **start_535, int coff_535, int expo_535)
{
    /*Making the new node*/
    Node_535 *temp_535 = (Node_535 *)malloc(sizeof(Node_535));
    temp_535->coff_535 = coff_535;
    temp_535->expo_535 = expo_535;
    temp_535->link_535 = NULL;
    /*Connecting the new node*/
    if (!*start_535)
    {
        *start_535 = temp_535;
        return;
    }
    Node_535 *tempStart_535 = *start_535;
    //Travel to last node
    while (tempStart_535->link_535)
        tempStart_535 = tempStart_535->link_535;
    tempStart_535->link_535 = temp_535;
    //Insert after last node
}

void display_535(Node_535 *start_535)
{
    if (!start_535)
        printf("0");
    while (start_535)
    {
        if (start_535->coff_535 > 0)
            printf("+");
        printf("%dx^%d", start_535->coff_535, start_535->expo_535);
        start_535 = start_535->link_535;
    }
    printf("\n");
}

Node_535 *add_polynomial_535(Node_535 *list1_535, Node_535 *list2_535)
{
    Node_535 *addList_535 = NULL;
    while (list1_535 && list2_535)
    {
        if (list1_535->expo_535 > list2_535->expo_535)
        {
            push_535(&addList_535, list1_535->coff_535, list1_535->expo_535);
            list1_535 = list1_535->link_535;
            continue;
        }
        else if (list1_535->expo_535 < list2_535->expo_535)
        {
            push_535(&addList_535, list2_535->coff_535, list2_535->expo_535);
            list2_535 = list2_535->link_535;
            continue;
        }
        if (list1_535->coff_535 + list2_535->coff_535)
        {
            push_535(&addList_535, list2_535->coff_535 + list1_535->coff_535, list2_535->expo_535);
            list2_535 = list2_535->link_535;
            list1_535 = list1_535->link_535;
        }
    }
    while (list1_535)
    {
        push_535(&addList_535, list1_535->coff_535, list1_535->expo_535);
        list1_535 = list1_535->link_535;
    }
    while (list2_535)
    {
        push_535(&addList_535, list2_535->coff_535, list2_535->expo_535);
        list2_535 = list2_535->link_535;
    }
    return addList_535;
}

