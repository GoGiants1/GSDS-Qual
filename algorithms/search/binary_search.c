/*
- keyword: binary search, binary_search, binarysearch

- keypoints: array 무조건 정렬되어 있어야 함!, O(logN)
*/


#include <stdio.h>

// 이진 탐색 함수
int binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        // 목표 값을 찾음
        if (arr[mid] == target) {
            return mid;
        }

        // 목표 값이 중간 값보다 작으면 왼쪽 절반 탐색
        if (arr[mid] > target) {
            right = mid - 1;
        }
        // 목표 값이 중간 값보다 크면 오른쪽 절반 탐색
        else {
            left = mid + 1;
        }
    }

    // 목표 값을 찾지 못함
    return -1;
}

// 이진 탐색 함수 (재귀적)
int binarySearchRecursion(int arr[], int low, int high, int x) {
    if (high >= low) {
        int mid = low + (high - low) / 2;

        // 중간 값이 찾고자 하는 값과 일치하는 경우
        if (arr[mid] == x)
            return mid;

        // 찾고자 하는 값이 중간 값보다 작은 경우, 왼쪽 서브배열에서 탐색
        if (arr[mid] > x)
            return binarySearchRecursion(arr, low, mid - 1, x);

        // 찾고자 하는 값이 중간 값보다 큰 경우, 오른쪽 서브배열에서 탐색
        return binarySearchRecursion(arr, mid + 1, high, x);
    }

    // 요소를 찾지 못한 경우
    return -1;
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 10;
    int result = binarySearch(arr, 0, n - 1, target);
    if (result == -1) {
        printf("Element is not present in array\n");
    } else {
        printf("Element is present at index %d\n", result);
    }
    return 0;
}
