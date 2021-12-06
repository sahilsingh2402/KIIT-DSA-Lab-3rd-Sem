typedef struct Node Node;
typedef struct QueNode
{
	Node *data;
	struct QueNode *link;
} QueNode;

typedef struct Queue
{
	QueNode *front;
	QueNode *rear;
} Queue;

int isEmpty(Queue *que)
{
	if (que->front == NULL)
		return 1;
	return 0;
}

void enqueue(Queue *que, Node *data)
{
	QueNode *temp = (QueNode *)malloc(sizeof(QueNode));
	temp->data = data;
	temp->link = NULL;

	if (isEmpty(que))
	{
		que->front = que->rear = temp;
		return;
	}

	que->rear->link = temp;
	que->rear = que->rear->link;
}

Node *dequeue(Queue *que)
{
	if (isEmpty(que))
		return NULL;

	QueNode *temp = que->front;
	que->front = que->front->link;

	if (que->front == NULL)
		que->rear = NULL;

	Node *n = temp->data;
	free(temp);
	return n;
}

Node *peek(Queue *que)
{
	if (isEmpty(que))
		return NULL;
	return que->front->data;
}
