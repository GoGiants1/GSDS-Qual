/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** letterCombinations(char* digits, int* returnSize) {
    char G[8][5] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    char **res;
    
    if(strlen(digits)==0){
        *returnSize = 0;
        return res;
    }
    else if(strlen(digits)==1){
        int ind = digits[0] - '0' - 2;
        *returnSize = strlen(G[ind]);
        res = malloc(strlen(G[ind]) * sizeof(char*));
        for (int i = 0; i < strlen(G[ind]); i++) res[i] = malloc(2 * sizeof(char));
        for(int i = 0; i<strlen(G[ind]); i++){
            char *tmp = malloc(sizeof(char)*2);
            tmp[0] = G[ind][i];
            tmp[1] = '\0';
            res[i] = tmp;
        }
        return res;
    }
    else if(strlen(digits)==2){
        int ind1 = digits[0]-'0'-2;
        int ind2 = digits[1]-'0'-2;
        (*returnSize) = strlen(G[ind1]) * strlen(G[ind2]);
        res = malloc((*returnSize) * sizeof(char*));
        for(int i = 0; i < (*returnSize); i++) res[i] = malloc(3 * sizeof(char));
        int ind = 0;
        for(int i = 0; i < strlen(G[ind1]); i++){
            for(int j = 0; j < strlen(G[ind2]); j++){
                char *tmp = malloc(sizeof(char)*3);
                tmp[0] = G[ind1][i];
                tmp[1] = G[ind2][j];
                tmp[2] = '\0';
                res[ind] = tmp;
                ind++;
            }
        }
        return res;
    }
    else if(strlen(digits)==3){
        int ind1 = digits[0]-'0'-2, ind2 = digits[1]-'0'-2, ind3 = digits[2]-'0'-2;
        *returnSize = strlen(G[ind1])*strlen(G[ind2])*strlen(G[ind3]);
        res = malloc((*returnSize) * sizeof(char*));
        for(int i = 0; i < (*returnSize); i++) res[i] = malloc(4 * sizeof(char));
        int ind = 0;
        for(int i = 0; i < strlen(G[ind1]); i++){
            for(int j = 0; j < strlen(G[ind2]); j++){
                for(int k = 0; k < strlen(G[ind3]); k++){
                    char *tmp = malloc(sizeof(char)*4);
                    tmp[0] = G[ind1][i];
                    tmp[1] = G[ind2][j];
                    tmp[2] = G[ind3][k];
                    tmp[3] = '\0';
                    res[ind] = tmp;
                    ind++;
                }
            }
        }
        return res;
    }
    else{
        int ind1 = digits[0]-'0'-2, ind2 = digits[1]-'0'-2, ind3 = digits[2]-'0'-2, ind4 = digits[3]-'0'-2;
        *returnSize = strlen(G[ind1])*strlen(G[ind2])*strlen(G[ind3])*strlen(G[ind4]);
        res = malloc((*returnSize) * sizeof(char*));
        for(int i = 0; i < (*returnSize); i++) res[i] = malloc(5 * sizeof(char));
        int ind = 0;
        for(int i = 0; i < strlen(G[ind1]); i++){
            for(int j = 0; j < strlen(G[ind2]); j++){
                for(int k = 0; k < strlen(G[ind3]); k++){
                    for(int h = 0; h < strlen(G[ind4]); h++){
                        char *tmp = malloc(sizeof(char)*5);
                        tmp[0] = G[ind1][i];
                        tmp[1] = G[ind2][j];
                        tmp[2] = G[ind3][k];
                        tmp[3] = G[ind3][h];
                        tmp[4] = '\0';
                        res[ind] = tmp;
                        ind++;
                    }
                }
            }
        }
        return res;
    }
    return res;
}
