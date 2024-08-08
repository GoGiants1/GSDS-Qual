/*
Goal: 주어진 array 정렬, ascending order (char 말고 다른 type array여도 가능)
Approach: bubble sort 

Input 1: {5, 2, 1, 4, 3}
Output 1: 1 2 3 4 5
Input 2: "hello321";
Output 2: 123ehllo
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare_int(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int compare_char(const void *a, const void *b) {
    return (*(char*)a - *(char*)b);
}

void sort(void *arr, int n, size_t elem_size, int (*compare)(const void*, const void*)) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            char *p1 = (char*)arr + j*elem_size;
            char *p2 = (char*)arr + (j+1)*elem_size;
            if (compare(p1, p2) > 0) {
                // swap p1 and p2
                char temp[elem_size];
                memcpy(temp, p1, elem_size);
                memcpy(p1, p2, elem_size);
                memcpy(p2, temp, elem_size);
            }
        }
    }
}

int main() {
    int arr_int[] = {5, 2, 1, 4, 3};
    char arr_char[] = "hello321";
    
    sort(arr_int, 5, sizeof(int), compare_int);
    sort(arr_char, strlen(arr_char), sizeof(char), compare_char);

    for (int i = 0; i < 5; i++) {
        printf("%d ", arr_int[i]);
    }
    printf("\n%s\n", arr_char);

    return 0;
}

