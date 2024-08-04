class Solution {
public:
    string reverseWords(string s) {
        int i, j;
        vector<string> spstr(0);
        string res = "";

        j = 0;
        for(i=s.size()-1;i>=-1;i--){
            if(i==-1 || s[i]==' '){
                if(j!=0){
                    res += s.substr(i+1,j);
                    res += " ";
                    j = 0;
                }
            }
            else j++;
        }
        res.pop_back();

        return res;
    }
};
