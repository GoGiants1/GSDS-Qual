// Priority queue using max heap
// maximum(A) return A[0] complexity=O(1)
// ExtractMax(A) max=maximum(A), A[0]=A[n-1], heap_size--, max heapify complexity=O(lgn)

#include <iostream>

using namespace std;

class Heap{
public:
    int *harr; // pointer to array of elements in heap
    int capacity; // maximum possible size of heap
    int heap_size; // current number of elements in heap
    Heap(int capacity);
    void insertKey(int k);
    void increaseKey(int i, int new_val);
    int maximum();
    int extractMax();
    int parent(int i){
        return (i-1)/2;
    }
    int left(int i){
        return (2*i+1);
    }
    int right(int i){
        return (2*i+2);
    }

    void MaxHeapify(int i, int n);
    void BuildMaxHeap();
    void HeapSort();
};

Heap::Heap(int capacity){
    this->capacity = capacity;
    this->heap_size = 0;
    this->harr = new int [capacity];
}

void Heap::insertKey(int k){
    if(heap_size == capacity){
        cout << "\nOverflow: Could not insert key\n";
        return;
    }

    heap_size++;
    int i = heap_size-1;
    harr[i]=k;

    while (i!=0 && harr[parent(i)] < harr[i]){
        swap(harr[i],harr[parent(i)]);
        i = parent(i);
    }
}

void Heap::increaseKey(int i, int new_val){
    if (new_val< harr[i]){
        cout << "new key is smaller than current key ";
    }
    else{
        harr[i] = new_val;
        while (i>0 && harr[parent(i)] < harr[i]){
            swap(harr[i],harr[parent(i)]);
            i = parent(i);
        }
    }
}

int Heap::maximum(){
    if (heap_size<1){
        cout << "underflow";
        return -1;
    }
    return harr[0];
}

int Heap::extractMax(){
    int max = maximum();
    harr[0] = harr[heap_size-1];
    heap_size--;
    MaxHeapify(0,heap_size);
    return max;
}

void Heap::MaxHeapify(int i, int n){
    int l = left(i);
    int r = right(i);
    int largest = -1;

    if (l<n && harr[l]>harr[i]){
        largest = l;
    }
    else{
        largest = i;
    }
    if(r<n && harr[r]>harr[largest]){
        largest = r;
    }
    if (largest!=i){
        swap(harr[largest],harr[i]);
        MaxHeapify(largest,n);
    }
}

void Heap::BuildMaxHeap(){
    for (int i = (heap_size-1)/2; i>=0; i--){
        MaxHeapify(i,heap_size);
    }
}

void Heap::HeapSort(){
    BuildMaxHeap();
    for (int i=heap_size-1; i>=0; i--){
        swap(harr[i],harr[0]);
        MaxHeapify(0,i);
    }
}

int main(){
    Heap A(5);
    A.insertKey(1);
    A.insertKey(2);
    A.insertKey(8);
    A.increaseKey(2,16);
    cout << A.maximum() << " ";
    A.insertKey(50);
    A.increaseKey(1,9);
    cout << A.maximum() << " ";
    A.insertKey(4);
    cout<< A.extractMax() << " ";
    cout << A.maximum() << " ";
    return 0;
}