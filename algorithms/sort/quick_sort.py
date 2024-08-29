"""
- keyword: quick sort, quick_sort, pivot

- keypoints: 
    * pivot보다 작은 모든 요소는 pivot의 왼쪽에, 큰 요소는 오른쪽에 위치하도록 배열 재배치
    * O(n log n)
    * In-place sorting
    * 안정적 X (동일 원소 순서 유지 X)

- pivot select methods
    1) 첫 번째 요소
    2) 마지막 요소: 이미 정렬된 배열이나 역순으로 정렬된 배열에 대해 매우 비효율적 (O(n^2))
    3) Random pivot
    4) Middle: 이미 정렬된 배열에 대해서도 좋은 성능
    5) Median-of-three (자주 사용): 최악의 경우 피할 때 유용 but 추가적인 연산 필요
"""

import random

# pivot select methods
def pivot_first(arr, low, high):
    return low

def pivot_last(arr, low, high):
    return high

def pivot_random(arr, low, high):
    return random.randint(low, high)

def pivot_middle(arr, low, high):
    return (low + high) // 2

def pivot_median_of_three(arr, low, high):
    mid = (low + high) // 2
    pivot_candidates = [(arr[low], low), (arr[mid], mid), (arr[high], high)]
    pivot_candidates.sort(key=lambda x: x[0])
    return pivot_candidates[1][1]

def partition_pivot(arr, low, high, pivot_selector):
    """
    Pivot select mechanism을 선택할 수 있는 함수 (동일하게 pivot의 위치 반환)
    """
    pivot_idx = pivot_selector(arr, low, high)
    arr[low], arr[pivot_idx] = arr[pivot_idx], arr[low]   # 피벗을 배열의 첫번째로 이동
    pivot = arr[low]
    i = low + 1        # 피벗 이후부터

    for j in range(low + 1, high + 1):
        if arr[j] < pivot:
            arr[i], arr[j] = arr[j], arr[i]    # 만약 피벗보다 작으면 i번째 애랑 자리를 바꿈
            i += 1               # i는 피벗보다 작은 원소들의 개수를 뜻함 (이동시킨 횟수)

    arr[low], arr[i - 1] = arr[i - 1], arr[low]      # i-1이 피벗보다 작은 마지막 원소 => 얘랑 피벗의 자리를 바꾸면 피벗보다 작은 애들이 모두 왼쪽에 있게 됨
    return i - 1     # 피벗의 위치 반환


def quickSort(arr, low, high):
    if low < high:
        pi = partition_pivot(arr, low, high, pivot_first)   # pivot selector 선택

        quickSort(arr, low, pi - 1) # 피벗을 기준으로 왼쪽 부분을 정렬
        quickSort(arr, pi + 1, high) # 피벗을 기준으로 오른쪽 부분을 정렬


if __name__ == "__main__":
    arr = [10, 7, 8, 9, 1, 5]
    quickSort(arr, 0, len(arr) - 1)
    print("Sorted array:", arr)
