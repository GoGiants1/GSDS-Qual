from collections import deque

graph_list = {1: set([2, 3]),
              2: set([4]),
              3: set([1]),
              4: set([2, 5, 6]),
              5: set([4, 6]),
              6: set([4])}
root_node = 1  # 시작 노드

def BFS_with_adj_list(graph, root):
    visited = []  # 방문 리스트
    queue = deque([root])  # 큐 = deque[root]

    while queue:
        n = queue.popleft()  # queue 의 맨 왼쪽 요소를 뽑아서 n 에 저장
        if n not in visited:  # n이 방문 리스트에 없으면
            visited.append(n)  # 방문한 곳에 n 추가
            queue += graph[n] - set(visited)  # 방문한 곳을 gragh 에서 제거하고 queue에 저장
            
        # 만약 n 이 방문 리스트에 있으면 위로 가서 다시 n = queue.popleft()
    return visited  # 방문 목록 리턴

print(BFS_with_adj_list(graph_list, root_node))