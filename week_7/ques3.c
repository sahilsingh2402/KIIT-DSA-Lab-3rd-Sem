#include <stdio.h>
#define MAX_535 100
typedef struct Stack_535
{
    int top1_535;
    int top2_535;
    int data_535[MAX_535];
} Stack_535;
int isFull_535(Stack_535 *);
//For first stack_535
int isEmpty1_535(Stack_535 *);
void push1_535(Stack_535 *, int);
int pop1_535(Stack_535 *);
void display1_535(Stack_535 *);
//For second stack_535
int isEmpty2_535(Stack_535 *);
void push2_535(Stack_535 *, int);
int pop2_535(Stack_535 *);
void display2_535(Stack_535 *);
int main()
{
    Stack_535 stack_535 = {-1, MAX_535};
    int choice_535;
    do
    {
        printf("Enter stack ID 1 for first stack and 2 for second!\n");
        printf("1) Insert\n2) Display\n3) Delete\n4) Exit\n->: ");
        scanf("%d", &choice_535);
        int val_535, id_535;
        switch (choice_535)
        {
        case 1:
            printf("Stack ID: ");
            scanf("%d", &id_535);
            printf("Enter value: ");
            scanf("%d", &val_535);
            (id_535 - 1) ? push2_535(&stack_535, val_535)
                         : push1_535(&stack_535, val_535);
            break;
        case 2:
            printf("Stack ID: ");
            scanf("%d", &id_535);
            (id_535 - 1) ? display2_535(&stack_535) : display1_535(&stack_535);
            break;
        case 3:
            printf("Stack ID: ");
            scanf("%d", &id_535);
            (id_535 - 1) ? pop2_535(&stack_535) : pop1_535(&stack_535);
            (id_535 - 1) ? display2_535(&stack_535) : display1_535(&stack_535);
            break;
        default:
            printf("\bExiting...\n");
        }
        printf("---------------------------\n");
    } while (choice_535 >= 1 && choice_535 <= 3);
    return 0;
}
int isFull_535(Stack_535 *stack_535)
{
    if (stack_535->top1_535 + 1 == stack_535->top2_535)
        return 1;
    return 0;
}
int isEmpty1_535(Stack_535 *stack_535)
{
    if (stack_535->top1_535 == -1)
        return 1;
    return 0;
}
void push1_535(Stack_535 *stack_535, int num)
{
    if (isFull_535(stack_535))
    {
        printf("Overflow!\n");
        return;
    }
    stack_535->data_535[++stack_535->top1_535] = num;
}
int pop1_535(Stack_535 *stack_535)
{
    if (isEmpty1_535(stack_535))
    {
        printf("Underflow!\n");
        return -99999;
    }
    return stack_535->data_535[stack_535->top1_535--];
}
void display1_535(Stack_535 *stack_535)
{
    if (isEmpty1_535(stack_535))
    {
        printf("\b\b \n");
        return;
    }
    int temp_535 = pop1_535(stack_535);
    printf("%d->", temp_535);
    display1_535(stack_535);
    push1_535(stack_535, temp_535);
}
//////////////////////////////////////////////////////////////////////////////
int isEmpty2_535(Stack_535 *stack_535)
{
    if (stack_535->top2_535 == MAX_535)
        return 1;
    return 0;
}
void push2_535(Stack_535 *stack_535, int num)
{
    if (isFull_535(stack_535))
    {
        printf("Overflow!\n");
        return;
    }
    stack_535->data_535[--stack_535->top2_535] = num;
}
int pop2_535(Stack_535 *stack_535)
{
    if (isEmpty2_535(stack_535))
    {
        printf("Underflow!\n");
        return -99999;
    }
    return stack_535->data_535[stack_535->top2_535++];
}
void display2_535(Stack_535 *stack_535)
{
    if (isEmpty2_535(stack_535))
    {
        printf("\b\b \n");
        return;
    }
    int temp_535 = pop2_535(stack_535);
    printf("%d->", temp_535);
    display2_535(stack_535);
    push2_535(stack_535, temp_535);
}

