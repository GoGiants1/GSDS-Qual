#include <stdio.h>
#include <stdlib.h>

int arraysEqual(int* a, int* b, int size) {
    for (int i = 0; i < size; i++) {
        if (a[i] != b[i]) return 0; // 배열의 요소가 다르면 0 반환
    }
    return 1; // 모든 요소가 같으면 1 반환
}

int isArrSubarray(int* subArray, int subArraySize, int** mainArray, int mainArraySize) {
    for (int i = 0; i < mainArraySize; i++) {
        if (arraysEqual(subArray, mainArray[i], subArraySize)) {
            return 1; // subArray가 mainArray의 요소 중 하나와 일치
        }
    }
    return 0; // 일치하는 요소가 없음
}


int main() {
    int subArray[] = {1, 2, 3};
    int subArraySize = sizeof(subArray) / sizeof(subArray[0]);
    
    // 각 배열을 먼저 선언
    int arr1[] = {1, 2, 3};
    int arr2[] = {2, 3, 1};
    int arr3[] = {2, 1, 3};

    // 배열들의 주소를 mainArray에 저장
    int* mainArray[] = {arr1, arr2, arr3};
    int mainArraySize = sizeof(mainArray) / sizeof(mainArray[0]);


    int result = isArrSubarray(subArray, subArraySize, mainArray, mainArraySize);
    if (result) {
        printf("The subArray is a part of mainArray.\n");
    } else {
        printf("The subArray is NOT a part of mainArray.\n");
    }

    return 0;
}
