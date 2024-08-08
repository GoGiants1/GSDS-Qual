/*
Goal: 주어진 문장 reverse, 이 때 결과값은 새로운 array에 저장 
Approach: 맨 뒤에서 시작해서 맨 앞으로 쭉 오면서 result array에 넣어주기

Input: "Hello, World!"
Output: "!dlroW ,olleH"
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* reverseString(const char *str) {
    int length = strlen(str);
    char *reversed = (char *)malloc((length + 1) * sizeof(char)); 
    if (reversed == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    int i, j;
    // Reverse the string
    for (i = length - 1, j = 0; i >= 0; i--, j++) {
        reversed[j] = str[i];
    }
    reversed[j] = '\0';

    return reversed;
}

int main(){
    // input
    char input[100];
    printf("Enter a sentence: ");
    fgets(input, sizeof(input), stdin);

    // Remove newline character if present
    if (input[strlen(input) - 1] == '\n')
        input[strlen(input) - 1] = '\0';

    // output
    char* result = reverseString(input);
    printf("%s\n", result);
    free(result);
    return 0; 
}