class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> prev_row(n, 1);
        vector<int> curr_row(n, 0);
        curr_row[0] = 1;
        for (int i = 1; i < m; ++i){
            for (int j = 1; j < n; ++j){
                curr_row[j] = curr_row[j-1] + prev_row[j];
            }
            prev_row = curr_row;
        }
        
        return prev_row[n-1];
    }
};