#include <stdio.h>

#define MAX_SIZE 1

struct Stack {
    int arr[MAX_SIZE];
    int top;
};

void initStack(struct Stack *stack) {
    stack->top = -1;
}

int isFull(struct Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

int isEmpty(struct Stack *stack) {
    return stack->top == -1;
}

void display(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack elements: ");
    for (int i = 0; i <= stack->top; i++)
        printf("%d ", stack->arr[i]);
    
    printf("\n");
}

void push(struct Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Stack overflow, cannot push %d\n", value);
        return;
    }

    stack->arr[++stack->top] = value;
    printf("%d pushed to stack\n", value);
}

int pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow, cannot pop\n");
        return -1;
    }

    printf("Popped element: %d\n", stack->arr[stack->top--]);
}

int main() {
    struct Stack myStack;
    initStack(&myStack);

    push(&myStack, 10);
    push(&myStack, 20);

    display(&myStack);

    pop(&myStack);
    pop(&myStack);

    display(&myStack);

    return 0;
}
