"""
- keyword: linear search, sequential search

- keypoints: Time proportional to len(L), linked list에서 자주 사용
"""

def linear_search(arr, target):
    for i in range(len(arr)):
        if arr[i] == target:
            return i
    return -1
