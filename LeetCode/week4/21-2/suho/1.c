#include <stdio.h>
#include <stdlib.h>

int smallest_pos_int( int *a, int N ){
    int *h = (int*)calloc(N+1, sizeof(int));
    for(int i = 0; i < N; i++){
        if(a[i]<N+1 && a[i]>0){
            h[a[i]-1] = 1;
        }
    }
    int ans = 0;
    while(h[ans]==1){
        ans++;
    }
    return ans+1;
}

int main(){
    int arr[5] = {1,1,2,3,-1};
    int *a = arr;
    int N = 5;
    printf("%d\n", smallest_pos_int(a, N));

    return 0;
}
