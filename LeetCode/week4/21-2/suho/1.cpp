#include <iostream>
#include <vector>
using namespace std;

int smallest_pos_int( vector<int> a, int N ){
    vector<int> h(N, 0);
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
    vector<int> a = {1,1,2,3,-1};
    int N = 5;
    printf("%d\n", smallest_pos_int(a, N));

    return 0;
}
