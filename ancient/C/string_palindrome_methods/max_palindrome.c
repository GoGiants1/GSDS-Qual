
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isPalindrome(char* s, int start, int end) {
    while (start < end) {
        if (s[start] != s[end]) {
            return 0; // Not a palindrome
        }
        start++;
        end--;
    }
    return 1; // Palindrome
}

void removeChar(char *str, int index) {
    int len = strlen(str);
    if (index >= 0 && index < len) {
        memmove(str + index, str + index + 1, len - index);
        str[len - 1] = '\0';  // Ensure null-termination after removal
    }
}

char ** makeAllSubstr(char* s, int possibleCases) {
    char ** AllSubseqs = (char**)malloc(possibleCases * sizeof(char*));
    int n = strlen(s);
    for (int i = 0; i < possibleCases; i++) {
        AllSubseqs[i] = (char*)malloc((n + 1) * sizeof(char));
        strcpy(AllSubseqs[i], s);

        for (int j = 0; j < n; j++) {
            if ((i >> j) & 1) {
                removeChar(AllSubseqs[i], j);
            }
        }
    }
    return AllSubseqs;
}

void freeAllSubseqs(char** AllSubseqs, int possibleCases) {
    for (int i = 0; i < possibleCases; i++) {
        free(AllSubseqs[i]);
    }
    free(AllSubseqs);
}

void maxPalindrome(char* s) {
    int n = strlen(s);
    int possibleSubseqs = 1;
    for (int i = 0; i < n; i++) {
        possibleSubseqs =possibleSubseqs * 2;
    }
    possibleSubseqs -= 1;

    char** allCases = makeAllSubstr(s, possibleSubseqs);

    int maxLen = 0;
    char* maxPalindrome = NULL;

    for (int i = 0; i < possibleSubseqs; i++) {
        int len = strlen(allCases[i]);
        if (isPalindrome(allCases[i], 0, len - 1) && len > maxLen) {
            maxLen = len;
            if (maxPalindrome != NULL) {
                free(maxPalindrome);
            }
            maxPalindrome = strdup(allCases[i]);
        }
    }

    if (maxPalindrome != NULL) {
        printf("Longest Palindrome: %s\n", maxPalindrome);
        free(maxPalindrome);
    } else {
        printf("No palindrome found.\n");
    }

    freeAllSubseqs(allCases, possibleSubseqs);
}

int main() {
    char input[100];
    
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';  // Remove newline character if present
    
    maxPalindrome(input);

    return 0;
}