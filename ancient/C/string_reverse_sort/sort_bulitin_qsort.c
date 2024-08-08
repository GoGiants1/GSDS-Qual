/*
Goal: 주어진 array 정렬, ascending order (char 말고 다른 type array여도 가능)
Approach: 내장 qsort() 함수 이용. 직접 구현한 버전은 sort_implement_*.c 참조 

Input: "banana apple orange"
Output: "  aaaaabeeglnnnoppr"
Output(중복 제거): " abeglnopr"
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(const void * a, const void * b) {
    return *(char*)a - *(char*)b;
}

int main() {
    char sentence[] = "banana apple orange";
    int n = strlen(sentence);

    qsort(sentence, n, sizeof(char), compare); 
    printf("%s\n", sentence);

    ///////////// Optional - 중복 제거 /////////////
    printf("After removing duplicates: ");
    char lastChar = '\0';
    for (int i = 0; i < n; i++) {
        if (sentence[i] != lastChar) {
            printf("%c", sentence[i]); // 지금은 프린트 형식, 원하면 새 array 파서 저장하는 식으로 해도 될 듯  
            lastChar = sentence[i];
        }
    }
    printf("\n");
    //////////////// Optional end ////////////////

    return 0;
}