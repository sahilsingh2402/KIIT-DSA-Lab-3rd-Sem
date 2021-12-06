#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    int r_thread;
    struct Node *right;
    struct Node *left;
} Node;
void insert(Node **, int);
void inorder_front(Node *);
int main()
{
    Node *root = NULL;
    int choice, val;
    do
    {
        printf("1) Insert\n2) Inorder Display\n3) Exit\n->: ");
        scanf("%d", &choice);
        printf("\n");
        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &val);
            insert(&root, val);
            break;
        case 2:
            inorder_front(root);
            break;
        default:
            printf("Exiting...\n");
        }
        printf("-------------------------------------------------\n");
    } while (choice >= 1 && choice <= 2);
    return 0;
}
void insert(Node **root, int val)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = val;
    temp->r_thread = 0;
    temp->left = temp->right = NULL;
    if (!*root)
    {
        *root = temp;
        return;
    }
    Node *ptrR = *root;
    Node *ptr_prev = NULL;
    Node *threadNode = NULL;
    while (ptrR)
    {
        ptr_prev = ptrR;
        if (ptrR->data >= val)
        {
            threadNode = ptrR;
            ptrR = ptrR->left;
        }
        else if (!ptrR->r_thread)
            ptrR = ptrR->right;
        else
            ptrR = NULL;
    }
    temp->right = threadNode;
    if (threadNode)
        temp->r_thread = 1;
    if (ptr_prev->data > val)
        ptr_prev->left = temp;
    else
    {
        ptr_prev->right = temp;
        ptr_prev->r_thread = 0;
    }
}
void inorder_front(Node *root)
{
    int flag = 0;
    while (root)
    {
        while (root->left && !flag)
            root = root->left;
        printf("%d->", root->data);
        if (root->right && root->r_thread)
        {
            flag = 1;
            root = root->right;
            continue;
        }
        root = root->right;
        flag = 0;
    }
    printf("\b\b \n");
}

