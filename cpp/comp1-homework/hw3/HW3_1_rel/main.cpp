#include <iostream> 
#include <climits> 
#include <queue>
#include <cmath>
#include <time.h>
#include <chrono>
using namespace std; 

#include "functions.hpp"

void enqueueLoop(MaxHeap &h, long n){
    for (long i = 1; i <= n; i++){
        h.enqueue(i);
    }
}

void dequeueLoop(MaxHeap &h){
    while (h.getMax() != nullptr){
        h.dequeue();
    }
}

int main() 
{ 
    MaxHeap h; 
    long n = pow(10,5);
    // 10 ** 6 -> 0.5 seconds
    // 10 ** 7 -> 5~6 seconds
    // 10 ** 8 -> 50~60 seconds

    for (int i = 1; i <= 30; i++){
        long n = pow(2,i);
        auto start = chrono::high_resolution_clock::now();
        enqueueLoop(h, n);
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
        cout << "The number of elements in the heap: " << n << endl; // "The number of elements in the heap: 1000000

        cout << "Time taken for Enqueue: " << duration.count() << " microseconds" << endl;

        start = chrono::high_resolution_clock::now();
        dequeueLoop(h);
        end = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<chrono::microseconds>(end - start);
        cout << "Time taken for Dequeue: " << duration.count() << " microseconds" << endl;
    }
    


    // cout << "Maximum value of the heap: " << h.getMax()->val << endl; 

    return 0; 
}