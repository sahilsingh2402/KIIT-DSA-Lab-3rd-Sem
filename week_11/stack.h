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
}
