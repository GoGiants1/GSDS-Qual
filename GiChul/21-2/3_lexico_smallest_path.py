"""
Q) Implement a function that finds out the lexicographically smallest path between 2 nodes in a graph. Consider an adjacency
list implementation of an undirected graph using a dictionary. LexSmallest(G,u,v) returns the lexicographically smallest path
between u,v. The list contains the id of the nodes on the path (= list of strings). If there is no path, return an empty list.

- Example
    1. LexSmallest(G,t,v) → ['t', 's', 'w', 'r', 'v']
    2. LexSmallest(G,u,u) → ['u']
    3. LexSmallest(G,w,y) → []
"""

class GNode:
    def __init__(self, id, color = "W", d = -1, f = -1, p = None):
        self.id = id               # string
        self.color = color         # status of node
        self.d = d                 # discover time of node
        self.f = f                 # finish time of node
        self.parent = p            # predecessor time of node
    
    def __str__(self):
        return self.id
    

def LexSmallest(G,u,v):
    """
    u에서 v 사이의 모든 path를 찾은 뒤 lexicographical하게 가장 작은 path를 고름
    ** 모든 가능한 경로를 탐색해야 하기 때문에 DFS 사용
    """
    all_paths = []

    def dfs(current, target, path, visited):
        visited.add(current)
        path.append(current.id)   # path는 list of strings라고 했기 때문에 current.id 추가

        if current == target:
            all_paths.append(list(path))
        else:
            for neighbor in sorted(G[current], key=lambda node: node.id):      # 여기서 애초에 sorting을 하여 lexical 순으로 이웃 방문
                if neighbor not in visited:
                    dfs(neighbor, target, path, visited)
        
        # 백트래킹: 현재 노드를 경로와 방문 기록에서 제거 (이전 상태로 되돌아가서 다른 경로를 탐색할 수 있게)
        path.pop()
        visited.remove(current)   # 다른 경로/가능성도 탐색해볼 수 있도록
    
    dfs(u,v,[],set())

    return min(all_paths) if all_paths else []   



if __name__ == "__main__":
    r, s, t, u = GNode('r'), GNode('s'), GNode('t'), GNode('u')
    v, w, x, y = GNode('v'), GNode('w'), GNode('x'), GNode('y')

    G = dict()
    G[r], G[w], G[t], G[u] = [w, v], [s, r, t], [s, x, w], [y]
    G[v], G[s], G[x], G[y] = [r], [w, t, x], [s, t], [u]

    '''
    r: [w,v]
    w: [s,r,t]
    t: [s,x,w]
    u: [y]
    v: [r]
    s: [w,t,x]
    x: [s,t]
    y: [u]
    '''

    print(LexSmallest(G, t, v))
    print(LexSmallest(G, u, u))
    print(LexSmallest(G, w, y))
