"""
- keyword: insertion sort, insertion_sort

- keypoints: 
    * 정렬되지 않은 부분의 각 요소를 차례대로 이미 정렬된 부분의 적절한 위치에 삽입 (거의 정렬된 배열 정렬할 떄 효율적)
    * O(n) / O(n^2)
    * In-place sorting
    * 안정적 (동일 원소 순서 유지)
"""

def insertion_sort(arr):
	for i in range(1,len(arr)):     # unsorted 시작 부분
		key = arr[i]
		j = i-1                       # sorted 시작 부분 (역순으로 비교)
		while j>=0 and key < arr[j]:
			arr[j+1] = arr[j]           # key가 아직 더 크다면 j를 뒤로 한 칸씩 밂
			j-=1
		arr[j+1] = key                # 현재 j는 key보다 작은 index를 가리키고 있을 것. 따라서 key는 그 다음 index에 넣어야 하니 j+1


if __name__ == "__main__":
    arr = [64, 34, 25, 12, 22, 11, 90]
    insertion_sort(arr)
    print("Sorted array is:", arr)
