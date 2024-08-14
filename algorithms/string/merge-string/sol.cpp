// string도 벡터처럼 가변 길이 대응, push_back 사용 가능.
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string res;

        for (int it1 = 0, it2 = 0; it1 < word1.size() || it2 < word2.size(); ++it1, ++it2)
        {
            if (it1 < word1.size())
                res.push_back(word1[it1]);
            if (it2 < word2.size())
                res.push_back(word2[it2]);
        }

        return res;
    }
};


class Solution2 {
public:
    string mergeAlternately(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        int max_len = max(m,n);

        vector<char> out;

        for (int i = 0; i < max_len; ++i){
            if (i < m){
                out.push_back(word1[i]);
            }
            if (i < n){
                out.push_back(word2[i]);
            }
        }
        
        string str_out(out.begin(), out.end());

        return str_out;
    }
};