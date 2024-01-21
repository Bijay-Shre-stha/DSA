#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 10

typedef struct {
    int front, rear;
    int queueArray[MAX_SIZE];
} LinearQueue;

void initializeQueue(LinearQueue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

bool isEmpty(const LinearQueue *queue) {
    return queue->front == -1;
}

bool isFull(const LinearQueue *queue) {
    return (queue->rear + 1) % MAX_SIZE == queue->front;
}

void enqueue(LinearQueue *queue, int value) {
    if (isFull(queue)) {
        printf("Queue full. Cannot enqueue %d\n", value);
        return;
    }

    if (isEmpty(queue))
        queue->front = 0;

    queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->queueArray[queue->rear] = value;
    printf("%d enqueued.\n", value);
}

void dequeue(LinearQueue *queue) {
    if (isEmpty(queue)) {
        printf("Queue empty. Cannot dequeue.\n");
        return;
    }

    printf("%d dequeued.\n", queue->queueArray[queue->front]);

    if (queue->front == queue->rear)
        initializeQueue(queue);
    else
        queue->front = (queue->front + 1) % MAX_SIZE;
}

void display(const LinearQueue *queue) {
    if (isEmpty(queue)) {
        printf("Queue empty.\n");
        return;
    }

    printf("Queue: ");
    for (int i = queue->front; i != (queue->rear + 1) % MAX_SIZE; i = (i + 1) % MAX_SIZE)
        printf("%d ", queue->queueArray[i]);
    printf("\n");
}

int main() {
    LinearQueue queue;
    initializeQueue(&queue);

    enqueue(&queue, 1);
    enqueue(&queue, 2);
    display(&queue);

    dequeue(&queue);

    enqueue(&queue, 3);
    display(&queue);

    return 0;
}
