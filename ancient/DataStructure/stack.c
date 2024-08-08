#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int arr[MAX_SIZE];
    int top;
} Stack;

void initialize(Stack* stack) {
    stack->top = -1;
}

bool empty(Stack* stack) {
    return stack->top == -1;
}

int size(Stack* stack) {
    return stack->top + 1;
}

int top(Stack* stack) {
    if (empty(stack)) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->arr[stack->top];
}

void push(Stack* stack, int value) {
    if (stack->top >= MAX_SIZE - 1) {
        printf("Stack is full\n");
        return;
    }
    stack->arr[++stack->top] = value;
}

void printStack(Stack* stack){
    printf("Stack : ");
    for (int i=0; i<stack->top+1; i++){
        printf("%d ", stack->arr[i]);
    }
    printf("%c", '\n');
}

void pop(Stack* stack) {
    if (empty(stack)) {
        printf("Stack is empty\n");
        return;
    }
    stack->top--;
}

// Test case
int main() {
    Stack stack;
    initialize(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printStack(&stack);

    printf("Top element is: %d\n", top(&stack)); // 30
    printf("Size of stack: %d\n", size(&stack)); // 3
    printf("Is stack empty? %s\n", empty(&stack) ? "Yes" : "No"); // No

    pop(&stack);
    printStack(&stack);

    printf("Top element after pop is: %d\n", top(&stack)); // 20


    return 0;
}
