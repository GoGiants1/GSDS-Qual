#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

int minDistance(vector<vector<int>>& points) {
    int num_points = points.size();
    if (num_points <= 1) return 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(num_points, INT_MAX);
    vector<bool> visited(num_points, false);
    vector<int> parent(num_points, -1);

    dist[0] = 0;
    pq.push({0, 0});
    int min_distance = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (visited[u]) continue;
        min_distance += dist[u];
        visited[u] = true;
        while (!pq.empty() && visited[pq.top().second]){ 
            pq.pop();
        }

        for (int v = 0; v < num_points; v++) {
            if (!visited[v]) {
                int weight = abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]);
                if (weight < dist[v]) {
                    dist[v] = weight;
                    pq.push({dist[v], v});
                }
            }
        }
    }
    return min_distance;
}
