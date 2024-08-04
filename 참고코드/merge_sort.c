#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void merge_sort(int* arr, int alen){
    if(alen > 1){
        int mid = alen / 2;
        int *left_half = (int*)malloc(sizeof(int)*mid);
        int *right_half = (int*)malloc(sizeof(int)*(alen-mid));

        memcpy(left_half, arr, sizeof(int)*mid);
        memcpy(right_half, arr+mid, sizeof(int)*(alen-mid));

        merge_sort(left_half, mid);
        merge_sort(right_half, alen-mid);

        int i = 0, j = 0, k = 0;

        while(i < mid && j < (alen-mid)){
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

        while(i < mid){
            arr[k] = left_half[i];
            i++;
            k++;
        }

        while(j < (alen-mid)){
            arr[k] = right_half[j];
            j++;
            k++;
        }
    }
}


int main(){
    int arr[6] = {12, 11, 13, 5, 6, 7};
    int *a = arr;
    merge_sort(a, 6);

    for(int i = 0; i < 6; i++) printf("%d, ",a[i]);

    return 0;
}





