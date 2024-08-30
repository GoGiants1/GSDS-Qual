#include <stdio.h>

void swap(int* a, int* b)
{

    int temp = *a;
    *a = *b;
    *b = temp;
}

// To heapify a subtree rooted with node i
// which is an index in arr[].
// n is size of heap
void maxHeapify(int arr[], int N, int i)
{
    // Find largest among root,
    // left child and right child

    // Initialize largest as root
    int largest = i;

    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < N && arr[left] > arr[largest])
        largest = left;

    if (right < N && arr[right] > arr[largest])
        largest = right;

    // Swap and continue heapifying
    // if root is not largest
    if (largest != i) {
        swap(&arr[i], &arr[largest]);

        maxHeapify(arr, N, largest);
    }
}

void minHeapify(int arr[], int N, int i)
{
    // Find smallest among root,
    // left child and right child

    // Initialize smallest as root
    int smallest = i;

    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < N && arr[left] < arr[smallest])
        smallest = left;

    if (right < N && arr[right] < arr[smallest])
        smallest = right;

    // Swap and continue heapifying
    // if root is not smallest
    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);

        minHeapify(arr, N, smallest);
    }
}

void heapSortAscending(int arr[], int N)
{

    // Build max heap
    for (int i = N / 2 - 1; i >= 0; i--)

        maxHeapify(arr, N, i);

    // Heap sort
    for (int i = N - 1; i >= 0; i--) {

        swap(&arr[0], &arr[i]);

        // 이미 정렬되어 뺀 i번째 요소를 제외한 나머지 요소들로 heapify
        // 0~i-1 개를 이용해서 heapify
        maxHeapify(arr, i, 0);
    }
}

void heapSortDescending(int arr[], int N)
{

    // Build min heap
    for (int i = N / 2 - 1; i >= 0; i--)

        minHeapify(arr, N, i);

    // Heap sort
    for (int i = N - 1; i >= 0; i--) {

        swap(&arr[0], &arr[i]);

        // 이미 정렬되어 뺀 i번째 요소를 제외한 나머지 요소들로 heapify
        // 0~i-1 개를 이용해서 heapify
        minHeapify(arr, i, 0);
    }
}

void printArray(int arr[], int N)
{
    for (int i = 0; i < N; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int N = sizeof(arr) / sizeof(arr[0]);

    heapSortAscending(arr, N);
    printf("Sorted array Ascending is\n");
    printArray(arr, N);

    heapSortDescending(arr, N);
    printf("Sorted array Descending is\n");
    printArray(arr, N);
}