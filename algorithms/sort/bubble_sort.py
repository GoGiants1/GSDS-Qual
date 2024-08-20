"""
keyword: bubble sort, bubble_sort, bubblesort, sorting

keypoints: 인접한 두 원소를 비교해, 순서대로 되어 있지 않으면 교환

"""

def bubble_sort(arr):
    n = len(arr)
    # 배열의 크기만큼 반복
    for i in range(n):
        swapped = False
        # 마지막 i개의 요소는 이미 정렬되어 있으므로 제외
        for j in range(0, n-i-1):
            # 인접한 두 요소를 비교하여 순서가 잘못되었으면 교환
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]
                swapped = True
        
        # 만약 이번 패스에서 요소가 교환되지 않았다면, 이미 정렬되어 있음
        if not swapped:
            break

# 테스트 코드
arr = [64, 34, 25, 12, 22, 11, 90]
bubble_sort(arr)
print("Sorted array is:", arr)
