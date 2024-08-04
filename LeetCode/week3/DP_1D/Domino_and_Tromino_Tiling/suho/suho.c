int numTilings(int n) {
    int T[1000];
    T[0] = 1;
    int i = 1;
    while(i <= n){
        if(i <= 1) T[i] = T[i - 1];
        else if (i <= 2) T[i] = T[i - 1] + T[i - 2];
        else if (i <= 3) T[i] = T[i - 1] + T[i - 2] + T[i - 3] * 2;
        else{
            T[i] = T[i - 1] + T[i - 2];
            for(int j = 0; j < i-2; j++) T[i] += T[j]*2;
        }
        i++;
    }

    return T[i - 1];
}
