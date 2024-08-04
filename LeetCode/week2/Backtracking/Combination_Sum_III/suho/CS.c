/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void combi(int k, int n, int *l, int llen, int **agg, int *returnsize, int **returnColumnSizes){
    if (l[llen-1]>n) return;
    else if (l[llen-1]==9) return;
    else if(llen>k) return;
    else{
        int sum = 0;
        for(int i = 0; i< llen; i++) sum+=l[i];
        if(sum>n) return;
        else if(llen==k && sum==n){
            agg[*returnsize] = l;
            *returnColumnSizes[*returnsize] = k;
            (*returnsize)++;
            return;
        }
        else if(llen<k){
            for(int i = l[llen-1]+1;i<n-sum+1;i++){
                int *l2 = (int*)malloc(sizeof(int)*(k+1));
                for(int j = 0; j<llen; j++) l2[j] = l[j];
                l2[llen] = i;
                combi(k, n, l2, llen+1, agg, returnsize, returnColumnSizes);
            }
            return;
        }
    }
}

int** combinationSum3(int k, int n, int* returnSize, int** returnColumnSizes) {
    int **agg = (int**)malloc(sizeof(int*)*100000);
    *returnSize = 0;
    *returnColumnSizes = (int*)malloc(sizeof(int) * 100000);

    int i = 0;
    for(i = 1; i<10; i++){
        int *l = (int*)malloc(sizeof(int)*(k+1));
        l[0] = i;
        int llen = 1;
        combi(k, n, l, llen, agg, returnSize, returnColumnSizes);
        
    }
    return agg;
}
