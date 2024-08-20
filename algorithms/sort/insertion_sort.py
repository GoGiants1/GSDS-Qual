"""
keyword: insertion sort, insertion_sort, insertionsort, sorting

keypoints: 자신의 위치를 찾아 삽입하는 방법

"""

def insertion_sort(arr):
    # 배열의 첫 번째 요소는 이미 정렬된 상태로 간주하고, 두 번째 요소부터 시작
    for i in range(1, len(arr)):
        key = arr[i]  # 현재 삽입할 요소
        j = i - 1

        # 현재 요소(key)보다 큰 요소들은 한 칸씩 뒤로 이동
        while j >= 0 and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1
        
        # 현재 요소(key)를 올바른 위치에 삽입
        arr[j + 1] = key

# 테스트 코드
arr = [12, 11, 13, 5, 6]
insertion_sort(arr)
print("Sorted array is:", arr)
