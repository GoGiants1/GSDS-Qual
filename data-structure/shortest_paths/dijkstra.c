#include <stdio.h>
#include <limits.h>

#define V 5  // 그래프의 정점 수

int minDistance(int dist[], int sptSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == 0 && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

void printPath(int parent[], int j) {
    // Base Case : If j is source
    if (parent[j] == -1)
        return;

    printPath(parent, parent[j]);

    printf("%d ", j);
}

void printSolution(int dist[], int parent[]) {
    int src = 0;
    printf("Vertex\t  Distance\tPath");
    for (int i = 1; i < V; i++) {
        printf("\n%d -> %d \t\t %d\t\t%d ", src, i, dist[i], src);
        printPath(parent, i);
    }
    printf("\n");
}

void dijkstra(int graph[V][V], int src) {
    int dist[V];
    int sptSet[V]; 
    int parent[V]; 

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = 0;
        parent[i] = -1;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet);
        sptSet[u] = 1;

        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    printSolution(dist, parent);
}

int main() {
    int graph[V][V] = { {0, 10, 0, 0, 5},
                        {0, 0, 1, 0, 2},
                        {0, 0, 0, 4, 0},
                        {7, 0, 6, 0, 0},
                        {0, 3, 9, 2, 0} };

    dijkstra(graph, 0);

    return 0;
}