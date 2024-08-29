"""
- keyword: prims, MST, minimum spanning tree

** greedy algorithm (vertex 기준 탐색!)
** MST의 특징: no cycle, 최단 경로 보장 x
"""

import heapq

def prims():
    """
    인접한 vertex 중 최소 비용 edge로 연결된 vertex 방문 (priority_queue 사용)
    """
    pq = []

    for edge in adj[1]:
        heapq.heappush(pq, edge)
    visit[1] = True

    count = 0
    mst_weight = 0

    while count < n - 1:      # 최대 edge 개수 V-1개
        weight, node = heapq.heappop(pq)
        if visit[node]: continue
        
        visit[node] = True
        count += 1
        mst_weight += weight

        print(f"{node}번 정점으로 이동: 비용 {weight}")   # 이동경로 출력

        for nextweight, nextnode in adj[node]:
            if not visit[nextnode]:
                heapq.heappush(pq, (nextweight, nextnode))

    print(f"MST 총 비용: {mst_weight}")

def init():   # weight, node
    adj[1].append((4, 2))          
    adj[1].append((8, 8))
    adj[2].append((4, 1))
    adj[2].append((8, 3))
    adj[2].append((11, 8))
    adj[3].append((8, 2))
    adj[3].append((7, 4))
    adj[3].append((4, 6))
    adj[3].append((2, 9))
    adj[4].append((7, 3))
    adj[4].append((9, 5))
    adj[4].append((14, 6))
    adj[5].append((9, 4))
    adj[5].append((10, 6))
    adj[6].append((4, 3))
    adj[6].append((14, 4))
    adj[6].append((10, 5))
    adj[6].append((2, 7))
    adj[7].append((2, 6))
    adj[7].append((1, 8))
    adj[7].append((6, 9))
    adj[8].append((8, 1))
    adj[8].append((11, 2))
    adj[8].append((1, 7))
    adj[8].append((7, 9))
    adj[9].append((2, 3))
    adj[9].append((6, 7))
    adj[9].append((7, 8))

if __name__ == "__main__":
    n = 9
    adj = [[] for _ in range(n + 1)]     # Index 1번부터 시작하기 위해 0번은 무시
    visit = [False] * (n + 1)
    init()
    print("[MST]")
    prims()