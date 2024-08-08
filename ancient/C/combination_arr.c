#include <stdio.h>
#include <stdlib.h>

void combinationUtil(int arr[], int n, int data[], int start, int end, 
                     int index, int r, int ***combinations, int *size, int *count);

// Function to initialize and call the util function
int** printCombination(int arr[], int n, int r, int *returnSize) {
    int **combinations = malloc(10000 * sizeof(int*)); // Assuming a maximum of 10000 combinations
    int *data = (int*)malloc(r * sizeof(int));
    int count = 0; // To keep track of the number of combinations
    
    // Call the util function
    combinationUtil(arr, n, data, 0, n-1, 0, r, &combinations, returnSize, &count);
    
    free(data); // Clean up temporary array
    
    return combinations; // Return the array of combinations
}

void combinationUtil(int arr[], int n, int data[], int start, int end,
                     int index, int r, int ***combinations, int *returnSize, int *count) {
    if (index == r) {
        // Allocate memory for a new combination
        int *newCombination = malloc(r * sizeof(int));
        for (int j = 0; j < r; j++) {
            newCombination[j] = data[j]; // Copy the combination
        }
        (*combinations)[*count] = newCombination; // Store the combination
        (*count)++; // Increment the count of combinations
        *returnSize = *count; // Update the return size
        return;
    }
    
    for (int i = start; i <= end && end - i + 1 >= r - index; i++) {
        data[index] = arr[i];
        combinationUtil(arr, n, data, i + 1, end, index + 1, r, combinations, returnSize, count);
    }
}

// Example usage
int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int r = 2;
    int n = sizeof(arr) / sizeof(arr[0]);
    int returnSize;
    
    // Get combinations
    int **combinations = printCombination(arr, n, r, &returnSize);
    
    // Print combinations
    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < r; j++) {
            printf("%d ", combinations[i][j]);
        }
        printf("\n");
        free(combinations[i]); // Clean up individual combination
    }
    free(combinations); // Clean up the array of combinations
    
    return 0;
}