class GNode:
    def __init__(self, id, color = "W", d = -1, f = -1, p = None):
        self.id = id
        self.color = color
        self.d = d
        self.f = f
        self.parent = p
    
    def __str__(self):
        return self.id
    
    
def lexcomp(l1, l2):
    res = 2
    if(l1 != l2):
        i = 0
        while(i < min(len(l1),len(l2))):
            if l1[i] < l2[i]: 
                res = 0
                break
            elif l1[i] > l2[i]:
                res = 1
                break
            else: i += 1

        if(res == 2):
            if len(l1) > len(l2): res = 1
            else: res = 0
    
    return res

def dfs(G, path, v):
    if(path[-1]==v): return list([ i.id for i in path])
    else:
        res = []
        for next in G[path[-1]]:
            if(next not in path):
                newpath = path + [next]
                tmp = dfs(G, newpath, v)
                if(len(res) == 0 or (len(tmp) != 0 and lexcomp(res, tmp) == 1)): res = tmp
        return res

def LexSmallest(G, u, v):
    path = dfs(G, [u], v)
    return path

r, s, t, u = GNode('r'), GNode('s'), GNode('t'), GNode('u')
v, w, x, y = GNode('v'), GNode('w'), GNode('x'), GNode('y')

G = dict()
G[r], G[w], G[t], G[u] = [w, v], [s, r, t], [s, x, w], [y]
G[v], G[s], G[x], G[y] = [r], [w, t, x], [s, t], [u]

print(LexSmallest(G, t, v))
print(LexSmallest(G, u, u))
print(LexSmallest(G, w, y))