/*
Goal: 주어진 문장 IN PLACE로 reverse
Approach: 앞, 뒤에서 시작해서 가운데로 쭉 오면서 서로 바꿔주기 

Input: "Hello, World!"
Output: "!dlroW ,olleH"
*/

#include <stdio.h>
#include <string.h>

void reverseString(char *str) {
    int length = strlen(str);
    int i, j;
    char temp;

    // Loop through the string and reverse it
    for (i = 0, j = length - 1; i < j; i++, j--) {
        // Swap characters at positions i and j
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

int main() {
    // input
    char input[100];
    printf("Enter a sentence: ");
    fgets(input, sizeof(input), stdin);

    // Remove newline character if present
    if (input[strlen(input) - 1] == '\n')
        input[strlen(input) - 1] = '\0';

    // output
    reverseString(input);
    printf("Reversed sentence: %s\n", input);
    return 0;
}