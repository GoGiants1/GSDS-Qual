#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool palindrome(string s){
    string sr = s;
    reverse(sr.begin(),sr.end());
    return s.substr(0,s.length()/2)==sr.substr(0,sr.length()/2);
}

bool substring(string s, string t){
    return s.find(t) != string::npos;
}

vector<string> max_palindrome(string s){
    vector<string> palin_list(0);
    for(int i = 0; i < s.length(); i++){
        for(int j = i+1; j < s.length()+1; j++){ 
            if(palindrome(s.substr(i,j-i))) palin_list.push_back(s.substr(i,j-i));
        }
    }

    int i = 0;
    while(i < palin_list.size()){
        for(int j = 0; j < palin_list.size(); j++){
            if(i != j){
                if(substring(palin_list[j],palin_list[i])){
                    palin_list.erase(palin_list.begin() + i);
                    i--;
                    break;
                }
            }
        }
        i++;
    }

    return palin_list;
}

int main(){
    printf("%d %d %d %d\n", palindrome("ababa"), palindrome("abccba"), palindrome("abadhc"), palindrome("abash"));
    printf("%d %d %d %d\n", substring("abcde", "abcde"), substring("abcde", ""), substring("abcde", "abc"), substring("abcde", "abe"));
    vector<string> maxp1 = max_palindrome("kabccbadzdefgfeda");
    vector<string> maxp2 = max_palindrome("kabccba dzabccbaza");
    for(int i = 0; i < maxp1.size(); i++) cout << "'" << maxp1[i] << "', ";
    cout << endl;
    for(int i = 0; i < maxp2.size(); i++) cout << "'" << maxp2[i] << "', ";
    cout << endl;

    return 0;
}