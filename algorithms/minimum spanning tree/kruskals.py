
class Edge:
    def __init__(self, u, v, weight):
        self.u = u
        self.v = v
        self.weight = weight

def find(parent, x):
    if parent[x] == x: return x
    parent[x] = find(parent, parent[x])
    return parent[x]

def unite(parent, x, y):
    root_x = find(parent, x)
    root_y = find(parent, y)
    if root_x != root_y:
        parent[root_y] = root_x

def kruskals(edges, n):
    edges.sort(key=lambda edge: edge.weight)

    parent = [i for i in range(n + 1)]

    mst_weight = 0
    count = 0

    for edge in edges:
        u = edge.u
        v = edge.v
        weight = edge.weight

        if find(parent, u) != find(parent, v):
            unite(parent, u, v)
            mst_weight += weight
            count += 1
            print(f"{u} - {v}번 정점 연결: 비용 {weight}")
            if count == n - 1: break

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
