//Insertion Sort 카드정리
//Complexity = O(n^2)
//Algorithm
//1. unsorted된 array중에서 가장 왼쪽에 있는거를 sorted array의 맞는 위치에 넣는다.

#include <iostream>
#include <string>
#include <vector>

using namespace std;
void swap(vector <int> &A, int sortedidx, int currentidx){
    int temp = A[sortedidx];
    A[sortedidx] = A[currentidx];
    A[currentidx] = temp;
}

int main(){
    vector <int> A{2, 5, 4, 7, 8, 1 ,9};
    int n = A.size();

    for (int i=0; i<n; i++){
        int sortedidx = i-1;
        int currentidx = i;
        while (sortedidx >= 0 && (A[sortedidx] > A[currentidx])){
            swap(A,sortedidx,currentidx);
            currentidx -= 1;
            sortedidx -= 1;
        }
    }

    for (int i: A){
        cout<< i << " ";
    }
}