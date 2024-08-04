class GNode:   
    def __init__(self, id, color = 'W', d = None, p = None):        
        self.id = id        
        self.distance = d                 
  
    
r, s, t, u, v = GNode('r'), GNode('s'), GNode('t'), GNode('u'), GNode('v')
w, x, y = GNode('w'), GNode('x'), GNode('y')
    
G = dict()
    
G[r], G[s], G[t], G[u], G[v] = [s, v], [r, w], [w, x, u], [t, x, y], [r]
G[w], G[x], G[y] = [s, t, x], [w, t, u, y], [x, u]

def bfs(G, s):
    v = []
    q = [s]

    while(len(q)!=0):
        n = q.pop(0)
        if n not in v:
            v.append(n)
            q.extend(G[n])
            for cn in G[n]: 
                if cn.distance is None: cn.distance = n.distance+1
    
    return v

def level_partition(G, s):
    s.distance = 0
    v = bfs(G, s)
    res = [[] for i in range(v[-1].distance+1)]
    for i in range(0,len(v)): res[v[i].distance].append(v[i].id)
    
    return res

print(level_partition(G, s))


