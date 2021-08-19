#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} *start = NULL;

void create_list(int n)
{
    struct node *temp;
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = n;
    new->next = NULL;
    if (start = NULL)
    {
        start = new;
    }
    else
    {
        temp = start;
        while (temp->next != NULL)
        {
            temp = temp->next;
            temp->next = new;
        }
    }
}

void main()
{
    int choice;
    struct node *start = NULL;
    while (1)
    {
        printf("Choices:\n");
        printf("1. Create List\n");
        printf("2. Traverse List\n");
        printf("3. Check List (Underflow Condition)\n");
        printf("4. Insert a node after a given data item\n");
        printf("5. Insert a node before a given data item\n");
        printf("6. Delete a node after a given data item\n");
        printf("7. Delete a node before a given data item\n");
        printf("8. Insert a node at the certain position\n");
        printf("9. Delete a node at the certain position\n");
        printf("10. Delete a node for the given key\n");
        printf("11. Search for an element in the linked list\n");
        printf("12. Sort the elements of the linked list\n");
        printf("13. Print the elements of the linked list in the reverse order\n");
        printf("14. Reverse the nodes of the linked list\n");
        printf("15. Print n th node from the last of a linked list\n");
        printf("16. Delete the duplicate elements in a linked list\n");

        printf("\n\nEnter Choice(1-16): ");
        scanf("%d", &choice);
    }

    switch (choice)
    {
    case 1:
        
        create_list(5);
        break;

    default:
        break;
    }
}
