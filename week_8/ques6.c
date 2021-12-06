#include <stdio.h>
#include <stdlib.h>
typedef struct Stack_535
{
    char data_535;
    struct Stack_535 *link_535;
} Stack_535;
void push_535(Stack_535 **, char n);
void pop_535(Stack_535 **);
char top_535(Stack_535 *);
int isEmpty_535(Stack_535 *);
int isBalanced_535(char str[]);
int main()
{
    char arr_535[100];
    printf("String: ");
    scanf("%s", arr_535);
    if (isBalanced_535(arr_535))
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
void push_535(Stack_535 **stack_535, char ch_535)
{
    Stack_535 *temp_535 = (Stack_535 *)malloc(sizeof(Stack_535));
    temp_535->data_535 = ch_535;
    temp_535->link_535 = *stack_535;
    *stack_535 = temp_535;
}
void pop_535(Stack_535 **stack_535)
{
    if (!*stack_535)
        return;
    Stack_535 *temp_535 = *stack_535;
    *stack_535 = (*stack_535)->link_535;
    free(temp_535);
}
char top_535(Stack_535 *stack_535)
{
    if (!stack_535)
        return 'a';
    return stack_535->data_535;
}
int isEmpty_535(Stack_535 *stack_535)
{
    if (!stack_535)
        return 1;
    return 0;
}
int isBalanced_535(char arr_535[])
{
    Stack_535 *stack_535 = NULL;
    for (int i = 0; arr_535[i] != '\0'; i++)
    {
        if (arr_535[i] == '(' || arr_535[i] == '[' || arr_535[i] == '{')
        {
            push_535(&stack_535, arr_535[i]);
            continue;
        }
        else if (arr_535[i] == ')' || arr_535[i] == '}' || arr_535[i] == ']')
        {
            if (isEmpty_535(stack_535))
                return 0;
        }
        if (top_535(stack_535) == '(' && arr_535[i] == ')')
            pop_535(&stack_535);
        else if (top_535(stack_535) == '{' && arr_535[i] == '}')
            pop_535(&stack_535);
        else if (top_535(stack_535) == '[' && arr_535[i] == ']')
            pop_535(&stack_535);
    }
    return isEmpty_535(stack_535);
}
