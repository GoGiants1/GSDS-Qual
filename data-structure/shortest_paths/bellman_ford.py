import sys
from collections import deque
iuput = sys.stdin.readline
INF = int(10**9)

'''
벡준 11657번(https://www.acmicpc.net/problem/11657) 을 가정하고 만듦
핵심 : dijkstra + 재방문시 distance 달라지는지 검출하기
'''

# initialize graph
V, E = map(int, input().split())
startNode = 1 # int(input()) # 문제에서는 1

graph = []
distances = [INF] * (V+1)                   # V+1은 그래프 시작 인덱스가 1부터여셔

for _ in range(E):
    u, v, w = map(int, input().split())
    graph.append((u, v, w))


def sssp_bellman_ford(graph, start, distances):
    distances[start] = 0
    
    for i in range(V):
        # check all edges : 
        for (curr_node, neighbor, weight) in graph:
            dist_to_neighbor = distances[neighbor]
            cost_from_curr = distances[curr_node] + weight
            if (distances[curr_node]!=INF) and (dist_to_neighbor > cost_from_curr):
                distances[neighbor] = cost_from_curr

                if i == V-1:
                    return True

    return False



if sssp_bellman_ford(graph, startNode, distances):
    print(-1)
else:
    for i in range(2, V+1):
        if distances[i] == INF:
            print(-1)
        else:
            print(distances[i])