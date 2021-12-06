/*Write a menu driven program to perform the following operations in a double linked list by using
suitable user defined functions for each case.*/
#include <stdio.h>
#include <stdlib.h>
typedef struct Node_535
{
    int data_535;
    struct Node_535 *prev_535;
    struct Node_535 *next_535;
} Node_535;
typedef struct DList_535
{
    Node_535 *start_535;
    Node_535 *end_535;
} DList_535;
//Utility Functions
Node_535 *create_node_535(int);
void push_util_535(Node_535 **, Node_535 **, int);
void display_fwd_util_535(Node_535 *);
void display_bkwd_util_535(Node_535 *);
void push_after_util_535(Node_535 **, Node_535 **, int, int);
void push_before_util_535(Node_535 **, Node_535 **, int, int);
void pop_at_util_535(Node_535 **, Node_535 **, int);
void push_first_util_535(Node_535 **, Node_535 **, int);
void pop_first_util_535(Node_535 **, Node_535 **);
void reverse_content_util_535(Node_535 *, Node_535 *);
//Driver Functions
void push_535(DList_535 *, int);
void display_fwd_535(DList_535);
void display_bkwd_535(DList_535);
void push_after_535(DList_535 *, int, int);
void push_before_535(DList_535 *, int, int);
void pop_at_535(DList_535 *, int);
void push_first_535(DList_535 *, int);
void pop_first_535(DList_535 *);
void reverse_content_535(DList_535);
int main()
{
    DList_535 dlist_535 = {NULL, NULL};
    int choice_535, value_535, pos_535;
    do
    {
        printf("1) Insert element\n2) Display forward\n3) Display backward\n");
        printf("4) Add node after element\n5) Add node before element\n");
        printf("6) Delete node at position\n7) Insert node as first node\n");
        printf("8) Delete the first node\n9) Reverse list contents\n->: ");
        scanf("%d", &choice_535);
        switch (choice_535)
        {
        case 1:
            printf("\nEnter a value: ");
            scanf("%d", &value_535);
            push_535(&dlist_535, value_535);
            printf("The list: ");
            display_fwd_535(dlist_535);
            break;
        case 2:
            printf("\nThe list: ");
            display_fwd_535(dlist_535);
            break;
        case 3:
            printf("\nThe list(bkwd): ");
            display_bkwd_535(dlist_535);
            break;
        case 4:
            printf("\nEnter a data member after which to insert: ");
            scanf("%d", &pos_535);
            printf("Enter value to insert: ");
            scanf("%d", &value_535);
            push_after_535(&dlist_535, value_535, pos_535);
            printf("The list: ");
            display_fwd_535(dlist_535);
            break;
        case 5:
            printf("\nEnter a data member before which to insert: ");
            scanf("%d", &pos_535);
            printf("Enter value to insert: ");
            scanf("%d", &value_535);
            push_before_535(&dlist_535, value_535, pos_535);
            printf("The list: ");
            display_fwd_535(dlist_535);
            break;
        case 6:
            printf("\nEnter the position of node to delete: ");
            scanf("%d", &pos_535);
            pop_at_535(&dlist_535, pos_535);
            printf("The list: ");
            display_fwd_535(dlist_535);
            break;
        case 7:
            printf("\nEnter a value: ");
            scanf("%d", &value_535);
            push_first_535(&dlist_535, value_535);
            printf("The list: ");
            display_fwd_535(dlist_535);
            break;
        case 8:
            printf("\nDeleted...\n");
            pop_first_535(&dlist_535);
            printf("The list: ");
            display_fwd_535(dlist_535);
            break;
        case 9:
            printf("\nReversed...");
            reverse_content_535(dlist_535);
            printf("\nThe list: ");
            display_fwd_535(dlist_535);
            break;
        default:
            printf("\nExiting...\n");
        }
        printf("----------------------------\n");
    } while (choice_535 >= 1 && choice_535 <= 9);
    return 0;
}
Node_535 *create_node_535(int data_535)
{
    Node_535 *temp_535 = (Node_535 *)malloc(sizeof(Node_535));
    temp_535->data_535 = data_535;
    temp_535->next_535 = NULL;
    temp_535->prev_535 = NULL;
    return temp_535;
}
void push_util_535(Node_535 **start_535, Node_535 **end_535, int data_535)
{
    Node_535 *temp_535 = create_node_535(data_535);
    if (!*start_535)
    {
        *end_535 = *start_535 = temp_535;
        return;
    }
    temp_535->prev_535 = *end_535;
    (*end_535)->next_535 = temp_535;
    *end_535 = temp_535;
}
void display_fwd_util_535(Node_535 *start_535)
{
    if (start_535)
        printf("null");
    while (start_535)
    {
        printf("<-%d->", start_535->data_535);
        start_535 = start_535->next_535;
    }
    printf("null\n");
}
void display_bkwd_util_535(Node_535 *end_535)
{
    if (end_535)
        printf("null");
    while (end_535)
    {
        printf("<-%d->", end_535->data_535);
        end_535 = end_535->prev_535;
    }
    printf("null\n");
}
void push_after_util_535(Node_535 **start_535, Node_535 **end_535, int data_535, int pos_535)
{
    Node_535 *temp_535 = create_node_535(data_535);
    if (!*start_535)
    {
        *start_535 = *end_535 = temp_535;
        return;
    }
    Node_535 *tempStart_535 = *start_535;
    while (tempStart_535 && tempStart_535->data_535 != pos_535)
    {
        tempStart_535 = tempStart_535->next_535;
    }
    if (!tempStart_535 || tempStart_535 == *end_535)
    {
        temp_535->prev_535 = *end_535;
        (*end_535)->next_535 = temp_535;
        *end_535 = temp_535;
        return;
    }
    temp_535->next_535 = tempStart_535->next_535;
    tempStart_535->next_535->prev_535 = temp_535;
    temp_535->prev_535 = tempStart_535;
    tempStart_535->next_535 = temp_535;
}
void push_before_util_535(Node_535 **start_535, Node_535 **end_535, int data_535, int pos_535)
{
    Node_535 *temp_535 = create_node_535(data_535);
    if (!*start_535)
    {
        *start_535 = *end_535 = temp_535;
        return;
    }
    Node_535 *tempStart_535 = *start_535;
    while (tempStart_535 && tempStart_535->data_535 != pos_535)
    {
        tempStart_535 = tempStart_535->next_535;
    }
    if (!tempStart_535)
    {
        temp_535->prev_535 = *end_535;
        (*end_535)->next_535 = temp_535;
        *end_535 = temp_535;
        return;
    }
    else if (tempStart_535 == *start_535)
    {
        temp_535->next_535 = *start_535;
        (*start_535)->prev_535 = temp_535;
        *start_535 = temp_535;
        return;
    }
    temp_535->prev_535 = tempStart_535->prev_535;
    temp_535->prev_535->next_535 = temp_535;
    temp_535->next_535 = tempStart_535;
    tempStart_535->prev_535 = temp_535;
}
void pop_at_util_535(Node_535 **start_535, Node_535 **end_535, int pos_535)
{
    Node_535 *tempStart_535 = *start_535;
    while (tempStart_535 && pos_535 - 1)
    {
        tempStart_535 = tempStart_535->next_535;
        pos_535--;
    }
    if (!tempStart_535 || pos_535 <= 0)
        return;
    else if (tempStart_535 == *start_535)
    {
        *start_535 = (*start_535)->next_535;
        if (!*start_535)
            *end_535 = NULL;
        else
            (*start_535)->prev_535 = NULL;
        free(tempStart_535);
        return;
    }
    else if (tempStart_535 == *end_535)
    {
        *end_535 = (*end_535)->prev_535;
        if (!*end_535)
            *start_535 = NULL;
        else
            (*end_535)->next_535 = NULL;
        free(tempStart_535);
        return;
    }
    tempStart_535->next_535->prev_535 = tempStart_535->prev_535;
    tempStart_535->prev_535->next_535 = tempStart_535->next_535;
    free(tempStart_535);
}
void push_first_util_535(Node_535 **start_535, Node_535 **end_535, int data_535)
{
    Node_535 *temp_535 = create_node_535(data_535);
    if (!*start_535)
    {
        *start_535 = *end_535 = temp_535;
        return;
    }
    (*start_535)->prev_535 = temp_535;
    temp_535->next_535 = *start_535;
    *start_535 = temp_535;
}
void pop_first_util_535(Node_535 **start_535, Node_535 **end_535)
{
    if (!*start_535)
        return;
    Node_535 *ptr = *start_535;
    *start_535 = (*start_535)->next_535;
    if (*start_535)
        (*start_535)->prev_535 = NULL;
    else
        *end_535 = NULL;
    free(ptr);
}
void reverse_content_util_535(Node_535 *start_535, Node_535 *end_535)
{
    while (start_535 != end_535 && start_535->prev_535 != end_535)
    {
        int temp_535 = start_535->data_535;
        start_535->data_535 = end_535->data_535;
        end_535->data_535 = temp_535;
        start_535 = start_535->next_535;
        end_535 = end_535->prev_535;
    }
}
////////////////////////////////////////////////////////////////////
void push_535(DList_535 *dlist_535, int data_535)
{
    push_util_535(&dlist_535->start_535, &dlist_535->end_535, data_535);
}
void display_fwd_535(DList_535 dlist_535)
{
    display_fwd_util_535(dlist_535.start_535);
}
void display_bkwd_535(DList_535 dlist_535)
{
    display_bkwd_util_535(dlist_535.end_535);
}
void push_after_535(DList_535 *dlist_535, int data_535, int pos_535)
{
    push_after_util_535(&dlist_535->start_535, &dlist_535->end_535, data_535, pos_535);
}
void push_before_535(DList_535 *dlist_535, int data_535, int pos_535)
{
    push_before_util_535(&dlist_535->start_535, &dlist_535->end_535, data_535, pos_535);
}
void pop_at_535(DList_535 *dlist_535, int pos_535)
{
    pop_at_util_535(&dlist_535->start_535, &dlist_535->end_535, pos_535);
}
void push_first_535(DList_535 *dlist_535, int data_535)
{
    push_first_util_535(&dlist_535->start_535, &dlist_535->end_535, data_535);
}
void pop_first_535(DList_535 *dlist_535)
{
    pop_first_util_535(&dlist_535->start_535, &dlist_535->end_535);
}
void reverse_content_535(DList_535 dlist_535)
{
    reverse_content_util_535(dlist_535.start_535, dlist_535.end_535);
}

