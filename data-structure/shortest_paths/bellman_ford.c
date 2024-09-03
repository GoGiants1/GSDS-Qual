#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// 그래프의 간선을 나타내는 구조체
struct Edge {
    int src, dest, weight;
};

// 그래프 구조체
struct Graph {
    int V, E; // V: 정점 수, E: 간선 수
    struct Edge* edge; // 간선 배열
};

// 그래프 생성 함수
struct Graph* createGraph(int V, int E) {
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    graph->edge = (struct Edge*) malloc(graph->E * sizeof(struct Edge));
    return graph;
}

// 최단 경로를 출력하는 함수
void printArr(int dist[], int n) {
    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < n; ++i)
        printf("%d\t\t%d\n", i, dist[i]);
}

// 벨만-포드 알고리즘 함수
void BellmanFord(struct Graph* graph, int src) {
    int V = graph->V;
    int E = graph->E;
    int dist[V];

    // 초기화: 모든 거리를 무한대로 설정하고, 시작 정점의 거리는 0으로 설정
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;
    dist[src] = 0;

    // 각 간선을 V-1번 반복해서 업데이트
    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = graph->edge[j].src;
            int v = graph->edge[j].dest;
            int weight = graph->edge[j].weight;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }

    // 음수 사이클이 있는지 검사
    for (int i = 0; i < E; i++) {
        int u = graph->edge[i].src;
        int v = graph->edge[i].dest;
        int weight = graph->edge[i].weight;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            printf("Graph contains negative weight cycle\n");
            return;
        }
    }

    printArr(dist, V);
}

int main() {
    int V = 5; // 정점 수
    int E = 8; // 간선 수
    struct Graph* graph = createGraph(V, E);

    // 간선 추가: src, dest, weight
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].weight = -1;

    graph->edge[1].src = 0;
    graph->edge[1].dest = 2;
    graph->edge[1].weight = 4;

    graph->edge[2].src = 1;
    graph->edge[2].dest = 2;
    graph->edge[2].weight = 3;

    graph->edge[3].src = 1;
    graph->edge[3].dest = 3;
    graph->edge[3].weight = 2;

    graph->edge[4].src = 1;
    graph->edge[4].dest = 4;
    graph->edge[4].weight = 2;

    graph->edge[5].src = 3;
    graph->edge[5].dest = 2;
    graph->edge[5].weight = 5;

    graph->edge[6].src = 3;
    graph->edge[6].dest = 1;
    graph->edge[6].weight = 1;

    graph->edge[7].src = 4;
    graph->edge[7].dest = 3;
    graph->edge[7].weight = -3;

    BellmanFord(graph, 0);

    free(graph->edge);
    free(graph);

    return 0;
}