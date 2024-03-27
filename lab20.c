#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev, *next;
};

struct Node* initialize() { return NULL; }

struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data, newNode->prev = NULL, newNode->next = head;
    if (head) head->prev = newNode;
    return newNode;
}

struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data, newNode->next = NULL;

    if (!head) return newNode;
    struct Node* current = head;
    while (current->next) current = current->next;

    current->next = newNode, newNode->prev = current;
    return head;
}

struct Node* insertAtPosition(struct Node* head, int data, int position) {
    if (position <= 0) return head;
    if (position == 1) return insertAtBeginning(head, data);

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    struct Node* current = head;
    for (int i = 1; i < position - 1 && current; i++) current = current->next;
    if (!current) return head;

    newNode->next = current->next;
    if (current->next) current->next->prev = newNode;
    current->next = newNode, newNode->prev = current;
    return head;
}

struct Node* deleteFromBeginning(struct Node* head) {
    if (!head) return NULL;
    struct Node* temp = head;
    head = head->next;
    if (head) head->prev = NULL;
    free(temp);
    return head;
}

struct Node* deleteFromEnd(struct Node* head) {
    if (!head) return NULL;
    if (!head->next) {
        free(head);
        return NULL;
    }
    struct Node* current = head;
    while (current->next) current = current->next;
    current->prev->next = NULL;
    free(current);
    return head;
}

struct Node* deleteFromPosition(struct Node* head, int position) {
    if (!head || position <= 0) return head;
    if (position == 1) return deleteFromBeginning(head);

    struct Node* current = head;
    for (int i = 1; i < position && current; i++) current = current->next;
    if (!current) return head;

    if (current->next) current->next->prev = current->prev;
    current->prev->next = current->next;
    free(current);
    return head;
}


void display(struct Node* head) {
    while (head) printf("%d ", head->data), head = head->next;
    printf("\n");
}

int main() {
    struct Node* head = initialize();
    head = insertAtBeginning(head, 5);
    head = insertAtEnd(head, 10);
    head = insertAtPosition(head, 7, 2);
    printf("After insertions: ");
    display(head);
    head = deleteFromBeginning(head);
    head = deleteFromPosition(head, 2);
    printf("After deletions: ");
    display(head);
    return 0;
}
