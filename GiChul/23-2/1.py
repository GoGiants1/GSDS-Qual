class GNode:   
    def __init__(self, id, color='W', p=None):        
        self.id = id        
        self.color = color        
        self.parent = p            
    
    def __str__(self):        
        return self.id     
       
    def __hash__(self):        
        return hash(self.id)
    
A, B, C = GNode('A'), GNode('B'), GNode('C')
D, E, F = GNode('D'), GNode('E'), GNode('F')
    
G = dict()
    
G[A], G[B], G[C] = [C,D], [A,F], [D,B]
G[D], G[E], G[F] = [E], [F], []


def bfs(start_node, graph):
    queue = [start_node]
    visited = [start_node]

    while queue:
        curr_node = queue.pop(0)

        for next_node in graph[curr_node]:
            if next_node not in visited:
                visited.append(next_node)
                queue.append(next_node)
    return visited

def find_root(G):
    res = []
    for start_node in G.keys():
        if len(bfs(start_node, G)) == len(G.keys()): res.append(start_node.id)

    return res

print(find_root(G))


