class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        // 길이가 1과 2인 DP 배열 초기화
        int i, j, max_len;
        int start = 0;
        max_len = 1;
        for (i = 0; i < n; i++){
            dp[i][i] = true;
        }
        
        for(i = 1; i < n; i++){
            if(s[i-1] == s[i]){
                dp[i-1][i] = true;
                start = i - 1;
                max_len = 2;
            }
        }

        for (int len = 3; len < n + 1; len++){
            for (i = 0; i + len - 1 < n; i++){
                int j = i + len - 1;
                if (s[i] == s[j] && dp[i + 1][j - 1]){
                    dp[i][j] = true;
                    start = i;
                    max_len = len;
                }
            }
        }
        return s.substr(start, max_len);
    }
};