/*
- keyword: linear search, sequential search

- keypoints: Time proportional to len(L), linked list에서 자주 사용
*/

#include <stdio.h>

int LinearSearch(int arr[], int size, int target) {
    for(int i = 0; i < size; i++) {
        if(arr[i] == target)
            return i;
    }
    return -1;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 3;

    int result = LinearSearch(arr, size, target);
    
    if(result != -1) {
        printf("Element found at index: %d\n", result);
    } else {
        printf("Element not found\n");
    }

    return 0;
}
