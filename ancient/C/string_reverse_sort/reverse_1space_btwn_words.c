/*
Goal: 주어진 문장 reverse, 이 때 공백은 단어 사이 딱 하나씩만 들어가도록 (,.! 등도 단어에 포함)
Approach: 맨 뒤에서 시작해서 맨 앞으로 쭉 오면서 result array에 넣어주기, 이 때 공백을 하나만 넣기 위해 새로운 단어 시작할 때만 공백 추가해줌 

Input: "  Hello,    World!  "
Output: "!dlroW ,olleH"
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* reverseString(char* s){
    int len = strlen(s);
    char* result = (char*)malloc((len+1)*sizeof(char));
    result[0] = '\0';

    int result_idx = 0, string_idx = len-1; 
    while (string_idx >= 0){
        if (s[string_idx]==' '){
            if (string_idx+1 < (len-1) && string_idx != 0 && s[string_idx+1] != ' '){ 
                result[result_idx++] = ' ';
            } 
        } else {
            result[result_idx++] = s[string_idx];
        }
        string_idx--; 
    }

    result[result_idx] = '\0';
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
    char* result = reverseString(input);
    printf("%s\n", result);
    free(result);
    return 0; 
}