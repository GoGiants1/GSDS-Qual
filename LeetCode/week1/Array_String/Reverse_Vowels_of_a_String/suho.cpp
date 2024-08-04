class Solution {
public:
    string reverseVowels(string s) {
        char v[] = {'a','e','i','o','u','A','E','I','O','U'};
        vector<int> ind(0);

        for(int i = 0; i < s.length(); i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U'){
                ind.push_back(i);
            }
        }

        string res = "";
        for(int i = 0; i < s.length(); i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U'){
                res += s[ind.back()];
                ind.pop_back();
            }
            else {
                res += s[i];
            }
        }

        return res;
    }
};
