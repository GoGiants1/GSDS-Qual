int fib(int *T, int Tlen, int n){
    if(Tlen > n) return T[Tlen-1];
    else{
        T[Tlen] = T[Tlen-1] + T[Tlen-2] + T[Tlen-3];
        Tlen++;
        return fib(T, Tlen, n);
    }
}

int tribonacci(int n){
    if(n == 0) return 0;
    else if(n < 3) return 1;
    else{
        int *T = (int*)malloc(sizeof(int)*40);
        T[0] = 0;
        T[1] = 1;
        T[2] = 1;
        return fib(T,3,n);
    }
}
