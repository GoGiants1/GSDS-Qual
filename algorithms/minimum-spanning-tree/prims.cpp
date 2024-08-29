// Given a connected, weighted, undirected graph 𝐺, find an MST of 𝐺
// Let 𝐴 be a set of edges such that 𝐴 ⊆ 𝑇, where is an MST 𝑇

// Prim’s algorithm (Greedy Algorithm)
// The set A forms a single tree
// The safe edge added to A is always a lowest-weight edge connecting the tree to a vetex not in the tree

// 컴퓨팅 과목 PPT에 나와있는 예로 풀어보았어요
// https://imgur.com/NJRecal.png 이미지 여기서 확인 가능!
// g++ -std=c++14 -o prims prims.cpp

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
typedef pair<int, int> p;

int n = 9;
vector<p> adj[10];
bool visit[10];

struct compare {
    bool operator()(p a, p b) {
        return a.second > b.second;
    }
};

void Prims() {
    priority_queue<p, vector<p>, compare> pque;

    for(int i = 0; i < adj[1].size(); i++) pque.push(adj[1][i]);
    visit[1] = true;

    int count = 0;
    int mst_weight = 0;

    while (count < n - 1) {
        p curline = pque.top();
        pque.pop();

        int node = curline.first;
        int weight = curline.second;

        if (visit[node]) continue;
        visit[node] = true;
        count++;
        mst_weight += weight;

        cout << node << "번 정점 발견 : 비용 " << weight << endl;

        for (int i = 0; i < adj[node].size(); i++) {
            int nextnode = adj[node][i].first;
            if (!visit[nextnode]) pque.push(adj[node][i]);
        }
    }
    cout << "MST 총 비용: " << mst_weight << endl;
}

void init() {
    // Adding edges as per the graph in the image (undirected)
    // adj[a]번째 노드와 {b, }번째 노드간의 간선이 {, c}의 가중치 가짐
    adj[1].push_back({ 2, 4 });
    adj[1].push_back({ 8, 8 });
    adj[2].push_back({ 1, 4 });
    adj[2].push_back({ 3, 8 });
    adj[2].push_back({ 8, 11 });
    adj[3].push_back({ 2, 8 });
    adj[3].push_back({ 4, 7 });
    adj[3].push_back({ 6, 4 });
    adj[3].push_back({ 9, 2 });
    adj[4].push_back({ 3, 7 });
    adj[4].push_back({ 5, 9 });
    adj[4].push_back({ 6, 14 });
    adj[5].push_back({ 4, 9 });
    adj[5].push_back({ 6, 10 });
    adj[6].push_back({ 3, 4 });
    adj[6].push_back({ 4, 14 });
    adj[6].push_back({ 5, 10 });
    adj[6].push_back({ 7, 2 });
    adj[7].push_back({ 6, 2 });
    adj[7].push_back({ 8, 1 });
    adj[7].push_back({ 9, 6 });
    adj[8].push_back({ 1, 8 });
    adj[8].push_back({ 2, 11 });
    adj[8].push_back({ 7, 1 });
    adj[8].push_back({ 9, 7 });
    adj[9].push_back({ 3, 2 });
    adj[9].push_back({ 7, 6 });
    adj[9].push_back({ 8, 7 });
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(NULL);

    init();

    cout << "[MST]" << endl;
    Prims();

    return 0;
}