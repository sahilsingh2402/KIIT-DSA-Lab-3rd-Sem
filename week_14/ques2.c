#include <stdio.h>
#include <stdlib.h>

struct Edge;
typedef struct Node
{
    int data;
    int visited_status;
    struct Edge *edges;
    struct Node *link;
} Node;
typedef struct Node Node;
typedef struct Stack
{
    Node *data;
    struct Stack *link;
} Stack;
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
typedef struct Edge
{
    struct Node *dest;
    struct Edge *link;
} Edge;
typedef struct Graph
{
    int size;
    struct Node *start;
} Graph;
int isEmpty(Queue *);
void enqueue(Queue *, Node *);
Node *dequeue(Queue *);
Node *peek(Queue *);
int isEmpty_stack(Stack *);
void push(Stack **, Node *);
Node *pop(Stack **);
void add_node(Graph *);
void insert_edges(Graph *, int, int);
void BFS(Graph *, int);
void DFS(Graph *, int);
void display(Graph);
int main()
{
    printf("Note: The graphs are directed and 1 based indexed!\n");
    printf("There can be more than one edge between a source and a destination.\n\n");
    Graph graph = {0, NULL};
    int choice;
    unsigned int vartex_1, vartex_2;
    do
    {
        printf("Current amount of nodes in graph: (%d)\n", graph.size);
        printf("1) Add a Node\n2) Add an edge\n3) Depth First Traversal\n");
        printf("4) Breadth First Traversal\n5) Display raw structure\n6) Exit\n->: ");
        scanf("%d", &choice);
        printf("\n");
        switch (choice)
        {
        case 1:
            add_node(&graph);
            break;
        case 2:
            printf("\nEnter the pair of vertices ");
            printf("(To and From, space separated): ");
            scanf("%d%d", &vartex_1, &vartex_2);
            insert_edges(&graph, vartex_1, vartex_2);
            break;
        case 3:
            printf("Enter a starting node: ");
            scanf("%d", &vartex_1);
            printf("BFS: ");
            BFS(&graph, vartex_1);
            break;
        case 4:
            printf("Enter a starting node: ");
            scanf("%d", &vartex_1);
            printf("DFS: ");
            DFS(&graph, vartex_1);
            break;
        case 5:
            display(graph);
        default:
            printf("Exiting...\n");
        }
        printf("----------------------------------\n");
    } while (choice >= 1 && choice <= 5);
    return 0;
}
void createGraph(Graph *graph, int nodes)
{
    int count = 1;
    Node *follow = NULL;
    graph->size = nodes;
    while (nodes--)
    {
        Node *temp = (Node *)malloc(sizeof(Node));
        temp->data = count++;
        temp->edges = NULL;
        temp->link = NULL;
        if (!follow)
        {
            graph->start = follow = temp;
            continue;
        }
        follow->link = temp;
        follow = temp;
    }
}
void add_node(Graph *graph)
{
    Node *lastNode = graph->start;
    if (!lastNode)
    {
        graph->size++;
        graph->start = (Node *)malloc(sizeof(Node));
        graph->start->data = graph->size;
        graph->start->edges = NULL;
        graph->start->link = NULL;
        return;
    }
    while (lastNode->link)
        lastNode = lastNode->link;
    lastNode->link = (Node *)malloc(sizeof(Node));
    lastNode->link->data = ++graph->size;
    lastNode->link->edges = NULL;
    lastNode->link->link = NULL;
}
void insert_edges_util(Graph *graph, Node **node, int vartex_2)
{
    if (vartex_2 < 1 || vartex_2 > graph->size)
        return;
    Node *start = graph->start;
    while (start)
    {
        if (start->data == vartex_2)
        {
            Node *temp_node = *node;
            Edge *temp = (Edge *)malloc(sizeof(Edge));
            temp->dest = start;
            temp->link = NULL;
            if (!temp_node->edges)
            {
                temp_node->edges = temp;
                return;
            }
            while (temp_node->edges->link)
                temp_node->edges = temp_node->edges->link;
            temp_node->edges->link = temp;
            return;
        }
        start = start->link;
    }
}
void insert_edges(Graph *graph, int vartex_1, int vartex_2)
{
    if (vartex_1 < 1 || vartex_1 > graph->size)
        return;
    else if (vartex_2 < 1 || vartex_2 > graph->size)
        return;
    Node *start = graph->start;
    while (start)
    {
        if (start->data == vartex_1)
        {
            insert_edges_util(graph, &start, vartex_2);
            return;
        }
        start = start->link;
    }
}
void BFS(Graph *graph, int val_start)
{
    if (!graph->start)
        return;
    Node *temp = graph->start;
    Node *start = NULL;
    while (temp)
    {
        if (val_start == temp->data)
            start = temp;
        temp->visited_status = 0;
        temp = temp->link;
    }
    Queue queue = {NULL, NULL};
    enqueue(&queue, start);
    start->visited_status = 1;
    while (!isEmpty(&queue))
    {
        temp = dequeue(&queue);
        printf("%d->", temp->data);
        Edge *temp_edges = temp->edges;
        while (temp_edges)
        {
            if (temp_edges->dest->visited_status == 0)
            {
                enqueue(&queue, temp_edges->dest);
                temp_edges->dest->visited_status = 1;
            }
            temp_edges = temp_edges->link;
        }
    }
    printf("\b\b \n");
}
void DFS(Graph *graph, int val_start)
{
    if (!graph->start)
        return;
    Node *temp = graph->start;
    Node *start = NULL;
    while (temp)
    {
        if (val_start == temp->data)
            start = temp;
        temp->visited_status = 0;
        temp = temp->link;
    }
    Stack *stack = NULL;
    push(&stack, start);
    start->visited_status = 1;
    while (!isEmpty_stack(stack))
    {
        temp = pop(&stack);
        printf("%d->", temp->data);
        Edge *temp_edges = temp->edges;
        while (temp_edges)
        {
            if (temp_edges->dest->visited_status == 0)
            {
                push(&stack, temp_edges->dest);
                temp_edges->dest->visited_status = 1;
            }
            temp_edges = temp_edges->link;
        }
    }
    printf("\b\b \n");
}
void display(Graph graph)
{
    while (graph.start)
    {
        printf("%d-> ", graph.start->data);
        Edge *edge = graph.start->edges;
        while (edge)
        {
            printf("%d, ", edge->dest->data);
            edge = edge->link;
        }
        printf("\b\b \n");
        graph.start = graph.start->link;
    }
    printf("\b\b\b \n");
}
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

