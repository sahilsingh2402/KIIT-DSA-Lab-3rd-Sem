#include <stdio.h>
#define MAX_535 100

typedef struct Stack_535
{
    int topCount_535;
    int data_535[MAX_535];
} Stack_535;

int isFull_535(Stack_535 *);
int isEmpty_535(Stack_535 *);
void push_535(Stack_535 *, int);
int pop_535(Stack_535 *);
void display_535(Stack_535 *);
void copy_535(Stack_535 *, Stack_535 *);
void sorted_insert_535(Stack_535 *, int);
void sort_535(Stack_535 *);

int main()
{
    Stack_535 stack_535 = {-1};
    Stack_535 stack2_535 = {-1};
    int choice_535;
    do
    {
        printf("1) Insert a number\n2) Delete top element\n");
        printf("3) display stack\n4) Copy stack\n5) Sort stack\n6) Exit\n->: ");
        scanf("%d", &choice_535);
        int val_535;
        switch (choice_535)
        {
        case 1:
            printf("Enter a value to insert: ");
            scanf("%d", &val_535);
            push_535(&stack_535, val_535);
            break;
        case 2:
            printf("%d was deleted!\n", pop_535(&stack_535));
            break;
        case 3:
            printf("\ntop->");
            display_535(&stack_535);
            break;
        case 4:
            printf("\ntop->");
            copy_535(&stack2_535, &stack_535);
            display_535(&stack2_535);
            break;
        case 5:
            printf("\ntop->");
            sort_535(&stack_535);
            display_535(&stack_535);
            break;
        default:
            printf("\nExiting...\n");
        }
        printf("-------------------------------\n");
    } while (choice_535 >= 1 && choice_535 <= 5);
    return 0;
}
void push_535(Stack_535 *stack_535, int num_535)
{
    if (isFull_535(stack_535))
    {
        printf("Overflow!\n");
        return;
    }
    stack_535->data_535[++stack_535->topCount_535] = num_535;
}
int pop_535(Stack_535 *stack_535)
{
    if (isEmpty_535(stack_535))
    {
        printf("Underflow!\n");
        return -99999;
    }
    return stack_535->data_535[stack_535->topCount_535--];
}
void display_535(Stack_535 *stack_535)
{
    if (isEmpty_535(stack_535))
    {
        printf("\b\b \n");
        return;
    }
    int temp_535 = pop_535(stack_535);
    printf("%d->", temp_535);
    display_535(stack_535);
    push_535(stack_535, temp_535);
}
int isFull_535(Stack_535 *stack_535)
{
    if (stack_535->topCount_535 == MAX_535 - 1)
        return 1;
    return 0;
}
int isEmpty_535(Stack_535 *stack_535)
{
    if (stack_535->topCount_535 == -1)
        return 1;
    return 0;
}
void copy_535(Stack_535 *dest_535, Stack_535 *src_535)
{
    if (isEmpty_535(src_535))
    {
        dest_535->topCount_535 = -1;
        return;
    }
    pop_535(src_535);
    copy_535(dest_535, src_535);
    push_535(dest_535, src_535->data_535[src_535->topCount_535 + 1]);
    push_535(src_535, src_535->data_535[src_535->topCount_535 + 1]);
}
void sorted_insert_535(Stack_535 *stack_535, int val_535)
{
    if (isEmpty_535(stack_535) || val_535 > stack_535->topCount_535)
    {
        push_535(stack_535, val_535);
        return;
    }
    int temp_535 = pop_535(stack_535);
    sorted_insert_535(stack_535, temp_535);
    push_535(stack_535, temp_535);
}
void sort_535(Stack_535 *stack_535)
{
    if (isEmpty_535(stack_535))
        return;
    int temp_535 = pop_535(stack_535);
    sort_535(stack_535);
    sorted_insert_535(stack_535, temp_535);
}

