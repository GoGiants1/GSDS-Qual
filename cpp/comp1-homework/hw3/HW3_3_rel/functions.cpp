#include <climits>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

void flightRoute(const int n, const int m,
                 const vector<vector<int>>& route_info) {
  vector<vector<pair<int, int>>> adj(n + 1);

  for (auto info : route_info) {
    // vector 형태여서 tie 사용 불가..?
    adj[info[0]].push_back({info[1], info[2]});
  }

  vector<long> min_cost(n + 1, LONG_MAX);
  vector<long> count_routes(n + 1, 0);
  vector<int> min_flights(n + 1, INT_MAX);
  vector<int> max_flights(n + 1, 0);
  priority_queue<pair<long, int>, vector<pair<long, int>>,
                 greater<pair<long, int>>>
      pq;  // cost, city

  min_cost[1] = 0;
  count_routes[1] = 1;
  min_flights[1] = 0;
  max_flights[1] = 0;
  pq.push({0, 1});

  while (!pq.empty()) {
    long cost;
    int u;
    tie(cost, u) = pq.top();
    pq.pop();
    if (cost > min_cost[u]) continue;

    for (const auto p : adj[u]) {
      int v;
      long weight;
      tie(v, weight) = p;
      long new_cost = cost + weight;
      int new_min_flights = min_flights[u] + 1;
      int new_max_flights = max_flights[u] + 1;

      if (new_cost < min_cost[v]) {
        // Relaxation
        min_cost[v] = new_cost;
        count_routes[v] = count_routes[u];
        pq.push({new_cost, v});
        min_flights[v] = new_min_flights;
        max_flights[v] = new_max_flights;
      } else if (new_cost == min_cost[v]) {
        count_routes[v] = (count_routes[v] + count_routes[u]) % INT_MAX;
        min_flights[v] = min(min_flights[v], new_min_flights);
        max_flights[v] = max(max_flights[v], new_max_flights);
      }
    }
  }

  cout << min_cost[n] << " " << count_routes[n] << " " << min_flights[n] << " "
       << max_flights[n];
}
