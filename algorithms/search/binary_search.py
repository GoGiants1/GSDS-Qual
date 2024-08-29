"""
- keyword: binary search, binary_search, binarysearch

- keypoints: array 무조건 정렬되어 있어야 함!, O(logN)
"""

def binary_search(L:list, v):
	"""
	반복을 활용한 이진 탐색 함수
	"""
	start, end = 0, len(L)-1
	while start != end+1:
		mid = (start+end)//2
		if L[mid] < v:
			start = mid+1
		else:
			end = mid-1
	if start < len(L) and L[start]==v:
		return start
	else:
		return -1

def binary_search_recursive(arr,target,left,right):
	"""
	재귀를 활용한 이진 탐색 함수
	"""
	if left > right:
		return False

	mid = (left+right)//2
	if arr[mid] == target:
		return True
	elif target < arr[mid]:
		binary_search_recursive(arr, target, left, mid-1)
	else:
		binary_search_recursive(arr, target, mid+1, right)



if __name__ == "__main__":
	arr = [2, 3, 4, 10, 40]
	target = 10
	result = binary_search(arr, target)
	result2 = binary_search_recursive(arr, target, 0, len(arr)-1)
	if result == -1:
		print("Element is not present in array")
	else:
		print("Element is present at index", result)
