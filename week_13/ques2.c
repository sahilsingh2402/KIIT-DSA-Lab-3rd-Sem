#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    char data;
    struct Node *left;
    struct Node *right;
} Node;
typedef struct Node Node;

typedef struct Stack
{
    Node *data;
    struct Stack *link;
} Stack;

int isEmpty_stack(Stack *stack)
{
    if (!stack)
        return 1;
    return 0;
}

void push(Stack **stack, Node *data)
{
    Stack *temp = (Stack *)malloc(sizeof(Stack));
    temp->data = data;
    temp->link = *stack;
    *stack = temp;
}

Node *pop(Stack **stack)
{
    if (isEmpty_stack(*stack))
    {
        printf("\nUnderflow!");
        return NULL;
    }

    Stack *temp = (*stack);
    *stack = (*stack)->link;

    Node *val = temp->data;
    free(temp);
    return val;
    Node *scanExpression(char *);
    void preorder(Node *);
    void inorder(Node *);
}

Node *scanExpression(char *expression)
{
    if (!expression)
        return NULL;
    int i = 0;
    char operations[6] = {'+', '-', '*', '/', '^', '%'};
    Stack *stack = NULL;
    while (expression[i] != '\0')
    {
        if ((expression[i] >= 'A' && expression[i] <= 'Z') ||
            (expression[i] >= 'a' && expression[i] <= 'z'))
        {
            Node *temp = (Node *)malloc(sizeof(Node));
            temp->right = temp->left = NULL;
            temp->data = expression[i];
            push(&stack, temp);
        }
        else
        {
            for (int j = 0; j < 6; j++)
            {
                if (operations[j] == expression[i])
                {
                    Node *temp =
                        (Node *)malloc(sizeof(Node));
                    temp->right = temp->left = NULL;
                    temp->data = expression[i];
                    temp->right = pop(&stack);
                    temp->left = pop(&stack);
                    push(&stack, temp);
                    break;
                }
            }
        }
        i++;
    }
    return pop(&stack);
}

void preorder(Node *root)
{
    if (!root)
        return;
    printf("%c", root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node *root)
{
    if (!root)
        return;
    inorder(root->left);
    printf("%c", root->data);
    inorder(root->right);
}

int main()
{
    char *input;
    printf("Enter expression: ");
    scanf(" %s", input);
    Node *root = scanExpression(input);
    printf("\nInorder: ");
    inorder(root);
    printf("\nPreorder: ");
    preorder(root);
    printf("\n");
    return 0;
}

