#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ALPHABET_SIZE 26
#define MAX_LEN 50

void swap(char* str, int i, int j) {
    char temp = str[i];
    str[i] = str[j];
    str[j] = temp;
}

void generatePermutations(char* str, int start, int end, char** result, int* count) {
    if (start == end) {
        result[*count] = strdup(str);
        (*count)++;
    } else {
        for (int i = start; i <= end; i++) {
            swap(str, start, i);
            generatePermutations(str, start + 1, end, result, count);
            swap(str, start, i);
        }
    }
}

int factorial(int n) {
    return (n == 0 || n == 1) ? 1 : n * factorial(n - 1);
}

char** getAllPermutations(char* str, int* resultSize) {
    int len = strlen(str);
    *resultSize = factorial(len);

    char** result = (char**)malloc(*resultSize * sizeof(char*));

    int count = 0;
    generatePermutations(str, 0, len - 1, result, &count);

    return result;
}

int** findForbidden(char* s) {
    int input_len = strlen(s);

    int** forbid = (int**)malloc(ALPHABET_SIZE * sizeof(int*));
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        forbid[i] = (int*)malloc(ALPHABET_SIZE * sizeof(int));
        memset(forbid[i], 0, ALPHABET_SIZE * sizeof(int));
    }

    for (int i = 0; i < input_len; i++) {
        int cur = s[i] - 'a';
        if (i == 0) {
            int forbidden = s[i + 1] - 'a';
            forbid[cur][forbidden]++;
        } else if (i == input_len - 1) {
            int forbidden = s[i - 1] - 'a';
            forbid[cur][forbidden]++;
        } else {
            int forbidden_l = s[i - 1] - 'a';
            int forbidden_r = s[i + 1] - 'a';
            forbid[cur][forbidden_l]++;
            forbid[cur][forbidden_r]++;
        }
    }

    return forbid;
}

int checkAdjacency(int** forbid, char* s) {
    int s_len = strlen(s);
    for (int i = 0; i < s_len; i++) {
        int cur = s[i] - 'a';
        if (i == 0) {
            int right = s[i + 1] - 'a';
            if (forbid[cur][right] > 0)
                return 0;
        } else if (i == s_len - 1) {
            int left = s[i - 1] - 'a';
            if (forbid[cur][left] > 0)
                return 0;
        } else {
            int left = s[i - 1] - 'a';
            int right = s[i + 1] - 'a';
            if (forbid[cur][right] > 0 || forbid[cur][left] > 0)
                return 0;
        }
    }
    return 1;
}

char** foo(char* s, int* validCount) {
    int resultSize;
    char** permutations = getAllPermutations(s, &resultSize);
    char** result = (char**)malloc(10000000 * sizeof(char*));
    int idx = 0;
    int** forbidden = findForbidden(s);
    for (int i = 0; i < resultSize; i++) {
        if (checkAdjacency(forbidden, permutations[i]) == 1) {
            result[idx] = strdup(permutations[i]);
            idx++;
        }
        free(permutations[i]);  // Free memory allocated for each permutation
    }
    result[idx] = NULL;
    *validCount = idx;

    // Free the memory allocated for the result array
    free(permutations);
    return result;
}
char* removeDuplicates(const char* input) {
    if (input == NULL) {
        return NULL;
    }

    int inputLength = strlen(input);
    if (inputLength <= 1) {
        // 문자열의 길이가 1 이하인 경우 중복이 없으므로 복사하여 반환
        char* result = (char*)malloc(inputLength + 1);
        strcpy(result, input);
        return result;
    }

    // 중복을 제거한 문자열을 생성
    char* result = (char*)malloc(inputLength + 1);
    int resultIndex = 0;

    for (int i = 0; i < inputLength; ++i) {
        int isDuplicate = 0;
        for (int j = 0; j < resultIndex; ++j) {
            if (input[i] == result[j]) {
                isDuplicate = 1;
                break;
            }
        }
        if (!isDuplicate) {
            result[resultIndex++] = input[i];
        }
    }
    result[resultIndex] = '\0';

    return result;
}

char** bar(char* s, int* validCount) {

    int** forbidden = findForbidden(s);
    
    char* woDuplicates=removeDuplicates(s);
    int resultSize;
    int idx = 0;
    char** permutations = getAllPermutations(woDuplicates, &resultSize);
    char** result = (char**)malloc(10000000 * sizeof(char*));




    for (int i = 0; i < resultSize; i++) {
        if (checkAdjacency(forbidden, permutations[i]) == 1) {
            result[idx] = strdup(permutations[i]);
            idx++;
        }
        free(permutations[i]);  // Free memory allocated for each permutation
    }
    result[idx] = NULL;
    *validCount = idx;

    // Free the memory allocated for the result array
    free(permutations);
    return result;
}



int main() {
    char input[MAX_LEN];

    printf("Enter a string: ");
    scanf("%s", input);

    int validCount;
    char** validPermutations = bar(input, &validCount);

    // Print the valid permutations
    for (int i = 0; i < validCount; i++) {
        printf("%s\n", validPermutations[i]);
        free(validPermutations[i]);  // Free memory allocated for each valid permutation
    }

    // Free the memory allocated for the valid permutations array
    free(validPermutations);

    return 0;
}
