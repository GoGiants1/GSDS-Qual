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
