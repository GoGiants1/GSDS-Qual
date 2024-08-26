import heapq
import sys

class Graph:
    def __init__(self, vertices):
        self.V = vertices  # Number of vertices in the graph
        self.graph = []    # Default dictionary to store the graph as an edge list

    def add_edge(self, u, v, w):
        self.graph.append([u, v, w])

    def bellman_ford(self, src):
        dist = [float("Inf")] * self.V
        dist[src] = 0

        for _ in range(self.V - 1):
            for u, v, w in self.graph:
                if dist[u] != float("Inf") and dist[u] + w < dist[v]:
                    dist[v] = dist[u] + w

        for u, v, w in self.graph:
            if dist[u] != float("Inf") and dist[u] + w < dist[v]:
                print("Graph contains negative weight cycle")
                return None

        return dist

    def dijkstra(self, src):
        dist = [float("Inf")] * self.V
        dist[src] = 0
        pq = []
        heapq.heappush(pq, (0, src))

        while pq:
            d, u = heapq.heappop(pq)
            if d > dist[u]:
                continue

            for v, w in self.adj[u]:
                if dist[u] + w < dist[v]:
                    dist[v] = dist[u] + w
                    heapq.heappush(pq, (dist[v], v))

        return dist

    def johnson(self):
        # Step 1: Add a new vertex and connect it to all other vertices with zero weight edges
        new_vertex = self.V
        self.V += 1
        for i in range(self.V - 1):
            self.graph.append([new_vertex, i, 0])

        # Step 2: Use Bellman-Ford to find the shortest paths from the new vertex
        h = self.bellman_ford(new_vertex)
        if h is None:
            return

        # Step 3: Remove the added vertex from the graph
        self.graph = self.graph[:-self.V+1]
        self.V -= 1

        # Step 4: Reweight the graph using h values
        self.adj = [[] for _ in range(self.V)]
        for u, v, w in self.graph:
            self.adj[u].append((v, w + h[u] - h[v]))

        # Step 5: Run Dijkstra's algorithm for each vertex
        all_pairs_shortest_paths = []
        for u in range(self.V):
            dist = self.dijkstra(u)
            # Undo the reweighting
            dist = [dist[v] + h[v] - h[u] for v in range(self.V)]
            all_pairs_shortest_paths.append(dist)

        return all_pairs_shortest_paths

# Example usage:
g = Graph(5)
g.add_edge(0, 1, -1)
g.add_edge(0, 2, 4)
g.add_edge(1, 2, 3)
g.add_edge(1, 3, 2)
g.add_edge(1, 4, 2)
g.add_edge(3, 2, 5)
g.add_edge(3, 1, 1)
g.add_edge(4, 3, -3)

result = g.johnson()

if result:
    print("The shortest paths between every pair of vertices are:")
    for row in result:
        print(row)
