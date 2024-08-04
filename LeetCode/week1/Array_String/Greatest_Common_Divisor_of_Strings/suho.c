char* gcdOfStrings(char* str1, char* str2) {
    int len1 = strlen(str1), len2 = strlen(str2), i, j, brk;

    for(i = (len1<len2?len1:len2); i>0; i--){
        if(len1%i != 0 || len2%i != 0) continue;
        
        char * txt = (char*)malloc(sizeof(char)*i);
        for(j = 0; j<i; j++){
            txt[j] = str1[j];
        }

        brk = 0;
        for(j=0;j<len1;j++){
            if(str1[j]!=txt[j%i]){
                brk = 1;
                break;
            }
        }
        if(brk) continue;
        
        for(j=0;j<len2;j++){
            if(str2[j]!=txt[j%i]){
                brk = 1;
                break;
            }
        }
        if(brk) continue;
        else break;
    }
    
    if(brk) return "";
    else{
        char * res = (char*)malloc(sizeof(char)*(i+1));
        for(j = 0; j<i; j++) res[j] = str1[j];
        res[j] = '\0';
        return res;
    }
}
