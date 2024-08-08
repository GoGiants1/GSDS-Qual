#include <stdio.h>

#define QUEUE_SIZE 100

typedef struct {
    int arr[QUEUE_SIZE];
    int frontIndex;
    int backIndex;
} Queue;

void initialize(Queue* queue) {
    queue->frontIndex = 0;
    queue->backIndex = 0;
}

int front(Queue* queue) {
    if (queue->frontIndex == queue->backIndex) {
        printf("Queue is empty!\n");
        return -1;
    }
    return queue->arr[queue->frontIndex];
}

int back(Queue* queue) {
    if (queue->frontIndex == queue->backIndex) {
        printf("Queue is empty!\n");
        return -1;
    }
    return queue->arr[queue->backIndex - 1];
}

int empty(Queue* queue) {
    return queue->frontIndex == queue->backIndex;
}

int size(Queue* queue) {
    return queue->backIndex - queue->frontIndex;
}

void push(Queue* queue, int value) {
    if (queue->backIndex == QUEUE_SIZE) {
        printf("Queue is full!\n");
        return;
    }
    queue->arr[queue->backIndex++] = value;
}

void pop(Queue* queue) {
    if (queue->frontIndex == queue->backIndex) {
        printf("Queue is empty!\n");
        return;
    }
    queue->frontIndex++;
}

void printQueue(Queue* queue){
    printf("Queue : ");
    for (int i=0; i<size(queue); i++){
        printf("%d ", queue->arr[i]);
    }
    printf("\n");
}

int main() {
    Queue queue;
    initialize(&queue);

    printf("Pushing elements into the queue:\n");
    for (int i = 1; i <= 5; i++) {
        push(&queue, i);
        printf("Pushed %d, Front: %d, Back: %d, Size: %d\n", i, front(&queue), back(&queue), size(&queue));
    }
    printQueue(&queue);

    printf("\nPopping elements from the queue:\n");
    while (!empty(&queue)) {
        printf("Front: %d, Back: %d, Size: %d\n", front(&queue), back(&queue), size(&queue));
        pop(&queue);
    }
    printQueue(&queue);

    printf("\nAttempt to pop from an empty queue:\n");
    pop(&queue);

    return 0;
}
