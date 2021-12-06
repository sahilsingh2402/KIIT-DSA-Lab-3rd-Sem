#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Stack_535
{
    char data_535;
    struct Stack_535 *link_535;
} Stack_535;
void push_535(Stack_535 **, char);
void pop_535(Stack_535 **);
char top_535(Stack_535 *);
int isEmpty_535(Stack_535 *);
int higherPrecedence_535(char, char);
char *InfixToPrefix_535(char[]);
int main()
{
    char str_535[100];
    printf("Infix: ");
    scanf(" %[^\n]s", str_535);
    char *arr_535 = InfixToPrefix_535(str_535);
    printf("Prefix: %s\n", arr_535);
    free(arr_535);
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
        return '\0';
    return stack_535->data_535;
}
int isEmpty_535(Stack_535 *stack_535)
{
    if (!stack_535)
        return 1;
    return 0;
}
int higherPrecedence_535(char ch1, char ch2) //Returns 1 if stack operator has equal or
{                                            //higher precedence than scanned operator
    if (ch1 == '^')
        return 1;
    else if (ch1 == '*' && (ch2 == '+' || ch2 == '-' || ch2 == '/' || ch2 == '%' || ch2 == '*'))
        return 1;
    else if (ch1 == '/' && (ch2 == '+' || ch2 == '-' || ch2 == '/' || ch2 == '%' || ch2 == '*'))
        return 1;
    else if (ch1 == '%' && (ch2 == '+' || ch2 == '-' || ch2 == '/' || ch2 == '%' || ch2 == '*'))
        return 1;
    else if (ch1 == '+' && (ch2 == '+' || ch2 == '-'))
        return 1;
    else if (ch1 == '-' && (ch2 == '+' || ch2 == '-'))
        return 1;
    return 0;
}
char *InfixToPrefix_535(char str_535[])
{
    Stack_535 *stack_535 = NULL;
    int j = 0;
    char *arr_535 = (char *)malloc(strlen(str_535) * sizeof(char));
    for (int i = strlen(str_535) - 1; i >= 0; i--)
    {
        if (str_535[i] == '(')
        { //evaluate all expressions after closing parentheses
            while (!isEmpty_535(stack_535) && (top_535(stack_535) != ')'))
            {
                arr_535[j++] = top_535(stack_535);
                pop_535(&stack_535);
            }
            pop_535(&stack_535);
            continue;
        }
        if ((str_535[i] >= 'a' && str_535[i] <= 'z') || (str_535[i] >= 'A' && str_535[i] <= 'Z'))
        {
            arr_535[j++] = str_535[i];
            continue;
        }
        //operator input in stack_535
        while (!isEmpty_535(stack_535) &&
               higherPrecedence_535(top_535(stack_535), str_535[i]))
        {
            arr_535[j++] = top_535(stack_535);
            pop_535(&stack_535);
        }
        push_535(&stack_535, str_535[i]);
    }
    while (!isEmpty_535(stack_535))
    {
        if (top_535(stack_535) != ')')
            arr_535[j++] = top_535(stack_535);
        pop_535(&stack_535);
    }
    for (int i = 0, j = strlen(arr_535) - 1; i <= strlen(arr_535) / 2; i++, j--)
    {
        char temp_535 = arr_535[i];
        arr_535[i] = arr_535[j];
        arr_535[j] = temp_535;
    }
    return arr_535;
}

