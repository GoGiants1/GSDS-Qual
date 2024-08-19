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

# 테스트
arr = [2, 3, 4, 10, 40]
target = 10
result = binary_search(arr, target)
if result == -1:
    print("Element is not present in array")
else:
    print("Element is present at index", result)
