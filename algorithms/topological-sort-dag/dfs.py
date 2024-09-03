INF = float('inf')
V = 4  # Number of vertices in the graph

def floyd_warshall(graph):
    # Initialize the solution matrix same as the input graph matrix
    dist = [[graph[i][j] for j in range(V)] for i in range(V)]

    # Adding vertices individually
    for k in range(V):
        for i in range(V):
            for j in range(V):
                # Update dist[i][j] to be the minimum distance found so far
                if dist[i][k] != INF and dist[k][j] != INF and dist[i][k] + dist[k][j] < dist[i][j]:
                    dist[i][j] = dist[i][k] + dist[k][j]

    return dist

def print_solution(dist):
    print("Shortest distances between every pair of vertices:")
    for i in range(V):
        for j in range(V):
            if dist[i][j] == INF:
                print("INF", end=" ")
            else:
                print(dist[i][j], end=" ")
        print()

if __name__ == "__main__":
    graph = [
        [0, 3, INF, INF],
        [2, 0, INF, INF],
        [INF, 7, 0, 1],
        [6, INF, INF, 0]
    ]

    # Running the Floyd-Warshall algorithm
    dist = floyd_warshall(graph)

    # Printing the solution
    print_solution(dist)