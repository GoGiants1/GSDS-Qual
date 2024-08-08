#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* sliceString(const char* str, int start, int end) {
    int len = strlen(str);
    
    // 음수 인덱스 처리
    if (start < 0) start = len + start;
    if (end < 0) end = len + end;

    if (start > end || start < 0 || end > len) return NULL;

    int sliceLen = end - start;
    char* result = (char*)malloc(sliceLen + 1); 

    if (!result) return NULL; 

    strncpy(result, str + start, sliceLen); 
    result[sliceLen] = '\0';

    return result;
}

char* concatStrings(const char* first, const char* second) {
    int firstLen = strlen(first);
    int secondLen = strlen(second);
    char* result = (char*)malloc(firstLen + secondLen + 1); // +1 for the null-terminator

    if (!result) return NULL;

    memcpy(result, first, firstLen);
    memcpy(result + firstLen, second, secondLen + 1); // +1 to include the null-terminator

    return result;
}

int main() {
    const char* s = "abcde";
    char* firstSlice = sliceString(s, 1, -2); // Equivalent to Python's s[1:-2]
    char* secondSlice = sliceString(s, 2, -1); // Another slice for demonstration

    if (firstSlice && secondSlice) {
        char* combined = concatStrings(firstSlice, secondSlice);
        if (combined) {
            printf("Combined string: %s\n", combined);
            free(combined);
        }
        free(firstSlice); 
        free(secondSlice);
    } else {
        printf("Invalid slice\n");
    }

    return 0;
}