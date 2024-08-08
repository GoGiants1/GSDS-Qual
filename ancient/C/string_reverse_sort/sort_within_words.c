/*
Goal: 주어진 문장의 "단어들 내에서" sorting. 
Approach: 공백 기준으로 단어 나눠서 각각 sorting한 후 (qsort() 이용) 합치기 

Input: "Hello, World!"
Output: ",olleH !dlroW"
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void* a, const void* b) {
  return (*(char*)a - *(char*)b);
}

char* sort_word(char* word) {
  int len = strlen(word);
  qsort(word, len, sizeof(char), compare);
  return word;
}

int main(){
    int C;
    char input[100], reversed[100];
    printf("Enter a sentence: ");
    fgets(input, 100, stdin);

    // parse input 
    char* token = strtok(input, " ");
    while (token != NULL) {
        // remove '\n' from the input 
        if (token[strlen(token)-1] == '\n') {
            token[strlen(token)-1] = '\0';
        }
        // sort each word, add a single space " " and add it to the reversed string
        strcat(reversed, sort_word(token));
        strcat(reversed, " ");
        token = strtok(NULL, " ");
    }

    printf("%s\n", reversed);
  return 0;
}