#include <iostream>
using namespace std;

// 두 개의 서브 배열을 병합하는 함수
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1; // 왼쪽 서브 배열 크기
    int n2 = r - m;     // 오른쪽 서브 배열 크기

    // 임시 배열 생성
    int L[n1], R[n2];

    // 데이터 복사
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;

    // 임시 배열에서 원래 배열로 병합
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // 남은 요소들을 복사
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Merge Sort 알고리즘
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2; // 중간 인덱스 계산

        mergeSort(arr, l, m);    // 왼쪽 반을 정렬
        mergeSort(arr, m + 1, r); // 오른쪽 반을 정렬

        merge(arr, l, m, r);     // 병합
    }
}

// 배열의 내용을 출력하는 함수
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    cout << "Given array is \n";
    printArray(arr, arr_size);

    // 배열을 병합 정렬로 정렬
    mergeSort(arr, 0, arr_size - 1);

    cout << "\nSorted array is \n";
    printArray(arr, arr_size);
    return 0;
}
