/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void swap(int* nums, int i, int j){
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}

void generatePermutations(int* nums, int numsSize, int index, int** result, int* returnSize, int** returnColumnSizes){
    if (index == numsSize){
        result[*returnSize] = malloc(numsSize * sizeof(int));
        memcpy(result[*returnSize], nums, numsSize * sizeof(int));
        (*returnColumnSizes)[*returnSize] = numsSize;
        (*returnSize)++;
        return;
    }

    for (int i = index; i < numsSize; i++){
        swap(nums, index, i);
        generatePermutations(nums, numsSize, index+1, result, returnSize, returnColumnSizes);
        swap(nums, index, i); //Backtrack
    }
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int totalPermutations = 1;
    for (int i=1; i <= numsSize; i++){
        totalPermutations *= i;
    }
    int** result = (int**)malloc(totalPermutations * sizeof(int*));
    *returnColumnSizes = (int*)malloc(totalPermutations * sizeof(int));
    *returnSize = 0;

    generatePermutations(nums, numsSize, 0, result, returnSize, returnColumnSizes);

    return result;

}

int main(){
    int nums[] = {1, 2, 3};
    int returnSize;
    int* returnColumnSizes;
    int** result = permute(nums, 3, &returnSize, &returnColumnSizes);
    for (int i=0; i<returnSize; i++){
        for (int j=0; j<returnColumnSizes[i]; j++){
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    return 0;
}