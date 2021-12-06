#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *right;
    struct Node *left;
} Node;
void insert(Node **root, int val)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    if (!*root)
    {
        *root = temp;
        return;
    }
    Node *ptrR = *root;
    Node *ptr_prev;
    while (ptrR)
    {
        ptr_prev = ptrR;
        if (ptrR->data >= val)
            ptrR = ptrR->left;
        else
            ptrR = ptrR->right;
    }
    if (ptr_prev->data > val)
        ptr_prev->left = temp;
    else
        ptr_prev->right = temp;
}
void preorder(Node *root)
{
    if (!root)
        return;
    printf("%d->", root->data);
    preorder(root->left);
    preorder(root->right);
}
void inorder(Node *root)
{
    if (!root)
        return;
    inorder(root->left);
    printf("%d->", root->data);
    inorder(root->right);
}
void postorder(Node *root)
{
    if (!root)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d->", root->data);
}
int treeHeight(Node *root)
{
    if (!root)
        return -1;
    return ((treeHeight(root->left) > treeHeight(root->right)) ? treeHeight(root->left) + 1 : treeHeight(root->right) + 1);
}
int isFullyComplete(Node *root)
{
    if (!root)
        return 1;
    else if (!root->left && !root->right)
        return 1;
    else if (root->left && root->right)
        return isFullyComplete(root->left) &&
               isFullyComplete(root->right);
    return 0;
}
void order_Nodes(Node *root, int *zero, int *first, int *second)
{
    if (!root)
        return;
    if (!root->left && !root->right)
        (*zero)++;
    else if (!root->left || !root->right)
        (*first)++;
    else
        (*second)++;
    order_Nodes(root->left, zero, first, second);
    order_Nodes(root->right, zero, first, second);
}
void count_degree(Node *root)
{
    int zero = 0;
    int first = 0;
    int second = 0;
    order_Nodes(root, &zero, &first, &second);
    printf("Degree zero: %d\n", zero);
    printf("Degree first: %d\n", first);
    printf("Degree second: %d\n", second);
}
int main()
{
    Node *root = NULL;
    int choice, val, t_hold;
    do
    {
        printf("1) Insert\n2) Preorder\n3) Postorder\n4) Inorder\n5) Tree Height\n");
        printf("6) Fully Complete BST\n7) Number of nodes of each degree\n");
        printf("8) Exit\n->: ");
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
            preorder(root);
            printf("\b\b \n");
            break;
        case 3:
            postorder(root);
            printf("\b\b \n");
            break;
        case 4:
            inorder(root);
            printf("\b\b \n");
            break;
        case 5:
            printf("Height of the tree: %d\n", treeHeight(root));
            break;
        case 6:
            if (isFullyComplete(root))
                printf("True\n");
            else
                printf("False\n");
            break;
        case 7:
            count_degree(root);
            break;
        default:
            printf("Exiting...\n");
        }
        printf("-------------------------------------------------\n");
    } while (choice >= 1 && choice <= 7);
    return 0;
}
