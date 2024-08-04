int longestCommonSubsequence(char* text1, char* text2) {
    int **sublen = (int**)malloc(sizeof(int*)*(strlen(text1)+1));
    for(int i = 0; i < strlen(text1) + 1; i++) sublen[i] = (int*)calloc(strlen(text2)+1, sizeof(int));
        
    for(int i = 0; i < strlen(text1)+1; i++){ 
        for(int j = 0; j < strlen(text2)+1; j++){
            if(i == 0 || j == 0) sublen[i][j] = 0;
            else if(text1[i-1] == text2[j-1]) sublen[i][j] = sublen[i-1][j-1] + 1;
            else sublen[i][j] = sublen[i-1][j] > sublen[i][j-1] ? sublen[i-1][j] : sublen[i][j-1];
        }
    }

    return sublen[strlen(text1)][strlen(text2)];
}
