from collections import deque, defaultdict

def topological_sort(vertices, adj_list):
    in_degree = [0] * vertices
    result = []

    # 각 노드의 진입 차수를 계산합니다.
    for node in range(vertices):
        for neighbor in adj_list[node]:
            in_degree[neighbor] += 1

    # 진입 차수가 0인 노드를 큐에 삽입합니다.
    queue = deque()
    for i in range(vertices):
        if in_degree[i] == 0:
            queue.append(i)

    # 큐에서 노드를 하나씩 꺼내면서 위상 정렬을 수행합니다.
    while queue:
        node = queue.popleft()
        result.append(node)

        for neighbor in adj_list[node]:
            in_degree[neighbor] -= 1
            if in_degree[neighbor] == 0:
                queue.append(neighbor)

    # 모든 노드를 방문했는지 확인합니다.
    if len(result) == vertices:
        print("Topological Sort:", result)
    else:
        print("Cycle detected! Topological sort not possible.")

if __name__ == "__main__":
    vertices = 6
    adj_list = defaultdict(list)

    # 그래프를 정의합니다.
    adj_list[5] = [2, 0]
    adj_list[4] = [0, 1]
    adj_list[2] = [3]
    adj_list[3] = [1]

    topological_sort(vertices, adj_list)