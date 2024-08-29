"""
- keyword: selection sort, selection_sort

- keypoints: 
    * unsorted part에서 최소값을 찾아 현재 위치와 교체
    * O(n^2)
    * In-place sorting
    * 안정적 X (동일 원소 순서 유지 X)
"""

def selection_sort(arr):
	for i in range(len(arr)):
		smallest = i
		for j in range(i+1, len(arr)):
			if arr[j] < arr[smallest]:
				smallest = j
		arr[i], arr[smallest] = arr[smallest], arr[i]
	
	return arr

if __name__ == "__main__":
    arr = [64, 34, 25, 12, 22, 11, 90]
    selection_sort(arr)
    print("Sorted array is:", arr)
