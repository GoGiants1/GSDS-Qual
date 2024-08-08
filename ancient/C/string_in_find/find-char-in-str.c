#include <stdio.h>
#include <string.h>

// 구조체를 사용하여 불리언 값과 사이즈를 함께 반환
typedef struct {
    int found; // 찾았다면 1, 아니면 0
    size_t position; // 문자의 위치
} CharFindResult;

CharFindResult findCharInString(const char* str, char ch) {
    CharFindResult result;
    // 문자열에서 문자를 찾고 위치를 반환
    char* found = strchr(str, ch);
    if (found != NULL) {
        result.found = 1;
        result.position = (size_t)(found - str); 
    } else {
        result.found = 0;
        result.position = 0; // 찾지 못했다면 0
    }
    return result;
}

int main() {
    char myString[101]; 
    char myChar;

    printf("Enter a string (up to 100 characters): ");
    scanf("%100s", myString);

    printf("Enter a character to find: ");
    scanf(" %c", &myChar); // 문자 입력 받음, 앞의 공백은 이전 입력 후 남은 개행 문자 무시를 위함

    CharFindResult result = findCharInString(myString, myChar);

    if (result.found) {
        printf("The character '%c' is found at index %zu.\n", myChar, result.position);
    } else {
        printf("The character '%c' is not found in the string.\n", myChar);
    }

    return 0;
}
