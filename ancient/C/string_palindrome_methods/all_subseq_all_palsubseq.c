#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
(cf) subsequence는 순서가 지켜진 (연속되지 않은 형태의) 문자열임. substring과 다른 개념!

functions
getLengthSubseq : duplicate 없이 각 length별로 subsequence를 구해내는 것.
getAllSubseq : duplicate 없이 모든 length의 subsequence를 구해내는 것.
PalindromeSubseq : palindrome인 모든 Subsequence를 구해내는 것. getAllSubseq이나 getLengthSubseq에서 받아온 char** array를 넣어줘야 함~

struct
MaxMinPalindrome : minimum, maximum palindrome 정보를 저장하는 struct

main 함수 (line 207) 의 출력결과 :

Enter a string: abbabb
bbb abb bba aba bab aab
All Unique Subsequences:
babb bbabb b ab aba aab bbb bab ba bb abb aabb abbab abbabb abba bbab abbbb a bba abbb bbbb ababb aa abab
Palindromic Subsequences : bbabb b aba bbb bab bb abba a bbbb aa
Maximum Palindrome: bbabb

*/


typedef struct {
    char* maxPalindrome;
    char* minPalindrome;
} MaxMinPalindrome;


void backtrack(char* str, int start, int seqLength, char* path, int pathIndex, char*** allSubseq, int* count, int* capacity) {
    if (pathIndex == seqLength) {
        for (int i = 0; i < *count; i++) { // 중복 검사
            if (strcmp((*allSubseq)[i], path) == 0) return;
        }
        if (*count == *capacity) {
            *capacity *= 2;
            *allSubseq = (char**)realloc(*allSubseq, (*capacity) * sizeof(char*));
        }
        (*allSubseq)[*count] = (char*)malloc((seqLength + 1) * sizeof(char));
        strncpy((*allSubseq)[*count], path, seqLength);
        (*allSubseq)[*count][seqLength] = '\0';
        (*count)++;
        return;
    }
    
    for (int i = start; str[i] != '\0'; i++) {
        path[pathIndex] = str[i];
        backtrack(str, i + 1, seqLength, path, pathIndex + 1, allSubseq, count, capacity);
    }
}

// enter 기준 출력
// void printArray(char** arr, int count) {
//     for (int i = 0; i < count; ++i) {
//         printf("%s\n", arr[i]);
//     }
// }

// 공백 기준 출력
void printArray(char** arr, int count) {
    for (int i = 0; i < count; ++i) {
        printf("%s ", arr[i]);
    }
    printf("\n");
}

void freeArray(char** arr, int count) {
    for (int i = 0; i < count; ++i) {
        free(arr[i]);
    }
    free(arr);
}


bool isPalindrome_(char* s) {
    int start = 0;
    int end = strlen(s) - 1;
    while (start < end){
        if (s[start] != s[end]) {
            return false;
        }
        start += 1;
        end -= 1;
    }
    return true;
}


bool isStringInArray(char* str, char** array, int arraySize) {
    for (int i = 0; i < arraySize; i++) {
        if (strcmp(array[i], str) == 0) {
            return true;
        }
    }
    return false;
}


char** getLengthSubseq(char* str, int seqLength, int* count) {
    int capacity = 10;
    char** allSubseq = (char**)malloc(capacity * sizeof(char*)); 
    *count = 0;
    char* path = (char*)malloc((seqLength + 1) * sizeof(char)); 
    
    backtrack(str, 0, seqLength, path, 0, &allSubseq, count, &capacity);
    free(path);
    
    qsort(allSubseq, *count, sizeof(char*), (int(*)(const void*, const void*))strcmp);
    char** noDupAllSubseq = (char**)malloc((*count) * sizeof(char*));
    
    // insert elemnts (non duplicates)
    int unique = 0;
    for (int i=0; i < *count; i++){
        int stlen = strlen(allSubseq[i]);
        if (noDupAllSubseq && !isStringInArray(allSubseq[i], noDupAllSubseq, unique)){
            noDupAllSubseq[unique] = (char*)malloc((stlen+1) * sizeof(char));
            strncpy(noDupAllSubseq[unique], allSubseq[i], stlen+1);
            unique++;
        }
    }
    if (unique < *count){
        noDupAllSubseq = (char**)realloc(noDupAllSubseq, unique*sizeof(char*));
    }
    *count = unique;
    
    return noDupAllSubseq;
}


char** getAllSubseq(char* str, int* allcount) {
    int capacity = 10;
    char** allSubseq = (char**)malloc(capacity * sizeof(char*)); 
    *allcount = 0;
    for (int seqLength = 1; seqLength <= strlen(str); seqLength++) {
        int count = 0;
        char* path = (char*)malloc((seqLength + 1) * sizeof(char));
        backtrack(str, 0, seqLength, path, 0, &allSubseq, allcount, &capacity);
        free(path);
    }
    qsort(allSubseq, *allcount, sizeof(char*), (int(*)(const void*, const void*))strcmp);
    char** noDupAllSubseq = (char**)malloc((*allcount) * sizeof(char*));

    int unique=0;
    for (int i=0; i < *allcount; i++){
        int stlen = strlen(allSubseq[i]);
        if (noDupAllSubseq && !isStringInArray(allSubseq[i], noDupAllSubseq, unique)){
            noDupAllSubseq[unique] = (char*)malloc((stlen+1) * sizeof(char));
            strncpy(noDupAllSubseq[unique], allSubseq[i], stlen+1);
            unique++;
        }
    }
    if (unique < *allcount){
        noDupAllSubseq = (char**)realloc(noDupAllSubseq, unique*sizeof(char*));
    }
    *allcount = unique;


    return noDupAllSubseq;
}

char** PalindromeSubseq(char** allsubstrs, int count, int* palcount){
    char** allpals = (char**)malloc(count * sizeof(char*)); 
    *palcount = 0;
    for (int i = 0; i < count; i++){
        if (isPalindrome_(allsubstrs[i])) {
            int stlen = strlen(allsubstrs[i]); 
            allpals[*palcount] = (char*)malloc((stlen + 1) * sizeof(char)); 
            strncpy(allpals[*palcount], allsubstrs[i], stlen + 1); 
            (*palcount)++;
        }
    }
    if (*palcount < count){
        allpals = (char**)realloc(allpals, (*palcount) * sizeof(char*)); 
    }
    return allpals;
}


MaxMinPalindrome findMaxMinPalindrome(char** palArray, int palcount) {
    MaxMinPalindrome result = {NULL, NULL};
    if (palcount == 0) return result; 

    int maxLength = 0, minLength = strlen(palArray[0]);
    result.maxPalindrome = palArray[0];
    result.minPalindrome = palArray[0];

    for (int i = 0; i < palcount; i++) {
        int currLength = strlen(palArray[i]);
        if (currLength > maxLength) {
            maxLength = currLength;
            result.maxPalindrome = palArray[i];
        }
        if (currLength < minLength) {
            minLength = currLength;
            result.minPalindrome = palArray[i];
        }
    }

    return result;
}


int main() {
    char str[100]; // 입력 받을 문자열의 최대 길이
    printf("Enter a string: ");
    scanf("%99s", str); // 문자열 입력 받음

    int seqLength = 3;
    int count = 0;
    int allcount=0;
    int palcount;

    char** subseqArray = getLengthSubseq(str, seqLength, &count);
    printArray(subseqArray, count);

    char** allsubseqArray = getAllSubseq(str, &allcount);
    printf("All Unique Subsequences:\n");
    printArray(allsubseqArray, allcount);

    char** palArray = PalindromeSubseq(allsubseqArray, allcount, &palcount);
    printf("Palindromic Subsequences : ");
    printArray(palArray, palcount);

    MaxMinPalindrome maxmin = findMaxMinPalindrome(palArray, palcount);
    printf("Maximum Palindrome: %s\n", maxmin.maxPalindrome ? maxmin.maxPalindrome : "None");


    freeArray(subseqArray, count);
    freeArray(allsubseqArray, allcount);
    freeArray(palArray, palcount);

    return 0;
}
