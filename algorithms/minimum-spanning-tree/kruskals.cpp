// Given a connected, weighted, undirected graph 𝐺, find an MST of 𝐺
// Let 𝐴 be a set of edges such that 𝐴 ⊆ 𝑇, where is an MST 𝑇

// Kruskal’s algorithm (= Greedy Algorithm)
// The set A is a forest whose vertices are all those of the given graph
// The safe edge added to A is always a lowest-wegith edge in the graph that connects two distinct components

// 컴퓨팅 과목 PPT에 나와있는 예로 풀어보았어요
// https://imgur.com/NJRecal.png 이미지 여기서 확인 가능!
// g++ -std=c++14 -o kruskals kruskals.cpp

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
typedef pair<int, int> p;

int n = 9;
vector<pair<int, p>> edges;
int parent[10];

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) parent[y] = x;
}

void Kruskals() {
    sort(edges.begin(), edges.end());

    int count = 0;
    int mst_weight = 0;

    for (auto edge : edges) {
        int weight = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;

        if (find(u) != find(v)) {
            unite(u, v);
            mst_weight += weight;
            count++;

            cout << u << " - " << v << "번 정점 연결: 비용 " << weight << endl;
            if (count == n - 1) break;
        }
    }
    cout << "MST 총 비용: " << mst_weight << endl;
}

void init() {
    for (int i = 1; i <= n; i++) parent[i] = i;

    // Adding edges as per the graph in the image (undirected)
    // {4, {1, 2}}: 4의 가중치를 가지는 edge가 node 1과 2의 간선임
    edges.push_back({4, {1, 2}});
    edges.push_back({8, {1, 8}});
    edges.push_back({4, {2, 1}});
    edges.push_back({8, {2, 3}});
    edges.push_back({11, {2, 8}});
    edges.push_back({8, {3, 2}});
    edges.push_back({7, {3, 4}});
    edges.push_back({4, {3, 6}});
    edges.push_back({2, {3, 9}});
    edges.push_back({7, {4, 3}});
    edges.push_back({9, {4, 5}});
    edges.push_back({14, {4, 6}});
    edges.push_back({9, {5, 4}});
    edges.push_back({10, {5, 6}});
    edges.push_back({4, {6, 3}});
    edges.push_back({14, {6, 4}});
    edges.push_back({10, {6, 5}});
    edges.push_back({2, {6, 7}});
    edges.push_back({2, {7, 6}});
    edges.push_back({1, {7, 8}});
    edges.push_back({6, {7, 9}});
    edges.push_back({8, {8, 1}});
    edges.push_back({11, {8, 2}});
    edges.push_back({1, {8, 7}});
    edges.push_back({7, {8, 9}});
    edges.push_back({2, {9, 3}});
    edges.push_back({6, {9, 7}});
    edges.push_back({7, {9, 8}});
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(NULL);

    init();

    cout << "[MST]" << endl;
    Kruskals();

    return 0;
}