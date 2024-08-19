#include <iostream>
using namespace std;

// 두 변수의 값을 교환하는 함수
void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// Selection Sort 알고리즘
void selectionSort(int arr[], int n) {
    int i, j, min_idx;

    // 배열의 각 요소에 대해 최소값을 찾음
    for (i = 0; i < n-1; i++) {
        // i 번째 요소를 최소값으로 가정
        min_idx = i;
        
        // 나머지 배열에서 최소값을 찾음
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }

        // 찾은 최소값을 현재 위치(i)로 이동
        swap(&arr[min_idx], &arr[i]);
    }
}

// 배열의 내용을 출력하는 함수
void printArray(int arr[], int size) {
    for (int i=0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    // 배열을 선택 정렬로 정렬
    selectionSort(arr, n);
    
    // 정렬된 배열을 출력
    cout << "Sorted array: \n";
    printArray(arr, n);
    
    return 0;
}
