#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

string iter(string s, map<char,vector<char>> G, map<char,int> num, int len){
    if(s.length()==len) return s;
    else{
        vector<char> next = s==""? G['#'] : G[s[s.length()-1]];
        string t = "";

        for(int i = 0; i < next.size();  i++){
            if (num[next[i]] > 0) {
                map<char,int> num1 = num;
                string s1 = s;
                s1.push_back(next[i]);
                num1[next[i]] --;
                string tmp = iter(s1,G,num1,len);
                if (tmp!="") t = tmp; 
            }
        }

        return t;
    }
}

string foo(string s){
    string t;
    if (s.length() < 3) t = "";
    else{
        map<char,vector<char>> G1;
        map<char,vector<char>> G;
        map<char,int> num;

        vector<char> allletter(0);
        for(int i = 0; i < s.length(); i++){
            if(find(allletter.begin(), allletter.end(), s[i]) == allletter.end()) allletter.push_back(s[i]);
        }

        for(int i = 0; i < s.length(); i++){
            if(G.count(s[i])==0){
                G['#'] = allletter;
                G[s[i]] = allletter;
                G1[s[i]] = vector<char>{};
                num[s[i]] = 1;      
            }
            else num[s[i]]++;

            if(i==0) G1[s[i]].push_back(s[i+1]);
            else if(i==s.length()-1) G1[s[i]].push_back(s[i-1]);
            else{
                G1[s[i]].push_back(s[i-1]);
                G1[s[i]].push_back(s[i+1]);
            }
        
        for(int i = 0; i < s.length(); i++){
            for(int j = 0; j < G1[s[i]].size(); j++){
                G[s[i]].erase(remove(G[s[i]].begin(), G[s[i]].end(), G1[s[i]][j]), G[s[i]].end());
            }
        }

        t = iter("",G,num,s.size());
        }
    }
    return t;
}

string bar(string s){
    string t;
    if (s.length() < 3) t = "";
    else{
        map<char,vector<char>> G1;
        map<char,vector<char>> G;
        map<char,int> num;

        vector<char> allletter(0);
        for(int i = 0; i < s.length(); i++){
            if(find(allletter.begin(), allletter.end(), s[i]) == allletter.end()) allletter.push_back(s[i]);
        }

        for(int i = 0; i < s.length(); i++){
            if(G.count(s[i])==0){
                G['#'] = allletter;
                G[s[i]] = allletter;
                G1[s[i]] = vector<char>{};
                num[s[i]] = 1;      
            }

            if(i==0) G1[s[i]].push_back(s[i+1]);
            else if(i==s.length()-1) G1[s[i]].push_back(s[i-1]);
            else {
                G1[s[i]].push_back(s[i-1]);
                G1[s[i]].push_back(s[i+1]);
            }
        
        for(int i = 0; i < s.length(); i++){
            for(int j = 0; j < G1[s[i]].size(); j++){
                G[s[i]].erase(remove(G[s[i]].begin(), G[s[i]].end(), G1[s[i]][j]), G[s[i]].end());
            }
        }

        t = iter("",G,num,allletter.size());
        }
    }
    return t;
}

int main(){
    cout << foo("abccde") << "\n" << endl;
    cout << bar("abccde") << "\n" << endl;
    return 0;
}

