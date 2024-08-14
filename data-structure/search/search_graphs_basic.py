'''
* Cycle 탐색에 있어서 DFS가 BFS보다 memory effiecient.
    * BFS -> queue 구현, 최단경로 구할때 좋음
    * DFS -> stack/재귀 구현, cycle 찾을때 좋음
* Graph 종류? 1)directed인지 2)cyclic한지 3)connected인지 4)weight가 있는지

'''
from collections import deque


def BFS(G:dict, start:str): # class 사용할 경우 GNode type이 될수도 
    visited = []
    to_search = deque([])

    # initialize queue
    to_search.append(start)

    while to_search:
        curr_node = to_search.popleft()
        #print(curr_node)
        if curr_node not in visited:
            visited.append(curr_node)
            for node in G[curr_node]:
                to_search.append(node)
    return visited

def DFS_recursion(G:dict, start:str, visited=[]):
    if start not in visited:
        visited.append(start)
        for node in G[start]:
            DFS_recursion(G, node, visited)
    return visited

def DFS_stack(G:dict, start:str):
    visited = []
    to_search = deque([])
    to_search.append(start)
    while to_search:
        curr_node = to_search.pop() # popleft가 아닌 점에 주의
        if curr_node not in visited:
            visited.append(curr_node)
            for node in G[curr_node]:
                to_search.append(node)
    return visited


if __name__ == "__main__":
    G_undirected = {
        'A': ['B', 'G', 'D'],
        'B': ['A', 'F', 'E'],
        'C': ['F', 'H'],
        'D': ['F', 'A'],
        'E': ['B', 'G'],
        'F': ['B', 'D', 'C'],
        'G': ['A', 'E'],
        'H': ['C']
    }
    G_directed = {
        'A': ['B', 'G', 'D'],
        'B': ['F', 'E'],
        'C': ['F', 'H'],
        'D': ['F'],
        'E': ['G'],
        'F': ['C'],
        'G': ['A'],
        'H': ['C']
    }
    print("undirected graph BFS", BFS(G_undirected, 'A'))
    print("directed graph BFS : ", BFS(G_directed, 'A'))
    print("undirected graph DFS using recursion", DFS_recursion(G_undirected, 'A'))
    print("undirected graph DFS using stack", DFS_stack(G_undirected, 'A'))
    # stack이기 때문에 D->G->B 순으로 나옴.
    # print("directed graph DFS using recursion", DFS_recursion(G_directed, 'A'))