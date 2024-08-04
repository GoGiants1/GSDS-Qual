class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> D(word1.length()+1, vector<int>(word2.length()+1));
        for(int i = 0; i < word1.length()+1; i++) D[i][0] = i;
        for(int i = 0; i < word2.length()+1; i++) D[0][i] = i;

        for(int i = 1; i < word1.length()+1; i++){
            for(int j = 1; j < word2.length()+1; j++){
                D[i][j] = min(min(D[i-1][j] + 1, D[i][j-1] + 1), D[i-1][j-1] + (word1[i-1] == word2[j-1] ? 0 : 1));
            }
        }
        
        return D[word1.length()][word2.length()];
    }
};
