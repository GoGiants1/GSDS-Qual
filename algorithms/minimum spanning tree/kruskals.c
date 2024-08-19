#include <stdio.h>
#include <stdlib.h>

#define V 9
#define E 28

typedef struct {
    int u, v, weight;
} Edge;

Edge edges[E];
int parent[V + 1];

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) parent[y] = x;
}

int compare(const void *a, const void *b) {
    Edge *edgeA = (Edge *)a;
    Edge *edgeB = (Edge *)b;
    return edgeA->weight - edgeB->weight;
}

void Kruskals() {
    qsort(edges, E, sizeof(Edge), compare);

    int count = 0;
    int mst_weight = 0;

    for (int i = 0; i < E; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int weight = edges[i].weight;

        if (find(u) != find(v)) {
            unite(u, v);
            mst_weight += weight;
            count++;
            printf("%d - %d번 정점 연결: 비용 %d\n", u, v, weight);
            if (count == V - 1) break;
        }
    }
    printf("MST 총 비용: %d\n", mst_weight);
}

void init() {
    for (int i = 1; i <= V; i++) parent[i] = i;

    // Adding edges as per the graph in the image (undirected)
    edges[0] = (Edge){1, 2, 4};
    edges[1] = (Edge){1, 8, 8};
    edges[2] = (Edge){2, 1, 4};
    edges[3] = (Edge){2, 3, 8};
    edges[4] = (Edge){2, 8, 11};
    edges[5] = (Edge){3, 2, 8};
    edges[6] = (Edge){3, 4, 7};
    edges[7] = (Edge){3, 6, 4};
    edges[8] = (Edge){3, 9, 2};
    edges[9] = (Edge){4, 3, 7};
    edges[10] = (Edge){4, 5, 9};
    edges[11] = (Edge){4, 6, 14};
    edges[12] = (Edge){5, 4, 9};
    edges[13] = (Edge){5, 6, 10};
    edges[14] = (Edge){6, 3, 4};
    edges[15] = (Edge){6, 4, 14};
    edges[16] = (Edge){6, 5, 10};
    edges[17] = (Edge){6, 7, 2};
    edges[18] = (Edge){7, 6, 2};
    edges[19] = (Edge){7, 8, 1};
    edges[20] = (Edge){7, 9, 6};
    edges[21] = (Edge){8, 1, 8};
    edges[22] = (Edge){8, 2, 11};
    edges[23] = (Edge){8, 7, 1};
    edges[24] = (Edge){8, 9, 7};
    edges[25] = (Edge){9, 3, 2};
    edges[26] = (Edge){9, 7, 6};
    edges[27] = (Edge){9, 8, 7};
}

int main() {
    init();

    printf("[MST]\n");
    Kruskals();

    return 0;
}
