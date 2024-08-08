/*
Goal: 주어진 문장의 "단어들 내에서" reverse. 
Approach: 공백 기준으로 단어 나누고 각 단어 reverse

Input: "Hello, World!"
Output: ",olleH !dlroW"
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to reverse a word
void reverseWord(char *word) {
    int length = strlen(word);
    int i, j;
    char temp;

    // Reverse the word
    for (i = 0, j = length - 1; i < j; i++, j--) {
        temp = word[i];
        word[i] = word[j];
        word[j] = temp;
    }
}

// Function to reverse each word in a sentence
char* reverseWords(const char *sentence) {
    int length = strlen(sentence);
    char *reversedSentence = (char *)malloc((length + 1) * sizeof(char)); 
    if (reversedSentence == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    int wordStart = 0;
    int wordEnd = 0;
    int writeIndex = 0;
    for (int i = 0; i <= length; i++) {
        if (sentence[i] == ' ' || sentence[i] == '\0') {
            wordEnd = i - 1;
            // Reverse the word
            for (int j = wordStart; j <= wordEnd; j++) {
                reversedSentence[writeIndex++] = sentence[wordEnd - j + wordStart];
            }
            // Add space between words
            if (sentence[i] == ' ')
                reversedSentence[writeIndex++] = ' ';
            wordStart = i + 1;
        }
    }
    // Null terminate the reversed sentence
    reversedSentence[writeIndex] = '\0';

    return reversedSentence;
}

int main() {
    char sentence[100];

    // Input sentence from user
    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    // Remove the newline character if present
    if (sentence[strlen(sentence) - 1] == '\n')
        sentence[strlen(sentence) - 1] = '\0';

    // Reverse each word in the sentence
    char *reversedWordsSentence = reverseWords(sentence);

    // Output the reversed sentence
    printf("Reversed sentence: %s\n", reversedWordsSentence);

    // Free the allocated memory
    free(reversedWordsSentence);

    return 0;
}
