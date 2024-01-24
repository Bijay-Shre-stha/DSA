#include <stdio.h>

#define MAX_SIZE 10

struct Queue {
    int items[MAX_SIZE];
    int front, rear;
};

void enqueue(struct Queue *q, int value) {
    if (q->rear == MAX_SIZE - 1) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }

    q->items[++q->rear] = value;
    if (q->front == -1) {
        q->front = 0;
    }

    printf("Enqueued: %d\n", value);
}

void dequeue(struct Queue *q) {
    if (q->front == -1) {
        printf("Queue is empty. Cannot dequeue.\n");
        return;
    }

    printf("Dequeued: %d\n", q->items[q->front++]);

    if (q->front > q->rear) {
        q->front = -1;
        q->rear = -1;
    }
}

void display(struct Queue *q) {
    if (q->front == -1) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->items[i]);
    }
    printf("\n");
}

int main() {
    struct Queue myQueue = {{0}, -1, -1};

    enqueue(&myQueue, 10);
    enqueue(&myQueue, 20);
    enqueue(&myQueue, 30);

    display(&myQueue);

    dequeue(&myQueue);

    display(&myQueue);

    return 0;
}
