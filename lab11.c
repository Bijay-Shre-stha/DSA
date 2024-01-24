#include <stdio.h>

#define MAX_SIZE 3

struct Queue
{
    int items[MAX_SIZE];
    int front, rear;
};

void enqueue(struct Queue *q, int value)
{
    if (q->rear == MAX_SIZE - 1)
    {
        printf("Queue is Overflow. %d Cannot enqueue.\n", value);
        return;
    }

    q->items[++q->rear] = value;
    if (q->front == -1)
        q->front = 0;

    printf("Enqueued: %d\n", value);
}

void dequeue(struct Queue *q)
{
    if (q->front == -1 || q->front > q->rear)
    {
        printf("Queue is Underflow. Cannot dequeue.\n");
        return;
    }

    printf("Dequeued: %d\n", q->items[q->front++]);

    if (q->front > q->rear)
        q->front = q->rear = -1;
}

void display(struct Queue *q)
{
    if (q->front == -1)
    {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    for (int i = q->front; i <= q->rear; i++)
        printf("%d ", q->items[i]);
    printf("\n");
}

int main()
{
    struct Queue myQueue = {{0}, -1, -1};

    for (int i = 1; i <= MAX_SIZE; i++)
        enqueue(&myQueue, i * 10);
    display(&myQueue);

    enqueue(&myQueue, 40); // Overflow

    for (int i = 0; i < MAX_SIZE + 1; i++)
        dequeue(&myQueue); // Underflow
    display(&myQueue);

    return 0;
}
