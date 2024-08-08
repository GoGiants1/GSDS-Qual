#include <stdio.h>
#include <stdlib.h>

void combinationUtil(char arr[], int n, char data[], int start, int end, 
                     int index, int r, char ***combinations, int *size, int *count);

// Function to initialize and call the util function
char** printCombination(char arr[], int n, int r, int *returnSize) {
    char **combinations = malloc(10000 * sizeof(char*)); // Assuming a maximum of 10000 combinations
    char *data = malloc((r + 1) * sizeof(char)); // +1 for null terminator
    int count = 0; // To keep track of the number of combinations
    
    // Call the util function
    combinationUtil(arr, n, data, 0, n-1, 0, r, &combinations, returnSize, &count);
    
    free(data); // Clean up temporary array
    
    return combinations; // Return the array of combinations
}

void combinationUtil(char arr[], int n, char data[], int start, int end,
                     int index, int r, char ***combinations, int *returnSize, int *count) {
    if (index == r) {
        data[index] = '\0'; // Null-terminate the current combination
        // Allocate memory for a new combination
        char *newCombination = malloc((r + 1) * sizeof(char));
        for (int j = 0; j < r; j++) {
            newCombination[j] = data[j]; // Copy the combination
        }
        newCombination[r] = '\0'; // Ensure the combination is null-terminated
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
    char arr[] = "abcde";
    int r = 3;
    int n = sizeof(arr) - 1; // -1 to exclude null terminator from count
    int returnSize;
    
    // Get combinations
    char **combinations = printCombination(arr, n, r, &returnSize);
    
    // Print combinations
    for (int i = 0; i < returnSize; i++) {
        printf("%s\n", combinations[i]);
        free(combinations[i]); // Clean up individual combination
    }
    free(combinations); // Clean up the array of combinations
    
    return 0;
}