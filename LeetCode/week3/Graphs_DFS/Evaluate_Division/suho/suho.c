/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** dfs(char *node, char *des, char **v, int *vlen, char **sq, int sqlen, char*** equations, int equationsSize){
    if(strcmp(node,des) == 0){
        //string.h
        char **sq2 = (char**)malloc(sizeof(char*)*(sqlen+3));
        sq2[0] = "0";
        sq2[sqlen+2] = "1";
        for(int i = 1; i < sqlen+1; i++) sq2[i] = sq[i-1];
        sq2[sqlen+1] = node;
        sq[sqlen] = node;
        sqlen++;
        return sq2;
    }

    else{
        int isin = 0;
        for(int i = 0; i < *vlen; i++){
            if(strcmp(v[i], node) == 0) isin = 1;
        } 
        if(isin == 0){
            v[*vlen] = node;
            (*vlen)++;
            sq[sqlen] = node;
            sqlen++;

            for(int i = 0; i < equationsSize; i++){
                if (strcmp(equations[i][0], node) == 0 || strcmp(equations[i][1], node) == 0){
                    char **sq2 = dfs(strcmp(equations[i][0], node) == 0 ? equations[i][1] : equations[i][0], des, v, vlen, sq, sqlen, equations, equationsSize);
                    if(strcmp(sq2[0], "0") == 0){
                        sq = sq2;
                        break;
                    }
                }
            }
            return sq;
        }
        else return sq;
    }
}

double* calcEquation(char*** equations, int equationsSize, int* equationsColSize, double* values, int valuesSize, char*** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    double *ans = (double*)malloc(sizeof(double)*queriesSize);
    int alen = 0;
    char **nodes = (char**)malloc(sizeof(char*)*equationsSize*2);
    for(int i = 0; i < equationsSize; i++) nodes[i] = equations[i][0];
    for(int i = 0; i < equationsSize; i++) nodes[i+equationsSize] = equations[i][1];

    for(int i = 0; i < queriesSize; i++){
        int isin = 0;
        for(int j = 0; j < 2*equationsSize; j++){
            if(strcmp(queries[i][0], nodes[j]) == 0) isin = 1;
        }
        if (isin == 0){
            ans[alen] = -1.;
            alen++;
        }
        else if(strcmp(queries[i][0], queries[i][1]) == 0){
            ans[alen] = 1.;
            alen++;
        }
        else{
            char **v = (char**)malloc(sizeof(char*)*equationsSize*2);
            int vlen = 0;
            char **sq = (char**)malloc(sizeof(char*)*equationsSize*2);
            int sqlen = 0;
            char **sq0 = dfs(queries[i][0], queries[i][1], v, &vlen, sq, sqlen, equations, equationsSize);
            if(strcmp(sq0[0],"0") == 0){
                double prod = 1.;
                int sq0len = 0;
                int j = 1;
                while(strcmp(sq0[j],"1") != 0){
                    sq0len++;
                    j++;
                }
                for(int j = 1; j < sq0len; j++){
                    for(int k = 0; k < equationsSize; k++){
                        if(strcmp(equations[k][0], sq0[j]) == 0 && strcmp(equations[k][1], sq0[j+1]) == 0){
                            prod *= values[k];
                            break;
                        }
                        else if(strcmp(equations[k][1], sq0[j]) == 0 && strcmp(equations[k][0], sq0[j+1]) == 0){
                            prod *= 1./values[k];
                            break;
                        }
                    }
                }
                ans[alen] = prod;
                alen++;
            }
            else{
                ans[alen] = -1.;
                alen++;
            }
        }
    }
    (*returnSize) = alen;
    return ans;
}
