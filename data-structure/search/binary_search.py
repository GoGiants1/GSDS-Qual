"""
keyword: binary search, binary_search, binarysearch

keypoints: sorted array 무조건 정렬되어 있어야 함!, O(logN)

"""
# 이진 탐색 함수
def binary_search(arr, target):
    left, right = 0, len(arr) - 1

    while left <= right:
        mid = left + (right - left) // 2

        # 목표 값을 찾음
        if arr[mid] == target:
            return mid

        # 목표 값이 중간 값보다 작으면 왼쪽 절반 탐색
        if arr[mid] > target:
            right = mid - 1
        # 목표 값이 중간 값보다 크면 오른쪽 절반 탐색
        else:
            left = mid + 1

    # 목표 값을 찾지 못함
    return -1

# 이진 탐색 재귀
def binary_search_recursion(arr, low, high, x):
    # 기저 사례: low가 high를 넘으면, 요소가 배열에 없음을 의미
    if high >= low:
        mid = (low + high) // 2

        # 중간 값이 찾고자 하는 값과 일치하는 경우
        if arr[mid] == x:
            return mid

        # 찾고자 하는 값이 중간 값보다 작은 경우, 왼쪽 서브배열에서 탐색
        elif arr[mid] > x:
            return binary_search_recursion(arr, low, mid - 1, x)

        # 찾고자 하는 값이 중간 값보다 큰 경우, 오른쪽 서브배열에서 탐색
        else:
            return binary_search_recursion(arr, mid + 1, high, x)
    
    # 요소를 찾지 못한 경우
    return -1

# 테스트
arr = [2, 3, 4, 10, 40]
target = 10
result = binary_search(arr, target)
result2 = binary_search_recursion(arr, 0, len(arr)-1, target)
if result == -1:
    print("Element is not present in array")
else:
    print("Element is present at index", result)
