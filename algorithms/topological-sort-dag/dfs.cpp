/*
DFS 기반 위상 정렬은 재귀적으로 각 노드를 방문하며, 모든 인접 노드를 방문한 후
해당 노드를 스택에 삽입합니다. 이 스택을 역순으로 나열하면 위상 정렬 결과가
됩니다.

1. 모든 노드를 방문하지 않은 상태로 표시합니다.
2. 방문하지 않은 노드를 시작점으로 DFS를 수행합니다.
3. 재귀적으로 모든 인접 노드를 방문한 후, 현재 노드를 스택에 삽입합니다.
4. 모든 노드를 처리한 후 스택에 쌓인 노드를 순서대로 꺼내면 위상 정렬 순서가
됩니다.

# 스택 기본 함수
## 추가 및 삭제
- push(element): top에 원소를 추가
- pop(): top에 있는 원소를 삭제
## 조회
- top(): top(스택의 처음이 아닌 가장 끝)에 있는 원소를 반환
기타
- empty(): 스택이 비어있으면 true 아니면 false를 반환
- size(): 스택 사이즈를 반환

*/

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void dfs(int node, vector<vector<int>>& adjList, vector<bool>& visited,
         stack<int>& Stack) {
  visited[node] = true;

  for (int neighbor : adjList[node]) {
    if (!visited[neighbor]) {
      dfs(neighbor, adjList, visited, Stack);
    }
  }

  Stack.push(node);
}

void topologicalSort(int vertices, vector<vector<int>>& adjList) {
  stack<int> Stack;
  vector<bool> visited(vertices, false);

  // 방문하지 않은 모든 노드에 대해 DFS를 수행합니다.
  for (int i = 0; i < vertices; i++) {
    if (!visited[i]) {
      dfs(i, adjList, visited, Stack);
    }
  }

  // 스택의 노드를 꺼내면서 위상 정렬 순서를 출력합니다.
  cout << "Topological Sort: ";
  while (!Stack.empty()) {
    cout << Stack.top() << " ";
    Stack.pop();
  }
  cout << endl;
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
