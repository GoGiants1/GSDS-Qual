#include <stdio.h>

// CPP랑 완전 동일

int main() {
    int numbers[] = {1, 2, 3, 4, 5};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    // Print the elements of the array
    for (int i = 0; i < size; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    // Access and modify an element
    numbers[2] = 10;
    printf("Modified element at index 2: %d\n", numbers[2]);

    return 0;
}
