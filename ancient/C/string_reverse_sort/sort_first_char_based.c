/*
Goal: 주어진 문장 속 단어들의 "첫번째 글자"를 기준으로 단어 순서 정렬 
Approach: 공백 기준으로 단어 나눠서 각각 sorting한 후 (qsort() 이용) 합치기 

Input: "banana apple orange"
Output: "apple banana orange"
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(const void * a, const void * b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int main() {
    char sentence[] = "banana apple orange";
    char *words[50]; // 각 단어들 저장할 array
    int i = 0;

    char *word = strtok(sentence, " ");
    while (word != NULL) {
        words[i++] = word;
        word = strtok(NULL, " ");
    }

    qsort(words, i, sizeof(char *), compare);

    for (int j = 0; j < i; j++) {
        printf("%s ", words[j]);
    }

    return 0;
}