#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define V 9

// gcc -o prims prims.c

int minWeight(int weight[], bool mstSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && weight[v] < min)
            min = weight[v], min_index = v;

    return min_index;
}

void printMST(int parent[], int graph[V][V]) {
    int total_weight = 0;
    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++) {
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
        total_weight += graph[i][parent[i]];
    }
    printf("MST 총 비용: %d\n", total_weight);
}

void Prim(int graph[V][V]) {
    int parent[V];
    int weight[V];
    bool mstSet[V];

    for (int i = 0; i < V; i++)
        weight[i] = INT_MAX, mstSet[i] = false;

    weight[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {
        int u = minWeight(weight, mstSet);

        mstSet[u] = true;

        for (int v = 0; v < V; v++)
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < weight[v])
                parent[v] = u, weight[v] = graph[u][v];
    }

    printMST(parent, graph);
}

int main() {
    int graph[V][V] = {
        {0, 4, 0, 0, 0, 0, 0, 8, 0},
        {4, 0, 8, 0, 0, 0, 0, 11, 0},
        {0, 8, 0, 7, 0, 4, 0, 0, 2},
        {0, 0, 7, 0, 9, 14, 0, 0, 0},
        {0, 0, 0, 9, 0, 10, 0, 0, 0},
        {0, 0, 4, 14, 10, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 2, 0, 1, 6},
        {8, 11, 0, 0, 0, 0, 1, 0, 7},
        {0, 0, 2, 0, 0, 0, 6, 7, 0}};

    Prim(graph);

    return 0;
}
