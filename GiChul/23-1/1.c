#include <stdio.h>
#include <string.h>
#include<stdlib.h>

char* iter_foo(char* s, char* full_s){
    if(strlen(s)==strlen(full_s)) return s;
    else{
        char *left = (char*)malloc(sizeof(char)*(strlen(full_s)+1));
        strcpy(left,full_s);
        int i;
        for(i = 0; i < strlen(s); i++){
            for(int j = 0; j < strlen(left); j++){
                if(left[j]==s[i]){
                    int k = j;
                    while(left[k]!= '\0'){
                        left[k] = left[k+1];
                        k++;
                    }
                    break;
                }
            }
        }

        char *next = (char*)malloc(sizeof(char)*(strlen(left)+1));
        strcpy(next, left);
        i = 0;
        while(i<strlen(next)){
            int adj = 0;
            int j;
            for(j = 0; j < strlen(full_s); j++){
                if(full_s[j]==s[strlen(s)-1]){
                    if(j==0 && full_s[j+1]==next[i]) adj=1;
                    if(j==strlen(full_s)-1 && full_s[j-1]==next[i]) adj=1;
                    if((j!=strlen(full_s)-1 && j!=0) && (full_s[j-1]==next[i] || full_s[j+1]==next[i])) adj=1;
                } 
            }
            if(adj==1){
                j = i;
                while(next[j]!='\0'){
                    next[j] = next[j+1];
                    j++;
                }
                i--;
            }
            i++;
        }

        char *t = "";
        for(int i = 0; i < strlen(next); i++){
            char *s1 = (char*)malloc(sizeof(char)*(strlen(s)+2));
            strcpy(s1,s);
            int s1len = strlen(s1);
            s1[s1len] = next[i];
            s1[s1len+1] = '\0';

            char *tmp = iter_foo(s1,full_s);
            if(strlen(tmp)!=0) t = tmp; 
        }

        return t;
    }
}

char* foo(char* s){
    if (strlen(s) < 3) return "";
    else{
        char *t = iter_foo("",s);
        return t;
    }
}

char* iter_bar(char* s, char* full_s, char* all_letter){
    if(strlen(s)==strlen(all_letter)) return s;
    else{
        char *left = (char*)malloc(sizeof(char)*(strlen(all_letter)+1));
        strcpy(left,all_letter);
        int i;
        for(i = 0; i < strlen(s); i++){
            for(int j = 0; j < strlen(left); j++){
                if(left[j]==s[i]){
                    int k = j;
                    while(left[k]!= '\0'){
                        left[k] = left[k+1];
                        k++;
                    }
                    break;
                }
            }
        }

        char *next = (char*)malloc(sizeof(char)*(strlen(left)+1));
        strcpy(next, left);
        i = 0;
        while(i<strlen(next)){
            int adj = 0;
            int j;
            for(j = 0; j < strlen(full_s); j++){
                if(full_s[j]==s[strlen(s)-1]){
                    if(j==0 && full_s[j+1]==next[i]) adj=1;
                    if(j==strlen(full_s)-1 && full_s[j-1]==next[i]) adj=1;
                    if((j!=strlen(full_s)-1 && j!=0) && (full_s[j-1]==next[i] || full_s[j+1]==next[i])) adj=1;
                } 
            }
            if(adj==1){
                j = i;
                while(next[j]!='\0'){
                    next[j] = next[j+1];
                    j++;
                }
                i--;
            }
            i++;
        }

        char *t = "";
        for(int i = 0; i < strlen(next); i++){
            char *s1 = (char*)malloc(sizeof(char)*(strlen(s)+2));
            strcpy(s1,s);
            int s1len = strlen(s1);
            s1[s1len] = next[i];
            s1[s1len+1] = '\0';

            char *tmp = iter_bar(s1,full_s,all_letter);
            if(strlen(tmp)!=0) t = tmp; 
        }

        return t;
    }
}

char* bar(char* s){
    if (strlen(s) < 3) return "";
    else{
        char *all_letter = (char*)malloc(sizeof(char)*(strlen(s)+1));
        int all_len = 0;
        for(int i = 0; i < strlen(s); i++){
            int isin = 0;
            for(int j = 0; j < all_len; j++){
                if(all_letter[j]==s[i]) isin=1;
            }
            if(isin==0){
                all_letter[all_len] = s[i];
                all_len++;
            }
        }

        char *t = iter_bar("",s,all_letter);
        return t;
    }
}

int main(){
    printf("%s\n", foo("abccdef"));
    printf("%s\n", bar("abccdef"));
    return 0;
}

