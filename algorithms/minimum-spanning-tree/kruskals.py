"""
- keyword: kruskals, MST, minimum spanning tree

** greedy algorithm (edge 기준 탐색!)
** MST의 특징: no cycle, 최단 경로 보장 x
"""

class Edge:
    def __init__(self, u, v, weight):
        self.u = u
        self.v = v
        self.weight = weight

def find(parent, x):
    """
    한 집합에 소속되어 있는지 확인하기 위해 루트 찾기
    """
    if parent[x] == x: return x       # 자기만 들어가 있으면
    parent[x] = find(parent, parent[x])
    return parent[x]

def unite(parent, x, y):
    """
    두 집합을 합침
    """
    root_x = find(parent, x)
    root_y = find(parent, y)
    parent[root_y] = root_x 

def kruskals(edges, n):
    """
    1) 모든 vertex가 각각의 집합으로 시작
    2) 두 집합을 연결하는 edge 중 최소 비용을 찾아 connect 2 distinct sets
    """
    edges.sort(key=lambda edge: edge.weight)    # weight 기준 정렬

    parent = [i for i in range(n + 1)]   # 같은 값을 가지면 같은 set

    count = 0
    mst_weight = 0
    
    for edge in edges:      # 이미 정렬했으니까 순서대로 불러오는 게 최소 비용 순대로 불러오는 거
        u = edge.u
        v = edge.v
        weight = edge.weight

        if find(parent, u) != find(parent, v):   # 두 vertex가 다른 set이면
            unite(parent, u, v)
            mst_weight += weight
            count += 1
            print(f"{u} - {v}번 정점 연결: 비용 {weight}")
            if count == n - 1: break      # 최대 edge 개수 V-1개

    print(f"MST 총 비용: {mst_weight}")

def init():
    edges = []
    edges.append(Edge(1, 2, 4))
    edges.append(Edge(1, 8, 8))
    edges.append(Edge(2, 1, 4))
    edges.append(Edge(2, 3, 8))
    edges.append(Edge(2, 8, 11))
    edges.append(Edge(3, 2, 8))
    edges.append(Edge(3, 4, 7))
    edges.append(Edge(3, 6, 4))
    edges.append(Edge(3, 9, 2))
    edges.append(Edge(4, 3, 7))
    edges.append(Edge(4, 5, 9))
    edges.append(Edge(4, 6, 14))
    edges.append(Edge(5, 4, 9))
    edges.append(Edge(5, 6, 10))
    edges.append(Edge(6, 3, 4))
    edges.append(Edge(6, 4, 14))
    edges.append(Edge(6, 5, 10))
    edges.append(Edge(6, 7, 2))
    edges.append(Edge(7, 6, 2))
    edges.append(Edge(7, 8, 1))
    edges.append(Edge(7, 9, 6))
    edges.append(Edge(8, 1, 8))
    edges.append(Edge(8, 2, 11))
    edges.append(Edge(8, 7, 1))
    edges.append(Edge(8, 9, 7))
    edges.append(Edge(9, 3, 2))
    edges.append(Edge(9, 7, 6))
    edges.append(Edge(9, 8, 7))

    return edges

if __name__ == "__main__":
    n = 9
    edges = init()
    print("[MST]")
    kruskals(edges, n)
