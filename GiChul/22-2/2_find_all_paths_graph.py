"""
Q) Given an acyclic directed graph G, implement function paths(G,s,t) that returns
the list of all paths between 2 vertices s and t. Paths in the list can be in any
order, and each element in the path should be the id of the vertex.

- Example: paths(G,a,c) → [["a","c"], ["a","b","d","c"]]
"""

class GNode:
    def __init__(self, id):
        self.id = id
    def __str__(self):
        return self.id

def paths(G,u,v):
    """
    u에서 v 사이의 모든 path를 찾음
    ** 모든 가능한 경로를 탐색해야 하기 때문에 DFS 사용
    """
    all_paths = []

    def dfs(current, target, path, visited):
        visited.add(current)
        path.append(current.id)  

        if current == target:
            all_paths.append(list(path))
        else:
            for neighbor in G[current]:     
                if neighbor not in visited:
                    dfs(neighbor, target, path, visited)
        
        # 백트래킹: 현재 노드를 경로와 방문 기록에서 제거 (이전 상태로 되돌아가서 다른 경로를 탐색할 수 있게)
        path.pop()
        visited.remove(current)   # 다른 경로/가능성도 탐색해볼 수 있도록
    
    dfs(u,v,[],set())

    return all_paths 

if __name__ == "__main__":
    a, b, c, d = GNode('a'), GNode('b'), GNode('c'), GNode('d')
    G = dict()
    G[a], G[b], G[c], G[d] = [b, c], [d], [], [c]

    print(paths(G,a,c))
