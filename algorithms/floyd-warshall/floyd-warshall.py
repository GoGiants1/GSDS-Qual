# Floyd-Warshall Algorithm in Python

# Number of vertices in the graph
INF = float('inf')

def floyd_warshall(graph):
    # Number of vertices in the graph
    V = len(graph)
    
    # Initialize the solution matrix same as the input graph matrix
    dist = [[graph[i][j] for j in range(V)] for i in range(V)]

    # Adding vertices individually
    for k in range(V):
        for i in range(V):
            for j in range(V):
                # Update dist[i][j] to be the minimum distance found so far
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])

    return dist

# Example usage:
graph = [
    [0, 3, INF, INF],
    [2, 0, INF, INF],
    [INF, 7, 0, 1],
    [6, INF, INF, 0]
]

# Running the Floyd-Warshall algorithm
dist = floyd_warshall(graph)

# Printing the solution
print("Shortest distances between every pair of vertices:")
for row in dist:
    print(row)