/*Write a menu driven program to perform the following operations in a header linked list by using
suitable user defined functions for each case. The head node keeps the count of the total number of
nodes in the list. The data node keeps the student information: Name, Roll No, CGPA, Address_City,
Branch.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node_535
{
    char name_535[20];
    int roll_535;
    float cgpa_535;
    char city_535[10];
    char branch_535[10];
    struct Node_535 *link_535;
} Node_535;
typedef struct Header_535
{
    int count_535;
    Node_535 *link_535;
} Header_535;
void get_535(Node_535 *);
void put_535(Node_535);
Node_535 *create_node_535(Node_535);
void push_535(Header_535 **, Node_535);
void display_535(Header_535 *);
int node_count_535(Header_535 *);
void display_branch_535(Header_535 *, char *);
void display_cgpa_branch_535(Header_535 *, char *);
int main()
{
    Header_535 *hlist_535 = NULL; //hlist_535 is the pointer to header node
    Node_535 data_535;
    int choice_535;
    do
    {
        printf("1) Insert data\n2) Display data\n3) Count nodes\n");
        printf("4) Search by branch\n5) Above 7.5 CGPA, branch\n6) Exit\n->: ");
        scanf("%d", &choice_535);
        switch (choice_535)
        {
        case 1:
            printf("\nEnter following info:\n");
            get_535(&data_535);
            push_535(&hlist_535, data_535);
            break;
        case 2:
            printf("\n");
            display_535(hlist_535);
            break;
        case 3:
            printf("\nNode count: %d\n", node_count_535(hlist_535));
            break;
        case 4:
            printf("\nEnter branch: ");
            scanf(" %[^\n]s", data_535.branch_535);
            display_branch_535(hlist_535, data_535.branch_535);
            break;
        case 5:
            printf("\nEnter branch: ");
            scanf(" %[^\n]s", data_535.branch_535);
            display_cgpa_branch_535(hlist_535, data_535.branch_535);
            break;
        default:
            printf("\nExiting...\n");
        }
        printf("------------------------------\n");
    } while (choice_535 >= 1 && choice_535 <= 5);
    return 0;
}
void get_535(Node_535 *data_535)
{
    printf("Name: ");
    scanf(" %[^\n]s", data_535->name_535);
    printf("Roll: ");
    scanf("%d", &data_535->roll_535);
    printf("CGPA: ");
    scanf("%f", &data_535->cgpa_535);
    printf("City: ");
    scanf(" %[^\n]s", data_535->city_535);
    printf("Branch: ");
    scanf(" %[^\n]s", data_535->branch_535);
}
void put_535(Node_535 data_535)
{
    printf("%s", data_535.name_535);
    printf(" %d", data_535.roll_535);
    printf(" %0.2f", data_535.cgpa_535);
    printf(" %s", data_535.city_535);
    printf(" %s\n", data_535.branch_535);
}
Node_535 *create_node_535(Node_535 data_535)
{
    Node_535 *temp_535 = (Node_535 *)malloc(sizeof(Node_535));
    strcpy(temp_535->name_535, data_535.name_535);
    strcpy(temp_535->city_535, data_535.city_535);
    strcpy(temp_535->branch_535, data_535.branch_535);
    temp_535->roll_535 = data_535.roll_535;
    temp_535->cgpa_535 = data_535.cgpa_535;
    temp_535->link_535 = NULL;
    return temp_535;
}
void push_535(Header_535 **hlist_535, Node_535 data_535)
{
    Node_535 *temp_535 = create_node_535(data_535);
    if (!*hlist_535)
    {
        *hlist_535 = (Header_535 *)malloc(sizeof(Header_535));
        (*hlist_535)->count_535 = 1;
        (*hlist_535)->link_535 = temp_535;
        return;
    }
    Node_535 *tempStart_535 = (*hlist_535)->link_535;
    while (tempStart_535->link_535)
    {
        tempStart_535 = tempStart_535->link_535;
    }
    (*hlist_535)->count_535++;
    tempStart_535->link_535 = temp_535;
}
void display_535(Header_535 *hlist_535)
{
    if (!hlist_535)
    {
        printf("(null)\n");
        return;
    }
    Node_535 *tempStart_535 = hlist_535->link_535;
    while (tempStart_535)
    {
        put_535(*tempStart_535);
        tempStart_535 = tempStart_535->link_535;
    }
}
int node_count_535(Header_535 *hlist_535)
{
    if (!hlist_535)
        return 0;
    return hlist_535->count_535;
}
void display_branch_535(Header_535 *hlist_535, char *branch_535)
{
    if (!hlist_535)
    {
        printf("(null)\n");
        return;
    }
    Node_535 *tempStart_535 = hlist_535->link_535;
    while (tempStart_535)
    {
        int match_535 = !strcmp(tempStart_535->branch_535, branch_535);
        if (match_535)
            put_535(*tempStart_535);
        tempStart_535 = tempStart_535->link_535;
    }
}
void display_cgpa_branch_535(Header_535 *hlist_535, char *branch_535)
{
    if (!hlist_535)
    {
        printf("(null)\n");
        return;
    }
    Node_535 *tempStart_535 = hlist_535->link_535;
    while (tempStart_535)
    {
        int match_535 = !strcmp(tempStart_535->branch_535, branch_535);
        if (match_535 && tempStart_535->cgpa_535 > 7.5)
            put_535(*tempStart_535);
        tempStart_535 = tempStart_535->link_535;
    }
}

