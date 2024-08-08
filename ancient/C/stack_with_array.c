#include <stdio.h>
#define MAX_SIZE 1000

typedef struct Stack {
    int data[MAX_SIZE];
    int size;
} Stack;

void init(Stack* s) {
    s->size = 0;
}

int empty(Stack* s) {
    return s->size == 0;
}

int size(Stack* s) {
    return s->size;
}

void push(Stack* s, int data) {
    if (s->size < MAX_SIZE) {
        s->data[s->size] = data;
        s->size++;
    } else {
        printf("Stack is full\n");
    }
}

int pop(Stack* s) {
    if (empty(s)) {
        printf("Stack is empty\n");
        return -1;
    }
    s->size--;
    return s->data[s->size];
}

int top(Stack* s) {
    if (empty(s)) {
        printf("Stack is empty\n");
        return -1;
    }
    return s->data[s->size - 1];
}

int main() {
    Stack s;
    init(&s);
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    printf("%d\n", size(&s)); // 3
    if (empty(&s)) printf("s is empty\n");
    else printf("s is not empty\n");
    pop(&s);
    printf("%d\n", top(&s)); // 20
    pop(&s);
    printf("%d\n", top(&s)); // 10
    pop(&s);
    if (empty(&s)) printf("s is empty\n");
    printf("%d\n", top(&s)); // Stack is empty
    return 0;
}
