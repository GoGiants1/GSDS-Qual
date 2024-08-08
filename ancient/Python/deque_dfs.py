from collections import deque

graph_list = {1: set([2, 3]),
              2: set([4]),
              3: set([1]),
              4: set([2, 5, 6]),
              5: set([4, 6]),
              6: set([4])}
root_node = 1  # 시작 노드

def DFS_with_adj_list(graph, root):
    visited = [] # 방문 리스트
    stack = [root] # 방문 해야 하는 노드리스트

    while stack:
        n = stack.pop() # stack 의 맨 오른쪽 요소를 뽑아서 n 에 저장

        if n not in visited: # n 이 방문 리스트에 없으면
            visited.append(n) # 방문한 곳에 n 추가
            stack += graph[n] - set(visited) # 방문한 곳을 graph 에서 제거하고 stack 에 저장

        # 만약 n 이 방문 리스트에 있으면 위로 가서 다시 n = queue.pop() 
    return visited
    
print(DFS_with_adj_list(graph_list, root_node))