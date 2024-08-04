int minDistance(char* word1, char* word2) {
    int **D = (int**)malloc(sizeof(int*)*(strlen(word1)+1));
    for(int i = 0; i < strlen(word1) + 1; i++) D[i] = (int*)calloc(strlen(word2)+1, sizeof(int));
    
    for(int i = 0; i < strlen(word1)+1; i++) D[i][0] = i;
    for(int i = 0; i < strlen(word2)+1; i++) D[0][i] = i;

    for(int i = 1; i < strlen(word1)+1; i++){
        for(int j = 1; j < strlen(word2)+1; j++){
            int a = D[i-1][j] + 1, b = D[i][j-1] + 1, c = D[i-1][j-1] + (word1[i-1] == word2[j-1] ? 0 : 1);
            D[i][j] = a > b ? (b > c ? c : b) : (a > c ? c : a);
        }
    }
    
    return D[strlen(word1)][strlen(word2)];
}
