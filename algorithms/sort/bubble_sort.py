"""
- keyword: bubble sort, bubble_sort

- keypoints: 
    * 인접한 원소들 비교, 필요 시 위치 교환
    * O(n^2)
    * In-place sorting
    * 안정적 (동일 원소 순서 유지)
"""

def bubble_sort(arr):
    n = len(arr)
    for i in range(n):
        for j in range(0, n-i-1):     # 한 턴이 끝날 때마다 오른쪽에 정렬된 값들이 쌓임
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]
    return arr


if __name__ == "__main__":
    arr = [64, 34, 25, 12, 22, 11, 90]
    bubble_sort(arr)
    print("Sorted array is:", arr)