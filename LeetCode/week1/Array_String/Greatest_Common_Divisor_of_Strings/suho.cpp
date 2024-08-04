class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int len1 = str1.length(), len2 = str2.length(), i, j, brk;
        string txt;

        for(i=min(len1,len2); i>0; i--){
            if(len1%i != 0 || len2%i != 0) continue;
            txt = str1.substr(0,i);
            
            brk = 0;
            for(j=1;j<len1/i;j++){
                if(txt != str1.substr(j*i,i)){
                    brk = 1;
                    break;
                }
            }
            if(brk) continue;
            for(j=0;j<len2/i;j++){
                if(txt != str2.substr(j*i,i)){
                    brk = 1;
                    break;
                }
            }
            if(brk) continue;
            else break;
        }

        if(brk) return "";
        else return txt;
    }
};
