#include <stdio.h>
#include <string.h> //strlen, strcpy
#include <stdlib.h> //malloc

typedef struct ret{
    int num;
    int len;
    char *s;
}retval;

int check_palindrome(char *s, int len){
    int res = 1;
    if(len >= 2){
        for(int i = 0; i < len/2; i++){
            if(s[i]!=s[len-1-i]){
                res=0;
            }
        }
    }
    return res;
}

retval make_palindrome(char *s, int len, int num){
    if(check_palindrome(s, len)==1){
        retval result = {num, len, s};
        return result;
    }
    else{
        int tempnum = 9;
        retval result = {9,1,(char*)malloc(sizeof(char) * 15)};
        for(int i = 0; i<len; i++){
            char *s1 = (char*)malloc(sizeof(char) * 15);
            int k=0;
            for(int j = 0; j<len; j++){
                if(i!=j){
                    s1[k] = s[j];
                    k++;
                }
            }
            s1[k] = '\0';       
            
            retval temp = make_palindrome(s1,len-1,num+1);
            if(temp.num<=result.num){
                result.num = temp.num;
                result.len = temp.len;
                strcpy(result.s,temp.s);
            }
        }
        return result;
    }
}

int main(){
    char *s = "radar";
    int len = strlen(s), num=0;

    retval result = make_palindrome(s,len,num);
    printf("%d, %s\n", result.num, result.s);



    return 0;
}

