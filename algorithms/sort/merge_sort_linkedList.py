"""
- keyword: merge sort, merge_sort, divide, combine, linked_list

- keypoints: 
    * 배열을 계속 쪼개어 정렬 후 다시 합치는 방법
    * O(n log n)
    * 연결 리스트의 요소들을 직접 재배치하여 정렬: memory 복잡도 O(1) 유지
    * 안정적 (동일 원소 순서 유지)

- algorithm
    1) 중간점 찾기: 이를 위해 빠른 포인터와 느린 포인터 사용
    2) 병합 정렬 호출: 재귀
    3) 병합
"""

class Node:
    def __init__(self, x):
        self.val = x
        self.next = None


def get_middle(head):
    """
    2-point technique를 이용하여 linked list의 중간점 찾기 (fast가 끝까지 가면 slow는 중간에 가 있을 것)
    """
    if head is None:
        return head
    
    slow = head
    fast = head.next

    while fast and fast.next:
        slow = slow.next        # 한 칸씩
        fast = fast.next.next   # 두 칸씩

    return slow


def merge_sort(head):
    if (head is None) or (head.next is None):
        return head
    
    # Step 1: Split the linked list
    middle = get_middle(head)
    next_to_middle = middle.next
    middle.next = None                # head~middle, next_to_middle~end 이렇게 두 개로 나뉨

    # Step 2: Apply merge_sort on both halves
    left = merge_sort(head)
    right = merge_sort(next_to_middle)

    # Step 3: Merge the sorted halves
    sorted_list = merge(left, right)
    return sorted_list


def merge(left,right):
    if not left:
        return right
    if not right:
        return left

    if left.val <= right.val:
        result = left
        result.next = merge(left.next, right)
    else:
        result = right
        result.next = merge(left, right.next)
    return result


def print_list(head):
    current = head
    while current:
        print(current.val, end=" -> ")
        current = current.next
    print("None")


if __name__ == "__main__":
    head = Node(4)
    head.next = Node(2)
    head.next.next = Node(1)
    head.next.next.next = Node(3)

    print("Original linked list:")
    print_list(head)

    head = merge_sort(head)

    print("Sorted linked list:")    # ascending order
    print_list(head)