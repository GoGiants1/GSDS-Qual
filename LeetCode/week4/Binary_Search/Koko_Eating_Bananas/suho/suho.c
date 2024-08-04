int hours(int *piles, int pilesSize, int k){
    int t = 0;
    for(int i = 0; i < pilesSize; i++){
        t += (int)ceil((float)piles[i]/k);
    }
    return t;
}

int minEatingSpeed(int* piles, int pilesSize, int h) {
    int a = 1, b = 0;
    for(int i = 0; i < pilesSize; i++){
        if(piles[i]>b) b = piles[i];
    }
    int k = (a+b)/2;
    int t = hours(piles, pilesSize, k);
    int k2;
    
    while(1){
        if(t > h) a = k+1;
        else b = k;
        k2 = (a+b)/2;
        if(k == k2) break;
        k = k2;
        t = hours(piles, pilesSize, k);
    }
    
    return k;
}
