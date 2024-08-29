"""
- keyword: bfs, dijkstra, bellman_ford, shortest paths, sssp

1) unweighted graph -> BFS로 풀기
2) directed graph -> dijkstra, bellman_ford

** shortest path는 cycle이 없거나 zero-weight cycle만 있을 때 정의됨
** relaxation: d[v] > d[u] + w(u,v) 이면 d[v] 값 감소, π[v] 값은 u로 변경
"""

import sys
iuput = sys.stdin.readline    # 입력처리 더 효율적으로 하는 코드

INF = int(10**9)

from collections import deque
def sssp_bfs(graph, start, distances):
    """
    unweighted graph: 사실상 노드까지의 depth 세는 것과 동일 (=less edge path)
    """
    distances[start] = 0
    pq = deque([])
    pq.append(start)
    
    while pq:
        curr_node = pq.popleft()
        for (neighbor, _) in graph[curr_node]:
            if distances[neighbor] == INF:
                distances[neighbor] = distances[curr_node] + 1
                pq.append(neighbor)
    
    return distances


import heapq
def sssp_dijkstra(graph, start, distances):
    """
    weighted graph with non-negative weights (greedy)
    """
    distances[start] = 0
    pq = []     # 아직 방문하지 않은 vertex들 저장 (distance, vertex)
    heapq.heappush(pq, (0, start))      # start node priority/distance를 0으로 초기화

    while pq:
        curr_dist, curr_node = heapq.heappop(pq)
        if curr_dist > distances[curr_node]:   # 이미 저장된 distance보다 크면 검토 필요 x
            continue
        for (neighbor, weight) in graph[curr_node]:
            next_cost = curr_dist + weight
            if next_cost < distances[neighbor]:   # relaxation
                distances[neighbor] = next_cost
                heapq.heappush(pq, (next_cost, neighbor))

    return distances


def sssp_bellman_ford(edges, start, distances):
    """
    general weighted graph (모든 edge에 대해 relaxation 수행)
    * negative weight cycle detect 가능
    """
    distances[start] = 0
    
    for i in range(V):
        # check all edges (한 노드에 대해 최대 V-1번 반복): 
        for (curr_node, neighbor, weight) in edges:
            dist_to_neighbor = distances[neighbor]
            cost_from_curr = distances[curr_node] + weight
            if (distances[curr_node]!=INF) and (dist_to_neighbor > cost_from_curr):
                distances[neighbor] = cost_from_curr
                
                # 최대 V-1번 반복 후에도 어떤 간선에서 더 짧은 경로가 발견된다면 이는 negative cycle이 존재한다는 뜻
                if i == V-1: 
                    return True
    return False


if __name__ == "__main__":
    V,E = 5,6 
    # V,E = 4,5
    startNode = 1

    graph = [[] for _ in range(V+1)]
    edges = [         # Edges (u, v, w) -> u에서 v로 가는 가중치 w인 간선
        (1, 2, 2),
        (1, 3, 4),
        (2, 3, 1),
        (2, 4, 7),
        (3, 5, 3),
        (4, 5, 1)
    ]

    # edges = [         
    #     (1, 2, 4),
    #     (2, 3, -2),
    #     (3, 4, 2),
    #     (4, 2, -1),
    #     (1, 3, 5)
    # ]

    for u, v, w in edges:
        graph[u].append((v, w))


    # BFS
    distances = [INF] * (V+1)
    sssp_bfs_result = sssp_bfs(graph, startNode, distances)

    print("BFS Result:")
    for i in range(1, V + 1):
        if sssp_bfs_result[i] == INF:
            print("INF")
        else:
            print(f"Distance to node {i}: {sssp_bfs_result[i]}")


    # Dijkstra
    distances = [INF] * (V+1)    # Reset distances
    sssp_dijkstra_result = sssp_dijkstra(graph, startNode, distances)

    print("\nDijkstra Result:")
    for i in range(1, V + 1):
        if sssp_dijkstra_result[i] == INF:
            print("INF")
        else:
            print(f"Distance to node {i}: {sssp_dijkstra_result[i]}")


    # Bellman-Ford
    distances = [INF] * (V+1)    # Reset distances
    has_negative_cycle = sssp_bellman_ford(edges, startNode, distances)

    print("\nBellman-Ford Result:")
    if has_negative_cycle:
        print("Negative cycle detected!")
    else:
        for i in range(1, V + 1):
            if distances[i] == INF:
                print("INF")
            else:
                print(f"Distance to node {i}: {distances[i]}")