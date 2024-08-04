char* reverseVowels(char* s) {
    int i = 0, j, count = 0, len;
    while(s[i] != '\0'){
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U'){
            count++;
        }
        i++;
    }
    len = i;

    char * v = (char*)malloc(sizeof(char)*count);
    char * res = (char*)malloc(sizeof(char)*(len+1));

    j = 0;
    for(i=0;i<len;i++){
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U'){
            v[j] = s[i];
            j++;
        }
        else{
            res[i] = s[i];
        }
    }

    j=count-1;
    for(i=0;i<len;i++){
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U'){
            res[i] = v[j];
            j--;
        }
    }
    res[len] = '\0';

    return res;
}
