class Solution {
public:
    int compress(vector<char>& chars) {
        vector<char> s(0);
        int i, j, count = 0;
        for(i=0;i<chars.size();i++){
            count++;
            if(i==chars.size()-1 || chars[i+1]!=chars[i]){
                s.push_back(chars[i]);
                if(count!=1){
                    for(j=0;j<to_string(count).length();j++) s.push_back(to_string(count)[j]);
                }  
                count = 0;
            }
        } 

        for(i=0;i<s.size();i++) chars[i] = s[i];
        return s.size();
    }
};
