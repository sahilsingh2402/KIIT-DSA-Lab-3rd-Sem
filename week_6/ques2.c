/*Write a menu driven program to perform the following operations in a circular linked list by using
suitable user defined functions for each case.*/
#include <stdio.h>
#include <stdlib.h>
typedef struct Node_535
{
    int data_535;
    struct Node_535 *link_535;
} Node_535;
void push_535(Node_535 **, int);
void display_535(Node_535 *);
void push_first_535(Node_535 **, int);
void pop_first_535(Node_535 **);
int main()
{
    Node_535 *list_535 = NULL;
    int choice_535, value_535;
    do
    {
        printf("1) Insert element\n2) Display element\n");
        printf("3) Insert first node\n4) Delete first node\n5) Exit\n->: ");
        scanf("%d", &choice_535);
        switch (choice_535)
        {
        case 1:
            printf("\nEnter a element: ");
            scanf("%d", &value_535);
            push_535(&list_535, value_535);
            printf("\nThe list: ");
            display_535(list_535);
            break;
        case 2:
            printf("\nThe list: ");
            display_535(list_535);
            break;
        case 3:
            printf("\nEnter a element: ");
            scanf("%d", &value_535);
            push_first_535(&list_535, value_535);
            printf("The list: ");
            display_535(list_535);
            break;
        case 4:
            pop_first_535(&list_535);
            printf("\nThe list: ");
            display_535(list_535);
            break;
        default:
            printf("\nExiting...\n");
        }
        printf("-----------------------------\n");
    } while (choice_535 >= 1 && choice_535 <= 4);
    return 0;
}
void push_535(Node_535 **start_535, int data_535)
{
    Node_535 *temp_535 = (Node_535 *)malloc(sizeof(Node_535));
    temp_535->data_535 = data_535;
    temp_535->link_535 = *start_535;
    if (!*start_535)
    {
        *start_535 = temp_535;
        temp_535->link_535 = temp_535;
    }
    Node_535 *tempStart_535 = *start_535;
    while (tempStart_535->link_535 != *start_535)
    {
        tempStart_535 = tempStart_535->link_535;
    }
    tempStart_535->link_535 = temp_535;
}
void display_535(Node_535 *start_535)
{
    if (!start_535)
    {
        printf("null\n");
        return;
    }
    Node_535 *tempStart_535 = start_535;
    do
    {
        printf("%d->", start_535->data_535);
        start_535 = start_535->link_535;
    } while (start_535 != tempStart_535);
    printf("(cir)\n");
}
void push_first_535(Node_535 **start_535, int data_535)
{
    Node_535 *temp_535 = (Node_535 *)malloc(sizeof(Node_535));
    temp_535->data_535 = data_535;
    temp_535->link_535 = *start_535;
    if (!*start_535)
    {
        temp_535->link_535 = temp_535;
        *start_535 = temp_535;
    }
    Node_535 *tempStart_535 = *start_535;
    while (tempStart_535->link_535 != *start_535)
    {
        tempStart_535 = tempStart_535->link_535;
    }
    *start_535 = temp_535;
    tempStart_535->link_535 = *start_535;
}
void pop_first_535(Node_535 **start_535)
{
    if (!*start_535)
        return;
    else if ((*start_535)->link_535 == *start_535)
    {
        free(*start_535);
        *start_535 = NULL;
        return;
    }
    Node_535 *tempStart_535 = *start_535;
    while (tempStart_535->link_535 != *start_535)
    {
        tempStart_535 = tempStart_535->link_535;
    }
    Node_535 *ptr_535 = *start_535;
    *start_535 = (*start_535)->link_535;
    tempStart_535->link_535 = *start_535;
    free(ptr_535);
}

