#include <iostream>
using namespace std;

// 두 변수의 값을 교환하는 함수
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 배열을 분할하고 피벗 위치를 반환하는 함수
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // 피벗을 배열의 마지막 요소로 설정
    int i = (low - 1); // i는 피벗보다 작은 요소들의 끝 인덱스를 가리킴

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) { // 피벗보다 작은 요소를 발견하면
            i++; // i를 증가시키고
            swap(&arr[i], &arr[j]); // i와 j의 요소를 교환
        }
    }
    swap(&arr[i + 1], &arr[high]); // 피벗을 올바른 위치로 이동
    return (i + 1); // 피벗의 위치를 반환
}

// Quick Sort 알고리즘
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // 배열을 분할하고 피벗 위치를 얻음

        quickSort(arr, low, pi - 1); // 피벗을 기준으로 왼쪽 부분을 정렬
        quickSort(arr, pi + 1, high); // 피벗을 기준으로 오른쪽 부분을 정렬
    }
}

// 배열의 내용을 출력하는 함수
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    // 배열을 퀵 정렬로 정렬
    quickSort(arr, 0, n - 1);
    
    // 정렬된 배열을 출력
    cout << "Sorted array: \n";
    printArray(arr, n);
    
    return 0;
}
