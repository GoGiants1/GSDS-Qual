class GNode:
    def __init__(self, id):
        self.id = id

def expo(G, path, t, pathlists):
    if path[-1] == t:
        pathlists.append([path[i].id for i in range(len(path))])
    else:
        for newnode in G[path[-1]]:
            if newnode not in path:
                newpath = path + [newnode]
                expo(G, newpath, t, pathlists)

def paths(G, s, t):
    pathlists = []
    expo(G, [s], t, pathlists)

    return pathlists

a, b, c, d = GNode('a'), GNode('b'), GNode('c'), GNode('d')
G = dict()
G[a], G[b], G[c], G[d] = [b, c], [d], [], [c]

print(paths(G,a,c))
