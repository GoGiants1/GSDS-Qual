void dfs(int *v, int *vlen, int n, int **connections, int *stepped, int *slen, int *num, int connectionsSize){
    int isin = 0;
    for(int i = 0; i < *vlen; i++){
        if(v[*vlen] == n) isin = 1;
    }

    if(isin == 0){
        v[*vlen] = n;
        (*vlen) += 1;

        for(int i = 0; i < connectionsSize; i++){
            if(connections[i][1]==n){ 
                stepped[*slen] = i;
                (*slen) += 1;
                dfs(v, vlen, connections[i][0], connections, stepped, slen, num, connectionsSize);
            }

            int isin = 0;
            for(int j = 0; j < *slen; j++){
                if(stepped[j] == i) isin = 1;
            }
            if(connections[i][0]==n && isin == 0){
                stepped[*slen] = i;
                (*slen) += 1;
                int tmp = connections[i][0];
                connections[i][0] = connections[i][1];
                connections[i][1] = tmp;
                (*num)+=1;
                dfs(v, vlen, connections[i][0], connections, stepped, slen, num, connectionsSize);
            }
        }
    }
}

int minReorder(int n, int** connections, int connectionsSize, int* connectionsColSize) {
    int num = 0;
    int *v = (int*)malloc(sizeof(int)*50000);
    int vlen = 0;
    int *stepped = (int*)malloc(sizeof(int)*50000);
    int slen = 0;
    dfs(v, &vlen, 0, connections, stepped, &slen, &num, connectionsSize);
    
    return num;
}
