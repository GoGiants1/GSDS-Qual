void dfs(int *visited, int *vlen, int num, int **rooms, int *roomsColSize){
    int isin = 0;
    for(int i = 0; i < *vlen; i++){
        if(visited[i]==num) isin = 1;
    }

    if(isin==0){
        printf("%d\n",num);
        visited[*vlen]=num;
        (*vlen)++;
        for(int i = 0; i < roomsColSize[num]; i++) dfs(visited, vlen, rooms[num][i], rooms, roomsColSize);
    }
}   

bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize) {
    int *visited = (int*)malloc(sizeof(int)*roomsSize);
    int vlen = 0;
    dfs(visited, &vlen, 0, rooms, roomsColSize);
    return vlen == roomsSize;
}
