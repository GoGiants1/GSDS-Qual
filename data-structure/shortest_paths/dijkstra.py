import sys
from collections import deque
iuput = sys.stdin.readline
INF = int(10**9)

'''
백준 1753번(https://www.acmicpc.net/problem/1753)을 가정하고 만듦
1) unweighted graph -> BFS
* 아래 2개는 directed case만
2) weightd graph with non-negative weightds ->dijkstra
* dijkstra가 음수 weight에 대해 안되는 이유 https://stackoverflow.com/questions/13159337/why-doesnt-dijkstras-algorithm-work-for-negative-weight-edges
3) a general weightd graph -> bellman-ford
주의할 점 : positive/negative weight cycle은 한번 돌때마다 cycle 안의 dist 값이 바뀜
            따라서 sssp는 안에 cycle이 없거나 zero-weight cycle만 있을때 정의됨
'''

def sssp_bfs(graph, start, distances):
    distances[start] = 0
    visited = []                            # distance = INF이면 visited = False
    to_search = deque([])
    to_search.append(start)
    
    while to_search:
        curr_node = to_search.popleft()
        for (neighbor, weight) in graph[curr_node]:
            if distances[neighbor] == INF:
                distances[neighbor] = distances[curr_node] + weight
                to_search.append(neighbor)
    
    return distances


import heapq
def sssp_dijkstra(graph, start, distances):
    distances[start] = 0
    pq = []
    heapq.heappush(pq, (0, start))      # start node에 priority 0(==distance) 줌

    while pq:
        curr_dist, curr_node = heapq.heappop(pq)
        # 들어오는 node의 거리가 저장된 값보다 크면 무시
        if curr_dist > distances[curr_node]:
            continue
        # 아니면 
        for (neighbor, weight) in graph[curr_node]:
            next_cost = curr_dist + weight
            if next_cost < distances[neighbor]:
                distances[neighbor] = next_cost
                heapq.heappush(pq, (next_cost, neighbor))

    return distances


# initialize graph
V, E = map(int, input().split())
startNode = int(input())

graph = [[] for _ in range(V+1)]
distances = [INF] * (V+1)                   # V+1은 그래프 시작 인덱스가 1부터여셔
for _ in range(E):
    u, v, w = map(int, input().split())
    graph[u].append((v, w))



# BFS의 경우 사실상 노드까지의 depth 세는 것과 동일하다
sssp_bfs_result = sssp_bfs(graph, startNode, distances)

# dijkstra result
sssp_dijkstra_result = sssp_dijkstra(graph, startNode, distances)

for i in range(1, V + 1):
    if sssp_dijkstra_result[i] == INF:
        print("INF")
    else:
        print(sssp_bfs_result[i])