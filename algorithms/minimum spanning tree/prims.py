import heapq

n = 9

adj = [[] for _ in range(n + 1)]
visit = [False] * (n + 1)

def prims():
    pque = []

    for edge in adj[1]: heapq.heappush(pque, edge)
    visit[1] = True

    count = 0
    mst_weight = 0

    while count < n - 1:
        weight, node = heapq.heappop(pque)
        if visit[node]: continue
        
        visit[node] = True
        count += 1
        mst_weight += weight

        print(f"{node}번 정점 발견 : 비용 {weight}")

        for nextweight, nextnode in adj[node]:
            if not visit[nextnode]:
                heapq.heappush(pque, (nextweight, nextnode))

    print(f"MST 총 비용: {mst_weight}")

def init():
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
    init()
    print("[MST]")
    prims()