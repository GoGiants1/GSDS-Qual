"""
- keyword: merge sort, merge_sort, divide, combine, array

- keypoints: 
    * 배열을 계속 쪼개어 정렬 후 다시 합치는 방법
    * O(n log n)
    * 분할된 리스트를 합치는 과정에서 추가적인 메모리 공간 O(N) 필요
    * 안정적 (동일 원소 순서 유지)
"""

def merge_sort(arr):
	if len(arr) > 1:
		mid = len(arr)//2
		L = arr[:mid]     # 쪼갬
		R = arr[mid:]
		
		merge_sort(L)     # 재귀 호출 
		merge_sort(R)
		
		i=j=k=0
		
		while i < len(L) and j < len(R):
			if L[i] < R[j]:
				arr[k] = L[i]
				i += 1
			else:
				arr[k] = R[j]
				j += 1
			k += 1
			
		while i < len(L):   # 남은 거 다 넣음
			arr[k] = L[i]
			i += 1
			k += 1
		
		while j < len(R):
			arr[k] = R[j]
			j += 1
			k += 1
			
	return arr

if __name__ == "__main__":
    arr = [12, 11, 13, 5, 6, 7]
    print("Given array is")
    print(arr)

    merge_sort(arr)

    print("\nSorted array is")
    print(arr)
