#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void perm(char *incomp, char *left, char **res, int *reslen){
    if(strcmp(left,"") == 0){
        int isin = 0;
        for(int i = 0; i < *reslen; i++){
            if(strcmp(res[i],incomp)==0) isin = 1;
        }
        if(isin == 0){
            res[*reslen] = incomp;
            (*reslen)++;
        }

    }

    else{
        for(int i = 0; i < strlen(left); i++){
            char *incomp2 = (char*)malloc(sizeof(char)*(strlen(incomp)+2));
            strcpy(incomp2, incomp);
            incomp2[strlen(incomp)] = left[i];
            incomp2[strlen(incomp)+1] = '\0';
            char *left2 = (char*)malloc(sizeof(char)*(strlen(left)));
            int k = 0;
            for(int j = 0; j < strlen(left); j++){
                if(i!=j){
                    left2[k] = left[j];
                    k++;
                }
            }
            left2[k] = '\0';
            perm(incomp2, left2, res, reslen);
        }
    }
}

char** str_perm(char *s){
    char **res = (char**)malloc(sizeof(char*)*1000);
    int reslen = 0;
    char *left = s;
    char *incomp = "";
    perm("", left, res, &reslen);

    return res;
}

int main(){
    char *s1 = "abc";
    char *s2 = "abb";

    char** res1 = str_perm(s1);
    char** res2 = str_perm(s2);

    for(int i = 0; i < 7; i++){
        printf("%s ",res1[i]);
    }
    printf("\n");

    for(int i = 0; i < 4; i++){
        printf("%s ",res2[i]);
    }
    printf("\n");

    return 0;
}

//memset(des, 0, 3*sizeof(int));
//memset(des, 'a', 3*sizeof(char));
//(int*)calloc(3,siezeof(int)); init with 0
//(char*)calloc(3,siezeof(char)); init with NULL

