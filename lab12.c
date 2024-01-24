#include <stdio.h>

#define MAX_SIZE 5

struct CircularQueue {
    int front, rear;
    int array[MAX_SIZE];
};

void initializeQueue(struct CircularQueue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

int isFull(struct CircularQueue *queue) {
    return (queue->front == (queue->rear + 1) % MAX_SIZE);
}

int isEmpty(struct CircularQueue *queue) {
    return (queue->front == -1 && queue->rear == -1);
}

void enqueue(struct CircularQueue *queue, int element) {
    if (isFull(queue)) {
        printf("Queue is full. Enqueue operation cannot be performed.\n");
    } else {
        if (isEmpty(queue)) queue->front = 0;
        queue->rear = (queue->rear + 1) % MAX_SIZE;
        queue->array[queue->rear] = element;
        printf("Enqueued %d to the circular queue.\n", element);
    }
}

void dequeue(struct CircularQueue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Dequeue operation cannot be performed.\n");
    } else {
        printf("Dequeued %d from the circular queue.\n", queue->array[queue->front]);

        if (queue->front == queue->rear) initializeQueue(queue);
        else queue->front = (queue->front + 1) % MAX_SIZE;
    }
}

void display(struct CircularQueue *queue) {
    if (isEmpty(queue)) printf("Queue is empty.\n");
    else {
        int i = queue->front;
        printf("Elements in the circular queue: ");
        do {
            printf("%d ", queue->array[i]);
            i = (i + 1) % MAX_SIZE;
        } while (i != (queue->rear + 1) % MAX_SIZE);
        printf("\n");
    }
}

int main() {
    struct CircularQueue queue;
    initializeQueue(&queue);

    enqueue(&queue, 1);
    enqueue(&queue, 2);
    display(&queue);

    dequeue(&queue);

    enqueue(&queue, 3);
    display(&queue);

    enqueue(&queue, 4); // This will print an error message as the queue is full

    return 0;
}
