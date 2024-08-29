#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <vector>

#include "functions.hpp"

using namespace std;

int main() {
  vector<vector<int>> my_route;
  // 5 10 -> n m

  // 1 2 5
  // 1 3 5
  // 1 4 10
  // 1 4 10
  // 1 5 15
  // 1 5 15
  // 2 3 5
  // 2 4 10
  // 3 4 5
  // 4 5 5
  // int n = 5;
  // int m = 10;
  // my_route.push_back({1, 2, 5});
  // my_route.push_back({1, 3, 5});
  // my_route.push_back({1, 4, 10});
  // my_route.push_back({1, 4, 10});
  // my_route.push_back({1, 5, 15});
  // my_route.push_back({1, 5, 15});
  // my_route.push_back({2, 3, 5});
  // my_route.push_back({2, 4, 10});
  // my_route.push_back({3, 4, 5});
  // my_route.push_back({4, 5, 5});
  // flightRoute(n, m, my_route);

  int n, m;
  cin >> n >> m;
  vector<vector<int>> route_info(m, vector<int>(3));
  for (int i = 0; i < m; ++i) {
    cin >> route_info[i][0] >> route_info[i][1] >> route_info[i][2];
  }

  flightRoute(n, m, route_info);

  return 0;
}
