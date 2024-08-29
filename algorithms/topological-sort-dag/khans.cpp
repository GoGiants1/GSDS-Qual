/*
위상 정렬의 특징
DAG에서만 적용 가능: 위상 정렬은 사이클이 없는 방향 그래프(DAG)에서만
가능합니다. 사이클이 있는 그래프에서는 위상 정렬이 불가능합니다. 노드들의 선후
관계 유지: 위상 정렬은 각 노드가 가리키는 다음 노드보다 앞에 위치하도록
정렬합니다. 순서가 유일하지 않을 수 있음: 주어진 DAG에 대해 여러 개의 위상 정렬
결과가 있을 수 있습니다.

BFS 기반과 DFS 기반 두 가지 풀이 있음

BFS(Kahn's algo)
1. 모든 노드의 진입 차수를 계산합니다.
2. 진입 차수가 0인 노드를 큐에 삽입합니다.
3. 큐에서 노드를 하나씩 꺼내어 정렬 리스트에 추가합니다.
4. 꺼낸 노드와 연결된 모든 노드의 진입 차수를 1씩 감소시킵니다.
5. 진입 차수가 0이 된 노드를 큐에 추가합니다.
6. 큐가 빌 때까지 3~5번 과정을 반복합니다.
7. 모든 노드를 방문했다면 정렬된 리스트를 출력하고, 그렇지 않으면 사이클이
존재함을 의미합니다


# 큐 기본 함수
## 추가 및 삭제
- push(element): 큐에 원소를 추가(뒤에)
- pop(): 큐에 있는 원소를 삭제(앞에)
## 조회
- front(): 큐 제일 앞에 있는 원소를 반환
- back(): 큐 제일 뒤에 있는 원소를 반환
## 기타
- empty(): 큐가 비어있으면 true 아니면 false를 반환
- size(): 큐 사이즈를 반환

*/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void topologicalSort(int vertices, vector<vector<int>>& adjList) {
  vector<int> inDegree(vertices, 0);
  vector<int> result;
  queue<int> q;

  // 각 노드의 진입 차수를 계산합니다.
  for (int i = 0; i < vertices; i++) {
    for (int neighbor : adjList[i]) {
      inDegree[neighbor]++;
    }
  }

  // 진입 차수가 0인 노드를 큐에 삽입합니다.
  for (int i = 0; i < vertices; i++) {
    if (inDegree[i] == 0) {
      q.push(i);
    }
  }

  // 큐에서 노드를 하나씩 꺼내면서 위상 정렬을 수행합니다.
  while (!q.empty()) {
    int node = q.front();
    q.pop();
    result.push_back(node);

    for (int neighbor : adjList[node]) {
      inDegree[neighbor]--;
      if (inDegree[neighbor] == 0) {
        q.push(neighbor);
      }
    }
  }

  // 모든 노드를 방문했는지 확인합니다.
  if (result.size() == vertices) {
    cout << "Topological Sort: ";
    for (int node : result) {
      cout << node << " ";
    }
    cout << endl;
  } else {
    cout << "Cycle detected! Topological sort not possible." << endl;
  }
}

int main() {
  int vertices = 6;
  vector<vector<int>> adjList(vertices);

  // 그래프를 정의합니다.
  adjList[5] = {2, 0};
  adjList[4] = {0, 1};
  adjList[2] = {3};
  adjList[3] = {1};

  topologicalSort(vertices, adjList);

  return 0;
}
