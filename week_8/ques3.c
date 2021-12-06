#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Stack_535
{
    int data_535;
    struct Stack_535 *link_535;
} Stack_535;
void push_535(Stack_535 **, int);
void pop_535(Stack_535 **);
int top_535(Stack_535 *);
int operation_535(char, int, int);
int EvoPrefix_535(char[]);
int main()
{
    char str_535[100];
    scanf(" %[^\n]s", str_535);
    printf("= %d\n", EvoPrefix_535(str_535));
    return 0;
}
void push_535(Stack_535 **stack_535, int num_535)
{
    Stack_535 *temp_535 = (Stack_535 *)malloc(sizeof(Stack_535));
    temp_535->data_535 = num_535;
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
int top_535(Stack_535 *stack_535)
{
    if (!stack_535)
        return 0;
    return stack_535->data_535;
}
int operation_535(char ch_535, int op1_535, int op2_535)
{
    switch (ch_535)
    {
    case '+':
        return op1_535 + op2_535;
    case '-':
        return op1_535 - op2_535;
    case '*':
        return op1_535 * op2_535;
    case '/':
        return op1_535 / op2_535;
    case '%':
        return op1_535 % op2_535;
    }
    //Exponent
    int res_535 = 1;
    for (int i = 0; i < op2_535; i++)
        res_535 *= op1_535;
    return res_535;
}
int EvoPrefix_535(char arr_535[])
{
    Stack_535 *stack_535 = NULL;
    int op1_535;
    int op2_535;
    for (int i = strlen(arr_535) - 1; i >= 0; i--)
    {
        if (arr_535[i] >= '0' && arr_535[i] <= '9')
        {
            int num_535 = 0;
            int rev_535 = 0;
            while (arr_535[i] != ' ')
            {
                rev_535 *= 10;
                rev_535 += (int)arr_535[i--] - 48;
            }
            while (rev_535)
            {
                num_535 *= 10;
                num_535 += rev_535 % 10;
                rev_535 /= 10;
            }
            push_535(&stack_535, num_535);
            continue;
        }
        else if (arr_535[i] == '*' || arr_535[i] == '/' || arr_535[i] == '%')
        {
            op1_535 = top_535(stack_535);
            pop_535(&stack_535);
            op2_535 = top_535(stack_535);
            pop_535(&stack_535);
            push_535(&stack_535, operation_535(arr_535[i], op1_535, op2_535));
        }
        else if (arr_535[i] == '+' || arr_535[i] == '-' || arr_535[i] == '^')
        {
            op1_535 = top_535(stack_535);
            pop_535(&stack_535);
            op2_535 = top_535(stack_535);
            pop_535(&stack_535);
            push_535(&stack_535, operation_535(arr_535[i], op1_535, op2_535));
        }
    }
    return top_535(stack_535);
}

