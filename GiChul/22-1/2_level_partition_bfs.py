"""
Q) Implement a function level_partition(G,s) that partitions the nodes in the breadth-first tree of G rooted as s
according to their level in the tree. It returns the list of partitions, and the partitions in the list are sorted in an
increasing order of the levels.

- Example: [[s], [r, w], [v, t, x], [u, y]]
"""

class GNode:
    def __init__(self, id, color = "W", d=0, p=None):
        self.id = id
        self.color = color
        self.distance = d
        self.parent = p
    def __str__(self):
        return self.id
    
def bfs(G,s):
    for node in G.keys():
        node.distance = float('inf')
    
    s.distance = 0   # 시작노드
    queue = [s]

    while queue:
        current_node = queue.pop(0)
        for neighbor in G[current_node]:
            if neighbor.distance == float('inf'):    # 아직 방문 x
                neighbor.distance = current_node.distance + 1        # distance로 거리 측정
                neighbor.parent = current_node
                queue.append(neighbor)


def level_partition(G,s):
    bfs(G,s)   # 노드의 거리/레벨 설정

    levels = {}     # level: [nodes]
    
    for node in G.keys():   # 레벨
        if node.distance not in levels:   # 아직 key로 없으면
            levels[node.distance] = []
        levels[node.distance].append(node.id)

    return [levels[level] for level in sorted(levels.keys())] 


if __name__ == "__main__":
    r,s,t,u,v = GNode('r'), GNode('s'), GNode('t'), GNode('u'), GNode('v')
    w,x,y = GNode('w'), GNode('x'), GNode('y')
    G = {
        r: [s, v],
        s: [r, w],
        t: [w, x, u],
        u: [t, x, y],
        v: [r],
        w: [s, t, x],
        x: [w, t, u, y],
        y: [u, x]
    }

    print(level_partition(G, s))

