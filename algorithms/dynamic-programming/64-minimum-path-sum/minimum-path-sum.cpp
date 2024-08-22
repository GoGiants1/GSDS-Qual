class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> mem(m, vector<int>(n, INT_MAX));

        return dp(m-1, n-1, grid, mem);
    }

    int dp(int i, int j, vector<vector<int>>& g, vector<vector<int>>& mem){
        if (i < 0 || j < 0){
            return INT_MAX;
        }
        if (i == 0 && j == 0){
            return g[i][j];
        }

        if (mem[i][j] != INT_MAX){
            return mem[i][j];
        }

        int result = min(dp(i-1, j, g, mem), dp(i, j-1, g, mem)) + g[i][j];
        mem[i][j] = result;
        return result;
    }
};