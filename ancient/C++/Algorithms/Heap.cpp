// Heap implementation, Max heap, Heap sort

// Heap implementation
// - parent = (i-1)/2, right = (2*i)+2, left = (2*i)+1

// Max Heapify: A[1]>= A[i]
// Complexity = O(h)
// - for given wrong position (index), make it max heap
// 1. left = (2*i)+1, right = (2*i)+2
// 2. find largest between left right and me
// 3. if largest!= me, change me and largest and max heapify the original largest index

// Build Max Heap
// Complexity = O(nh) = O(nlgn) -> not tight!! tighter bound = O(n)
// 1. leaf node 는 max heapify 필요없으니까 [n/2] 부터 1 까지 Bottom up으로 max heapify

// Heap Sort
// Complexity = O(nlgn)
// 1. max heapify the graph
// 2. swap the A[0-i] and max heapify for reduced A repeat

#include <iostream>

using namespace std;

class Heap{
public:
    int *harr; // pointer to array of elements in heap
    int capacity; // maximum possible size of heap
    int heap_size; // current number of elements in heap
    Heap(int capacity);
    void insertKey(int k);
    int parent(int i){
        return (i-1)/2;
    }
    int left(int i){
        return (2*i+1);
    }
    int right(int i){
        return (2*i+2);
    }
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
}

void MaxHeapify(Heap A, int i, int n){
    int l = A.left(i);
    int r = A.right(i);
    int largest = -1;

    if (l<n && A.harr[l]>A.harr[i]){
        largest = l;
    }
    else{
        largest = i;
    }
    if(r<n && A.harr[r]>A.harr[largest]){
        largest = r;
    }
    if (largest!=i){
        swap(A.harr[largest],A.harr[i]);
        MaxHeapify(A,largest,n);
    }
}

void BuildMaxHeap(Heap A){
    for (int i = (A.heap_size-1)/2; i>=0; i--){
        MaxHeapify(A,i,A.heap_size);
    }
}

void HeapSort(Heap A){
    BuildMaxHeap(A);
    for (int i=A.heap_size-1; i>=0; i--){
        swap(A.harr[i],A.harr[0]);
        MaxHeapify(A,0,i);
    }
}

int main(){
    Heap A(20);
    A.insertKey(16);
    A.insertKey(4);
    A.insertKey(10);
    A.insertKey(14);
    A.insertKey(7);
    A.insertKey(9);
    A.insertKey(3);
    A.insertKey(2);
    A.insertKey(8);
    A.insertKey(1);

    MaxHeapify(A, 1, 10);
    
    for (int i=0; i<10; i++){
        cout<<A.harr[i]<<" ";
    }
    cout << endl;

    Heap B(20);
    B.insertKey(4);
    B.insertKey(1);
    B.insertKey(3);
    B.insertKey(2);
    B.insertKey(16);
    B.insertKey(9);
    B.insertKey(10);
    B.insertKey(14);
    B.insertKey(8);
    B.insertKey(7);
    BuildMaxHeap(B);

    for (int j=0; j<10; j++){
        cout<<B.harr[j]<<" ";
    }

    cout<<endl;

    Heap C(20);
    C.insertKey(4);
    C.insertKey(1);
    C.insertKey(3);
    C.insertKey(2);
    C.insertKey(16);
    C.insertKey(9);
    C.insertKey(10);
    C.insertKey(14);
    C.insertKey(8);
    C.insertKey(7);
    HeapSort(C);

    for (int j=0; j<10; j++){
        cout<<C.harr[j]<<" ";
    }


}