int minCostClimbingStairs(int* cost, int costSize) {
    int *T = (int*)malloc(sizeof(int)*1000);
    T[0] = 0;
    T[1] = 0;
    int i = 1;
    int Tlen = 2;
    while(i < costSize){
        T[Tlen] = T[i]+cost[i] < T[i-1]+cost[i-1] ? T[i]+cost[i] : T[i-1]+cost[i-1];
        i++;
        Tlen++;
    }
    return T[Tlen-1];
}
