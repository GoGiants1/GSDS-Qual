#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Stack {
    Node* top;
    int size;
} Stack;

Stack* createStack() {
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->top = NULL;
    s->size = 0;
    return s;
}

int empty(Stack* s) {
    return s->size == 0;
}

int size(Stack* s) {
    return s->size;
}

void push(Stack* s, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = s->top;
    s->top = newNode;
    s->size++;
}

int pop(Stack* s) {
    if (empty(s)) {
        printf("Stack is empty\n");
        return -1;
    }
    Node* temp = s->top;
    int data = temp->data;
    s->top = s->top->next;
    s->size--;
    free(temp);
    return data;
}

int top(Stack* s) {
    if (empty(s)) {
        printf("Stack is empty\n");
        return -1;
    }
    return s->top->data;
}

int main() {
    Stack* s = createStack();
    push(s, 10);
    push(s, 20);
    push(s, 30);
    printf("%d\n", size(s)); // 3
    if (empty(s)) printf("s is empty\n");
    else printf("s is not empty\n");
    pop(s);
    printf("%d\n", top(s)); // 20
    pop(s);
    printf("%d\n", top(s)); // 10
    pop(s);
    if (empty(s)) printf("s is empty\n");
    printf("%d\n", top(s)); // Stack is empty
    return 0;
}
