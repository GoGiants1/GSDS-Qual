"""
keyword: quick sort, quick_sort, quicksort, sorting, pivot

keypoints: pivot을 기준으로 작은 요소들은 왼쪽으로, 큰 요소들은 오른쪽으로 정렬

# 피벗(pivot)을 선택하는 방법
1) 첫번째 요소
2) 마지막 요소
이미 정렬된 배열이나 역순으로 정렬된 배열에 대해 매우 비효율적 O(N^2)
3) Random pivot
평균적으로 O(NlogN)
4) Middle
이미 정렬된 배열에 대해서도 좋은 성능
5) Median-of-Three (자주 사용)
피벗 선택을 위한 추가적인 연산이 필요하지만, 최악의 경우를 피하기 위해 매우 유용!
"""

import random

# 다양한 Pivot Selection 방법
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
    pivot_idx = pivot_selector(arr, low, high)
    arr[low], arr[pivot_idx] = arr[pivot_idx], arr[low]  # 피벗을 배열의 첫번째로 이동
    pivot = arr[low]
    i = low + 1

    for j in range(low + 1, high + 1):
        if arr[j] < pivot:
            arr[i], arr[j] = arr[j], arr[i]
            i += 1

    arr[low], arr[i - 1] = arr[i - 1], arr[low]
    return i - 1 # 피벗의 위치 반환

# 배열을 분할하고 피벗 위치를 반환하는 함수
def partition(arr, low, high):
    pivot = arr[high] # 피벗을 배열의 마지막 요소로 설정
    i = low - 1 # i는 피벗보다 작은 요소들의 끝 인덱스를 가리킴

    for j in range(low, high):
        if arr[j] < pivot: # 피벗보다 작은 요소를 발견하면
            i = i + 1
            arr[i], arr[j] = arr[j], arr[i] # i와 j의 요소를 교환

    arr[i + 1], arr[high] = arr[high], arr[i + 1] # 피벗을 올바른 위치로 이동
    return i + 1 # 피벗의 위치를 반환

# Quick Sort 알고리즘
def quickSort(arr, low, high):
    if low < high:
        # pi = partition(arr, low, high) # 배열을 분할하고 피벗 위치를 얻음
        pi = partition_pivot(arr, low, high, pivot_median_of_three) # pivot selector 선택

        quickSort(arr, low, pi - 1) # 피벗을 기준으로 왼쪽 부분을 정렬
        quickSort(arr, pi + 1, high) # 피벗을 기준으로 오른쪽 부분을 정렬

# 정렬할 배열
arr = [10, 7, 8, 9, 1, 5]
n = len(arr)

# 배열을 퀵 정렬로 정렬
quickSort(arr, 0, n - 1)

# 정렬된 배열을 출력
print("Sorted array:", arr)
