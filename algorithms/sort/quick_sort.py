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
        pi = partition(arr, low, high) # 배열을 분할하고 피벗 위치를 얻음

        quickSort(arr, low, pi - 1) # 피벗을 기준으로 왼쪽 부분을 정렬
        quickSort(arr, pi + 1, high) # 피벗을 기준으로 오른쪽 부분을 정렬

# 정렬할 배열
arr = [10, 7, 8, 9, 1, 5]
n = len(arr)

# 배열을 퀵 정렬로 정렬
quickSort(arr, 0, n - 1)

# 정렬된 배열을 출력
print("Sorted array:", arr)
