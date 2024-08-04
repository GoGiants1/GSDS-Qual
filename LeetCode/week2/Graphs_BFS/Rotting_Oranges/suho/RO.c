int orangesRotting(int** grid, int gridSize, int* gridColSize) {
    int cnt=0, t=0;
    int (*grid_t)[*gridColSize] = malloc(sizeof(int[gridSize][*gridColSize]));
    int (*grid_t0)[*gridColSize] = malloc(sizeof(int[gridSize][*gridColSize]));
    for(int i = 0; i<gridSize; i++){
        for(int j = 0; j<*gridColSize; j++){
            grid_t[i][j] = grid[i][j];
            grid_t0[i][j] = grid[i][j];
        }
    }

    while(1){
        int cnt0 = cnt;
        cnt = 0;
        for(int i = 0; i<gridSize; i++){
            for(int j = 0; j<*gridColSize; j++){
                if(grid_t0[i][j]==1){
                    cnt++;
                    if((i-1>=0 && grid_t0[i-1][j]==2) || (j-1>=0 && grid_t0[i][j-1]==2) || (i+1<gridSize && grid_t0[i+1][j]==2) || (j+1<*gridColSize && grid_t0[i][j+1]==2)){
                        grid_t[i][j] = 2;
                    }
                }
            }
        }
        if(cnt==0) return t;
        else if(cnt==cnt0) return -1;
        else{
            for(int i = 0; i<gridSize; i++){
                for(int j = 0; j<*gridColSize; j++){
                    grid_t0[i][j] = grid_t[i][j];
                }
            }
            t++;
        }
    }
}
