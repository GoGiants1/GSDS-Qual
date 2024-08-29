"""
- keyword: heap, min_heap, pq, priority_queue, array
- functions: shift_up, shift_down, heappush, heappop, heapify

Heap 규칙
1. 완전 이진 트리: 노드를 왼쪽에서 오른쪽으로 하나씩 빠짐없이 채워나간다 (레벨 순서로 노드 삽입)
2. 최소 힙은 부모 값 <= 자식 값
"""


def shift_up(heap, child):
    """
    노드 위로 올리기
    """
    while child > 0:     # 올라갈 거니까 index 0을 넘어서지 않도록 조심
        parent = (child - 1) // 2
        if heap[parent] > heap[child]:
            heap[parent], heap[child] = heap[child], heap[parent]
            child = parent    # 올라감 
        else:
            break

def shift_down(heap, parent, last):
    """
    노드 아래로 내리기기
    """
    while parent < last:     # 내려갈 거니까 index가 넘치지 않도록 조심
        child = parent * 2 + 1
        sibling = child + 1
        if sibling < last and heap[child] > heap[sibling]:    # 더 작은 값을 child에 넣음
            child = sibling
        if child < last and heap[parent] > heap[child]:
            heap[parent], heap[child] = heap[child], heap[parent]
            parent = child     # 내려감
        else:
            break

def heappush(heap, data):
    """
    원소 추가 후 수정
    """
    heap.append(data)
    shift_up(heap, len(heap) - 1)      # 맨 마지막 노드 올리기

def heappop(heap):
    """
    모든 원소들이 오름차순으로 정렬되어 출력됨
    """
    if not heap:
        return "Empty Heap!"
    elif len(heap) == 1:
        return heap.pop()

    pop_data, heap[0] = heap[0], heap.pop()      # 마지막 원소를 루트로 대체
    shift_down(heap, 0, len(heap))               # 처음부터 끝까지 수정
    return pop_data

def heapify(arr):
    """
    주어진 배열 heap으로 만들기
    """
    last = len(arr) // 2       # leaf 노드는 자식이 없어 이미 힙의 조건 만족 -> 스킵
    for current in range(last - 1, -1, -1):     # bottom up으로 밑 노드부터 정렬
        shift_down(arr, current, len(arr))


if __name__ == "__main__":
    h = []
    arr = [21, 33, 17, 27, 9, 11, 14]
    for i in arr:
        heappush(h, i)

    print(f"배열의 상태: {arr}\n")
    print(f"배열의 모든 원소를 힙에 push한 상태: {h}\n")
    print("힙에서 모든 원소를 pop한 결과:", end = " ")
    while h:
        print(heappop(h), end = " ")
    print(f"\n\n빈 힙에서 원소를 pop한 결과: {heappop(h)}")
    print()

    h1 = [5, 2, 4, 1, 3]
    h2 = [3, 4, 5, 1, 2]
    h3 = [1, 5, 6, 4, 3, 8, 7, 2]
    for h in (h1, h2, h3):
        print(f"{h}를 최소 힙 구조로 만든 결과:", end = " ")
        heapify(h)
        print(h)
        print()