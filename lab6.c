#include <stdio.h>

#define MAX_SIZE 100

typedef struct {
    int top;
    int values[MAX_SIZE];
} Stack;

void initStack(Stack *stack) {
    stack->top = -1;
}

int isEmpty(Stack *stack) {
    return stack->top == -1;
}

int isFull(Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

void push(Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Error: Stack overflow\n");
        return;
    }
    stack->values[++stack->top] = value;
}

int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Error: Stack underflow\n");
        return -1;
    }
    return stack->values[stack->top--];
}

int peek(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Error: Stack is empty\n");
        return -1;
    }
    return stack->values[stack->top];
}

int main() {
    Stack myStack;
    initStack(&myStack);

    push(&myStack, 10);
    push(&myStack, 20);
    push(&myStack, 30);

    printf("Top: %d\n", peek(&myStack));

    while (!isEmpty(&myStack)) {
        printf("Pop: %d\n", pop(&myStack));
    }

    if (isEmpty(&myStack)) {
        printf("Stack is empty\n");
    }

    return 0;
}
