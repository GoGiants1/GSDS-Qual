#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 6

typedef struct {
    int *array;
    int size;
} Vector;

typedef struct {
    int items[MAX_VERTICES];
    int front, rear;
} Queue;

void initVector(Vector *v, int size) {
    v->array = (int *)malloc(size * sizeof(int));
    v->size = 0;
}

void push_back(Vector *v, int value) {
    v->array[v->size++] = value;
}

void initQueue(Queue *q) {
    q->front = 0;
    q->rear = 0;
}

int isEmpty(Queue *q) {
    return q->front == q->rear;
}

void enqueue(Queue *q, int value) {
    q->items[q->rear++] = value;
}

int dequeue(Queue *q) {
    return q->items[q->front++];
}

void topologicalSort(int vertices, Vector adjList[]) {
    int inDegree[MAX_VERTICES] = {0};
    int result[MAX_VERTICES];
    Queue q;
    initQueue(&q);

    // 각 노드의 진입 차수를 계산합니다.
    for (int node = 0; node < vertices; node++) {
        for (int j = 0; j < adjList[node].size; j++) {
            int neighbor = adjList[node].array[j];
            inDegree[neighbor]++;
        }
    }

    // 진입 차수가 0인 노드를 큐에 삽입합니다.
    for (int i = 0; i < vertices; i++) {
        if (inDegree[i] == 0) {
            enqueue(&q, i);
        }
    }

    // 큐에서 노드를 하나씩 꺼내면서 위상 정렬을 수행합니다.
    int index = 0;
    while (!isEmpty(&q)) {
        int node = dequeue(&q);
        result[index++] = node;

        for (int j = 0; j < adjList[node].size; j++) {
            int neighbor = adjList[node].array[j];
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0) {
                enqueue(&q, neighbor);
            }
        }
    }

    // 모든 노드를 방문했는지 확인합니다.
    if (index == vertices) {
        printf("Topological Sort: ");
        for (int i = 0; i < index; i++) {
            printf("%d ", result[i]);
        }
        printf("\n");
    } else {
        printf("Cycle detected! Topological sort not possible.\n");
    }
}

int main() {
    int vertices = 6;
    Vector adjList[MAX_VERTICES];

    // 그래프를 정의합니다.
    for (int i = 0; i < vertices; i++) {
        initVector(&adjList[i], vertices);
    }

    push_back(&adjList[5], 2);
    push_back(&adjList[5], 0);
    push_back(&adjList[4], 0);
    push_back(&adjList[4], 1);
    push_back(&adjList[2], 3);
    push_back(&adjList[3], 1);

    topologicalSort(vertices, adjList);

    for (int i = 0; i < vertices; i++) {
        free(adjList[i].array);
    }

    return 0;
}