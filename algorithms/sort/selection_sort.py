"""
keyword: selection sort, selection_sort, selectionsort, sorting

keypoints: 현재 위치에 최솟값을 찾아 선택해 넣는 정렬

"""
# Selection Sort 알고리즘
def selectionSort(arr):
    n = len(arr)
    
    # 배열의 각 요소에 대해 최소값을 찾음
    for i in range(n):
        # i 번째 요소를 최소값으로 가정
        min_idx = i
        
        # 나머지 배열에서 최소값을 찾음
        for j in range(i+1, n):
            if arr[j] < arr[min_idx]:
                min_idx = j

        # 찾은 최소값을 현재 위치(i)로 이동
        arr[i], arr[min_idx] = arr[min_idx], arr[i]

# 정렬할 배열
arr = [64, 25, 12, 22, 11]

# 배열을 선택 정렬로 정렬
selectionSort(arr)

# 정렬된 배열을 출력
print("Sorted array:", arr)
