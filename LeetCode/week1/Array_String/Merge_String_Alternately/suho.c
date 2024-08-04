char * mergeAlternately(char * word1, char * word2){
    int i = strlen(word1), j = strlen(word2), k = 0, n;
    char * txt = (char*)malloc(sizeof(char) * (1 + i + j));
    
    for (n = 0; n < i || n < j; n++){
        if (n < i) {
            txt[k] = word1[n];
            k++;
        }
        if (n < j) {
            txt[k] = word2[n];
            k++;
        }
    }
    txt[k] = '\0';

    return txt;
}
