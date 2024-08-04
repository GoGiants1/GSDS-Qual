class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i = word1.length(), j = word2.length();
        string txt = "";

        for(int n = 0; n < (i>j?i:j); n++){
            if(n<i) txt.append(1,word1[n]);
            if(n<j) txt.append(1,word2[n]);
        }
        return txt;
    }
};
