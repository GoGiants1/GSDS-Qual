#include <iostream>
#include <string>
#include <vector>
using namespace std;

void perm(string incomp, string left, vector<string> *res){
    if(left == ""){
        if(find((*res).begin(),(*res).end(),incomp) == (*res).end()) (*res).push_back(incomp);
    }

    else{
        for(int i = 0; i < left.length(); i++){
            string incomp2 = incomp + left.substr(i,1);
            string left2 = left;
            left2.erase(i,1);
            perm(incomp2,left2,res);
        }
    }
}

vector<string> str_perm(string s){
    vector<string> res(0);
    string left = s;
    perm("",left,&res);

    return res;
}

int main(){
    string s1 = "abc";
    string s2 = "abb";

    vector<string> res1 = str_perm(s1);
    vector<string> res2 = str_perm(s2);

    for(int i = 0; i < res1.size(); i++){
        cout << res1[i] << " ";
    }
    cout << endl;

    for(int i = 0; i < res2.size(); i++){
        cout << res2[i] << " ";
    }
    cout << endl;

    return 0;
}

