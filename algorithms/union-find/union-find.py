class UnionFind:
    def __init__(self, size):
        self.parent = list(range(size))  # Initialize each node to be its own parent
        self.rank = [0] * size  # Rank (depth) of each tree is initially 0

    def find(self, p):
        # Path compression: make the found root the parent of all nodes in the path
        if self.parent[p] != p:
            self.parent[p] = self.find(self.parent[p])  # Recursively find the root
        return self.parent[p]

    def union(self, p, q):
        rootP = self.find(p)
        rootQ = self.find(q)

        if rootP != rootQ:
            # Union by rank: attach smaller tree under root of deeper tree
            if self.rank[rootP] > self.rank[rootQ]:
                self.parent[rootQ] = rootP
            elif self.rank[rootP] < self.rank[rootQ]:
                self.parent[rootP] = rootQ
            else:
                self.parent[rootQ] = rootP
                self.rank[rootP] += 1

    def connected(self, p, q):
        return self.find(p) == self.find(q)

# Example usage:
uf = UnionFind(10)

# Union some sets
uf.union(1, 2)
uf.union(3, 4)
uf.union(1, 4)

# Check if they are connected
print(uf.connected(1, 4))  # True
print(uf.connected(1, 5))  # False