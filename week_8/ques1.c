#include <stdio.h>
#include <stdlib.h>

#define INT_MAX_535 2147483647
#define INT_MIN_535 -2147483648

typedef struct Stack_535
{
    int data_535;
    struct Stack_535 *link_535;
} Stack_535;

void push_535(Stack_535 **, int);
int pop_535(Stack_535 **);
int isEmpty_535(Stack_535 *);
void display_535(Stack_535 *);
int peek_lowest_535(Stack_535 *);
int peek_highest_535(Stack_535 *);
int peek_middle_535(Stack_535 *, int *, int);

int main()
{
    Stack_535 *stack_535 = NULL;
    int choice_535;
    do
    {
        int val_535;
        printf("1) Insert in stack\n2) Display\n3) Delete top\n");
        printf("4) Peek lowest\n5) Peek highest\n6) Peek middle\n7) Exit\n->: ");
        scanf("%d", &choice_535);
        switch (choice_535)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &val_535);
            push_535(&stack_535, val_535);
            break;
        case 2:
            printf("\ntop->");
            display_535(stack_535);
            break;
        case 3:
            printf("\nDeleted element: %d\n", pop_535(&stack_535));
            break;
        case 4:
            printf("\nLowest value: %d\n", peek_lowest_535(stack_535));
            break;
        case 5:
            printf("\nHighest value: %d\n", peek_highest_535(stack_535));
            break;
        case 6:
            printf("\nMiddle element: %d\n",
                   peek_middle_535(stack_535, &val_535, 0));
            break;
        default:
            printf("\nExiting...\n");
        }
        printf("----------------------------\n");
    } while (choice_535 >= 1 && choice_535 <= 6);
    return 0;
}

void push_535(Stack_535 **stack_535, int num_535)
{
    Stack_535 *temp_535 = (Stack_535 *)malloc(sizeof(Stack_535));
    temp_535->data_535 = num_535;
    temp_535->link_535 = *stack_535;
    *stack_535 = temp_535;
}

int pop_535(Stack_535 **stack_535)
{
    if (isEmpty_535(*stack_535))
    {
        printf("\nUnderflow!");
        return -9999999;
    }
    Stack_535 *temp_535 = (*stack_535);
    *stack_535 = (*stack_535)->link_535;
    int val_535 = temp_535->data_535;
    free(temp_535);
    return val_535;
}

int isEmpty_535(Stack_535 *stack_535)
{
    if (!stack_535)
        return 1;
    return 0;
}

void display_535(Stack_535 *stack_535)
{
    if (isEmpty_535(stack_535))
    {
        printf("\b\b \n");
        return;
    }
    int temp_535 = pop_535(&stack_535);
    printf("%d->", temp_535);
    display_535(stack_535);
    push_535(&stack_535, temp_535);
}

int peek_lowest_535(Stack_535 *stack_535)
{
    if (!stack_535)
        return INT_MAX_535;

    int val_535 = pop_535(&stack_535);
    int lowest_535 = peek_lowest_535(stack_535);
    push_535(&stack_535, val_535);
    if (lowest_535 > val_535)
        return val_535;
    return lowest_535;
}

int peek_highest_535(Stack_535 *stack_535)
{
    if (!stack_535)
        return INT_MIN_535;

    int val_535 = pop_535(&stack_535);
    int highest_535 = peek_highest_535(stack_535);
    push_535(&stack_535, val_535);
    if (highest_535 < val_535)
        return val_535;
    return highest_535;
}

int peek_middle_535(Stack_535 *stack_535, int *length_535, int position_535)
{
    if (!stack_535)
    {
        *length_535 = position_535;
        return INT_MIN_535;
    }
    int val_535 = pop_535(&stack_535);
    int next_535 = peek_middle_535(stack_535, length_535, position_535 + 1);
    push_535(&stack_535, val_535);

    if (*length_535 / 2 == position_535)
        return val_535;
    return next_535;
}

