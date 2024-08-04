void dfs(int *v, int *vlen, int node, int **isConnected, int isConnectedSize){
    int isin = 0;
    for(int i = 0; i < *vlen; i++){
        if(v[i]==node) isin = 1;
    }
    
    if(isin==0){
        v[*vlen] = node;
        (*vlen) += 1;

        for(int i = 0; i < isConnectedSize; i++){
            if(isConnected[node][i]==1) dfs(v, vlen, i, isConnected, isConnectedSize);
        } 
    }
}

int findCircleNum(int** isConnected, int isConnectedSize, int* isConnectedColSize) {
    int *v = (int*)malloc(sizeof(int)*200);
    int vlen = 0;
    int num = 0;

    for(int i = 0; i < isConnectedSize; i++){
        int isin = 0;
        for(int j = 0; j < vlen; j++){
            if(v[j]==i) isin = 1;
        }

        if(isin==0){
            num++;
            dfs(v, &vlen, i, isConnected, isConnectedSize);
        }
    }
    
    return num;
}
