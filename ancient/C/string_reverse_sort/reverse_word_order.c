/*
Goal: 주어진 문장에서 단어의 "순서만" reverse
Approach: 맨 뒤에서 시작해서 맨 앞으로 쭉 오면서 result array에 넣어주기, 이 때 이전 문자가 공백이면 스킵 

Input: "Hello, World!"
Output: "World! Hello,"
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* reverseWords(char* s) {
    char* words[1000]; 
    int n_words = 0; 
    char* result = (char*)malloc((strlen(s)+1)*sizeof(char));

    // parse input sentence s
    char* token = strtok(s, " ");
    while (token != NULL) {
        words[n_words++] = token;
        token = strtok(NULL, " ");
    }  
    
    for (int i=n_words-1; i>=0; i--){
        strcat(result, words[i]); 
        if (i != 0){
            strcat(result, " "); // add space between words 
        }
    }    

    return result; 
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
    char* result = reverseWords(input);
    printf("%s\n", result);
    free(result); 
    return 0; 
}