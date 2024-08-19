# 두 개의 서브 배열을 병합하는 함수
def merge(arr, l, m, r):
    n1 = m - l + 1 # 왼쪽 서브 배열 크기
    n2 = r - m     # 오른쪽 서브 배열 크기

    # 임시 배열 생성
    L = arr[l:l + n1]
    R = arr[m + 1:m + 1 + n2]

    i = 0
    j = 0
    k = l

    # 임시 배열에서 원래 배열로 병합
    while i < n1 and j < n2:
        if L[i] <= R[j]:
            arr[k] = L[i]
            i += 1
        else:
            arr[k] = R[j]
            j += 1
        k += 1

    # 남은 요소들을 복사
    while i < n1:
        arr[k] = L[i]
        i += 1
        k += 1

    while j < n2:
        arr[k] = R[j]
        j += 1
        k += 1

# Merge Sort 알고리즘
def mergeSort(arr, l, r):
    if l < r:
        m = l + (r - l) // 2 # 중간 인덱스 계산

        mergeSort(arr, l, m)    # 왼쪽 반을 정렬
        mergeSort(arr, m + 1, r) # 오른쪽 반을 정렬

        merge(arr, l, m, r)     # 병합

# 정렬할 배열
arr = [12, 11, 13, 5, 6, 7]
arr_size = len(arr)

print("Given array is")
print(arr)

# 배열을 병합 정렬로 정렬
mergeSort(arr, 0, arr_size - 1)

print("\nSorted array is")
print(arr)
