class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> sublen(text1.length()+1, vector<int>(text2.length()+1));
        
        for(int i = 0; i < text1.length()+1; i++){ 
            for(int j = 0; j < text2.length()+1; j++){
                if(i == 0 or j == 0) sublen[i][j] = 0;
                else if(text1[i-1] == text2[j-1]) sublen[i][j] = sublen[i-1][j-1] + 1;
                else sublen[i][j] = max(sublen[i-1][j], sublen[i][j-1]);
            }
        }
    
        return sublen[text1.length()][text2.length()];
    }
};
