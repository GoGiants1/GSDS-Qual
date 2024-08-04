class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> up(m, vector<int>(n));
        up[0][0] = 1;
        
        for(int i = 0; i <  m; i++){
            for(int j = 0; j < n; j++){
                cout << i << j << endl;
                if(i==0){
                    if(j==0) up[i][j] = 1;
                    else up[i][j] = up[i][j-1];
                }
                else if(j==0) up[i][j] = up[i-1][j];
                else up[i][j] = up[i][j-1] + up[i-1][j];
            }
        }
        
        return up[m-1][n-1];
    }
};
