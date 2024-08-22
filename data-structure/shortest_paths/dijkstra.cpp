#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 필요한 변수들
int V, E, start;
const int INF=9999999;
vector<pair<int, int>> graph[20001];
int distances[20001];

//q) relaxation = 그냥 거리 업데이트?? 제대로 이해한게 맞나 모르겠음

void init_graph(){
    cin >> V >> E >> start;
    for (int i=0; i<E ; i++){
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back(make_pair(c, b)); // distance, node pair
    }
    // distance INF 초기화
    for (int i=1; i<=V; i++){
        distances[i] = INF;
    }
}

void sssp_dijkstra(){
    priority_queue<pair<int,int>> pq;
    pq.push(make_pair(0, start)); // start distance = 0
    distances[start] = 0;

    while (!pq.empty()){
        int curr_distance = pq.top().first;
        int curr_node = pq.top().second;
        pq.pop();

        for (int i=0; i<graph[curr_node].size(); i++){
            int cost = graph[curr_node][i].first;
            int next_node = graph[curr_node][i].second;
            int next_cost = curr_distance + cost;

            if (distances[next_node] > next_cost){
                distances[next_node] = next_cost;
                pq.push(make_pair(next_cost, next_node));
            }
        }
    }
    for (int i=1; i<=V; i++){
        if (distances[i] == INF) cout << "INF" << endl;
        else cout << distances[i] << endl;

    }
}

int main(void){
    init_graph();
    sssp_dijkstra();

    return 0;
}