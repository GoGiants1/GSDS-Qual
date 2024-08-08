#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// https://blogshine.tistory.com/122 참고하기

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

bool nextPermutation(int a[], int n) {
    int i = n - 1;
    while (i > 0 && a[i - 1] >= a[i]) i -= 1; // 뒤에서 앞으로 가면서 i-1 >= i가 아니면 끝 (1번)
    if (i <= 0) return false; // 만약 마지막 순열이라면 끝난다
    int j = n - 1;
    while (a[j] <= a[i - 1]) j -= 1; // 뒤에서 앞으로 가면서 크면서 가장 작은 수를 구한다 (2번)
    swap(&a[i - 1], &a[j]); // 두 수의 위치를 바꾼다 (3번)
    j = n - 1;
    while (i < j) { // i < n-1까지의 수열을 뒤집는다 (4번)
        swap(&a[i], &a[j]);
        i += 1;
        j -= 1;
    }
    return true; // 다음 수열이 존재한다면 true
}

void swapStr(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

bool nextPermutationStr(char *a, int n) {
    int i = n - 1;
    while (i > 0 && a[i - 1] >= a[i]) i -= 1; // 뒤에서 앞으로 가면서 i-1 >= i가 아니면 끝 (1번)
    if (i <= 0) return false; // 만약 마지막 순열이라면 끝난다
    int j = n - 1;
    while (a[j] <= a[i - 1]) j -= 1; // 뒤에서 앞으로 가면서 크면서 가장 작은 수를 구한다 (2번)
    swapStr(&a[i - 1], &a[j]); // 두 수의 위치를 바꾼다 (3번)
    j = n - 1;
    while (i < j) { // i < n-1까지의 문자열을 뒤집는다 (4번)
        swapStr(&a[i], &a[j]);
        i += 1;
        j -= 1;
    }
    return true; // 다음 수열이 존재한다면 true
}

void printString(char *str) {
    // while (*str != '\0') {
    //     putchar(*str);
    //     str++;
    // }
    // putchar('\n');
    int i=0;
    while(str[i]!='\0'){
        printf("%c",str[i]);
        i++;
    }
    printf("\n");
}

void printArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
    char str[] = "abc"; // 문자열을 초기화

    printf("Original String: ");
    printString(str);

    // nextPermutationStr 함수를 호출하여 다음 순열이 존재하는 경우 출력
    int count = 1;
    while (nextPermutationStr(str, sizeof(str) - 1)) {
        printf("Next Permutation %d: ", count);
        printString(str);
        count++;
    }

    int arr[] = {1, 2, 3}; // 정수 배열을 초기화
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array: ");
    printArray(arr, n);

    // nextPermutation 함수를 호출하여 다음 순열이 존재하는 경우 출력
    int cnt = 1;
    while (nextPermutation(arr, n)) {
        printf("Next Permutation %d: ", cnt);
        printArray(arr, n);
        cnt++;
    }

    return 0;
}

int factorial(int n) {
    if (n <= 1)
        return 1;
    return n * factorial(n - 1);
}

// int main() {
//     int arr[] = {1, 2, 3}; // 정수 배열을 초기화
//     int n = sizeof(arr) / sizeof(arr[0]);

//     int num_permutations = factorial(n);
//     int permutations[num_permutations][n];

//     // 배열 복사를 위한 함수
//     void copyArray(int src[], int dest[], int length) {
//         for (int i = 0; i < length; i++) {
//             dest[i] = src[i];
//         }
//     }

//     // 모든 순열 생성 및 저장
//     int current_permutation = 0;
//     do {
//         copyArray(arr, permutations[current_permutation], n);
//         current_permutation++;
//     } while (nextPermutation(arr, n));

//     // 2차원 배열에 저장된 모든 순열 출력
//     for (int i = 0; i < num_permutations; i++) {
//         for (int j = 0; j < n; j++) {
//             printf("%d ", permutations[i][j]);
//         }
//         printf("\n");
//     }

//     return 0;
// }

// int main() {
//     char str[] = "abc"; // 문자열을 초기화
//     int n = strlen(str);

//     int num_permutations = factorial(n);
//     char permutations[num_permutations][n + 1];

//     // 배열 복사를 위한 함수
//     void copyString(char *src, char *dest, int length) {
//         strncpy(dest, src, length);
//         dest[length] = '\0';
//     }

//     // 모든 순열 생성 및 저장
//     int current_permutation = 0;
//     do {
//         copyString(str, permutations[current_permutation], n);
//         current_permutation++;
//     } while (nextPermutationStr(str, n));

//     // 2차원 배열에 저장된 모든 순열 출력
//     for (int i = 0; i < num_permutations; i++) {
//         printf("%s\n", permutations[i]);
//     }

//     return 0;
// }