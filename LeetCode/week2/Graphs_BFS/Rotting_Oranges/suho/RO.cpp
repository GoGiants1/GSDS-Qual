class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int cnt=0, t=0;
        vector<vector<int>> grid_t, grid_t0;
        grid_t.resize(grid.size());
        grid_t0.resize(grid.size());
        copy(grid.begin(), grid.end(), grid_t.begin());
        copy(grid.begin(), grid.end(), grid_t0.begin());

        while(1){
            int cnt0 = cnt;
            cnt = 0;
            for(int i = 0; i<grid.size(); i++){
                for(int j = 0; j<grid[0].size(); j++){
                    if(grid_t0[i][j]==1){
                        cnt++;
                        if((i-1>=0 && grid_t0[i-1][j]==2) || (j-1>=0 && grid_t0[i][j-1]==2) || (i+1<grid.size() && grid_t0[i+1][j]==2) || (j+1<grid[0].size() && grid_t0[i][j+1]==2)){
                            grid_t[i][j] = 2;
                        }
                    }
                }
            }
            if(cnt==0) return t;
            else if(cnt==cnt0) return -1;
            else{
                copy(grid_t.begin(), grid_t.end(), grid_t0.begin());
                t++;
            }
        }
    }
};
