#include <iostream>
#include <vector>
using namespace std;

void merge_sort(vector<int> &arr){
    if(arr.size() > 1){
        int mid = arr.size() / 2;
        vector<int> left_half(arr.begin(), arr.begin()+mid);
        vector<int> right_half(arr.begin()+mid, arr.end());

        merge_sort(left_half);
        merge_sort(right_half);

        int i = 0, j = 0, k = 0;

        while(i < left_half.size() and j < right_half.size()){
            if(left_half[i] < right_half[j]){
                arr[k] = left_half[i];
                i++;
            }
            else{
                arr[k] = right_half[j];
                j++;
            }
            k++;
        }

        while(i < left_half.size()){
            arr[k] = left_half[i];
            i++;
            k++;
        }

        while(j < right_half.size()){
            arr[k] = right_half[j];
            j++;
            k++;
        }
    }
}


int main(){
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    merge_sort(arr);

    for(int i = 0; i < arr.size(); i++) printf("%d, ",arr[i]);

    return 0;
}





