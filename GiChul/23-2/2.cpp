#include <iostream>
#include<algorithm> //string
using namespace std;

struct ret{
    int num;
    string s;
};

int check_palindrome(string s){
    int res = 1;
    if(s.length() >= 2){
        for(int i = 0; i < s.length()/2; i++){
            if(s[i]!=s[s.length()-1-i]){
                res=0;
            }
        }
    }
    return res;
}

ret make_palindrome(string s, int num){
    if(check_palindrome(s)==1){
        ret result = {num, s};
        return result;
    }
    else{
        ret result = {9,""};
        for(int i = 0; i<s.length(); i++){
            string s1 = "";
            for(int j = 0; j<s.length(); j++){
                if(i!=j) s1.push_back(s[j]);
            }   
            
            ret temp = make_palindrome(s1,num+1);
            if(temp.num<=result.num){
                result.num = temp.num;
                result.s = temp.s;
            }
        }
        return result;
    }
}

int main(){
    string s = "apple";
    int num=0;

    ret result = make_palindrome(s,num);
    cout << result.num << " " << result.s << endl;

    return 0;
}

