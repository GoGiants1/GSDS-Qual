char* reverseWords(char* s) {
    int i = 0, j = 0, k, count, len, reslen = 0, start[501], end[501];
    
    while(s[i]!='\0'){
        if(s[i]!=' '){
            reslen++;
            if(i==0 || s[i-1]==' '){
                start[j] = i;
            }
            if(s[i+1]==' ' || s[i+1]=='\0'){
                end[j] = i;
                j++;
            }
        }
        i++;
    }
    count = j;
    len = i;
    reslen += (count - 1);
    
    char * res = (char*)malloc(sizeof(char)*(reslen+1));
    
    j = 0;
    for(i=count-1;i>=0;i--){
        for(k=0;k<(end[i]-start[i]+1);k++){
            res[j] = s[start[i]+k];
            j++;
        }
        res[j] = ' ';
        j++;
    }
    res[reslen] = '\0';
    
    return res;
}
