#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *link;
};
struct node *create(struct node *start);
void traverse(struct node *start);
void count(struct node *start);
struct node *add_beg(struct node *start, int data);
struct node *add_end(struct node *start, int data);
/*
void search(struct node *start, int data);
struct node *add_pos(struct node *start, int data, int pos);
struct node *del(struct node *start, int pos);
struct node *del_key(struct node *start, int item);
*/

int main(void)
{
    struct node *start = NULL;
    int choice, pos, data, item;
    while (1)
    {
        printf("\n--------Linked List Operations-------\n");
        printf("1. Create List\n");
        printf("2. Traverse List\n");
        printf("3. Check List (Underflow Condition)\n");
        printf("4. Insert a node after a given data item\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            start = create(start);
            break;

        case 2:
            traverse(start);
            break;

        case 3:
            count(start);
            break;

        default:
            printf("Error");
            break;
        }
    }
}

struct node *create(struct node *start)
{
    int i, n, data;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    start = NULL;
    if (n == 0)
        return start;
    printf("Enter Element: ");
    scanf("%d", &data);
    start = add_beg(start, data);
    for (i = 2; i <= n; i++)
    {
        printf("Enter Element: ");
        scanf("%d", &data);
        start = add_end(start, data);
    }
    return start;
}

struct node *add_beg(struct node *start, int data)
{
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info = data;
    tmp->link = start;
    start = tmp;
};

struct node *add_end(struct node *start, int data)
{
    struct node *tmp, *ptr;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info = data;
    ptr = start;
    while (ptr->link != NULL)
        ptr = ptr->link;

    ptr->link = tmp;
    tmp->link = NULL;
    return start;
};

void traverse(struct node *start)
{
    struct node *ptr;
    if (start == NULL)
    {
        printf("List is empty\n");
        return;
    }
    ptr = start;
    printf("List is:\n");
    while (ptr != NULL)
    {
        printf("%d ", ptr->info);
        ptr = ptr->link;
    }
    printf("\n\n");
};

void count(struct node *start)
{
    struct node *ptr;
    int count = 0;
    if (start == NULL)
    {
        printf("List is empty\n");
        return;
    }
    ptr = start;
    while (ptr != NULL)
    {
        ptr = ptr->link;
        count++;
    }
    printf("No of elements: %d\n", count);
};

void insert_after_di(struct node *start, int data)
{
    struct node *temp = start;
    while ((temp->data) != item && temp != NULL)
    {
        temp = temp->next;
        if (temp = NULL)
        {
            printf("Item not found!");
        }
        else
        {
            new->next = temp->next;
            temp->next = new;
        }
    }
}

/*
void search(struct node *start, int data)
{
    struct node *ptr;
    int pos = 1;
    if (start == NULL)
    {
        printf("List is empty\n");
        return;
    }
    ptr = start;
    printf("List is:\n");
    while (ptr != NULL)
    {
        if (ptr->info == data)
            ;
        {
            printf("item is %d found at %d \n", data, pos);
            return;
        }
        ptr = ptr->link;
        pos++;
    }
    printf("\nItem not found");
};



struct node *add_pos(struct node *start, int data, int pos)
{
    struct node *tmp, *ptr;
    int i;
    ptr = start;
    for (i = 1; i < pos - 1 && ptr != NULL; i++)
        ptr = ptr->link;
    if (ptr == NULL)
        printf("error\n");
    else
    {
        tmp = (struct node *)malloc(sizeof(struct node));
        tmp->info = data;
        if (pos == 1)
        {
            tmp->link = start;
            start = tmp;
        }
        else
        {
            tmp->link = ptr->link;
            ptr->link = tmp;
        }
    }
    return start;
};

struct node *del_key(struct node *start, int data)
{
    struct node *tmp, *ptr;
    if (start == NULL)
    {
        printf("Empty list");
        return start;
    }
    if (start->info == data)
    {
        tmp = start;
        start = start->link;
        free(tmp);
        return start;
    }
    ptr = start;
    while (ptr->link != NULL)
    {
        if (ptr->link->info == data)
        {
            tmp = ptr->link;
            ptr->link = tmp->link;
            free(tmp);
            return start;
        }
        ptr = ptr->link;
    }
    printf("Element not found\n");
    return start;
};
struct node *del(struct node *start, int pos)
{
    struct node *tmp, *ptr, *temp;
    int i;
    ptr = start;
    if (start == NULL)
    {
        printf("Empty list");
        return start;
    }
    if (pos == 1)
    {
        tmp = start;
        start = start->link;
        free(tmp);
        return start;
    }
    for (i = 1; i <= (pos - 1); i++)
    {
        temp = ptr;
        ptr = ptr->link;
        if (ptr == NULL)
        {
            printf("Invalid pos\n");
        }
        temp->link = ptr->link;
        free(ptr);
        return start;
    }
}
*/