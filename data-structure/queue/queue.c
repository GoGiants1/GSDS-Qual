#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

typedef struct{
  int items[SIZE];
  int rear, front;
} Queue;

void init(Queue *Q){
  Q->rear = Q->front = -1;
}

int isEmpty(Queue *Q){
    return (Q->front == -1);
}

int isFull(Queue *Q){
    return (Q->rear == SIZE - 1);
}

void enqueue(Queue *Q, int data){
    if(isFull(Q)){
        printf("Overflow\n");
        return;
    }
    if (Q->front == -1) {Q->front = 0;}  // 첫 요소 추가 시 front를 0으로 설정
    Q->items[++Q->rear] = data;
    return;
}

int dequeue(Queue *Q){
    if(isEmpty(Q)){
        printf("The queue is empty.\n");
        return -1;
    }
    int item = Q->items[Q->front];
    Q->front++;
    if (Q->front > Q->rear) {  // 마지막 요소가 제거된 경우 큐를 초기화
        Q->front = Q->rear = -1;
    }
    return item;
}

int peek(Queue *Q){
    if (isEmpty(Q)){
        printf("The queue is empty.\n");
        return -1;
    }
    return Q->items[Q->front];
}

void printQueue(Queue *Q){
    if (isEmpty(Q)){
        printf("The queue is empty.\n");
        return;
    }
    for (int i = Q->front; i <= Q->rear; i++){
        printf("%d -> ", Q->items[i]);
    }
    printf("NULL\n");
    return;
}

int main() {
    Queue q;
    init(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    printf("Removed %d\n", dequeue(&q));
    printf("Front item is %d\n", peek(&q));

    printQueue(&q);

    return 0;
}