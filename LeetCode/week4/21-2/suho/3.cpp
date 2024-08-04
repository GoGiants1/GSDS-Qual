#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct GNode{
    char id = id;
    GNode(char id) : id(id) {}
};
    
    
int lexcomp(vector<char> l1, vector<char> l2){
    int res = 2;
    if(l1 != l2){
        int i = 0;
        while(i < min(l1.size(),l2.size())){
            if(l1[i] < l2[i]){
                res = 0;
                break;
            }
            else if(l1[i] > l2[i]){
                res = 1;
                break;
            }
            else i++;
        }

        if(res == 2){
            if(l1.size() > l2.size()) res = 1;
            else res = 0;
        }
    }
    
    return res;
}


vector<char> dfs(map<GNode*,vector<GNode*>> G, vector<GNode*> path, GNode *v){
    if(path.back() == v){
        vector<char> res(0);
        for(int i = 0; i < path.size(); i++){
            res.push_back(path[i]->id);
        }
        return res;
    }
    else{
        vector<char> res(0);
        for(int i = 0; i < G[path.back()].size(); i++){
            if(find(path.begin(), path.end(), G[path.back()][i]) == path.end()){
                vector<GNode*> newpath = path;
                newpath.push_back(G[path.back()][i]);
                vector<char> tmp = dfs(G, newpath, v);
                if(res.size() == 0 or (tmp.size() != 0 && lexcomp(res, tmp) == 1)) res = tmp;
            }
        }
        return res;
    }
}

vector<char> LexSmallest(map<GNode*,vector<GNode*>> G, GNode *u, GNode *v){
    vector<char> path = dfs(G, vector<GNode*>{u}, v);
    return path;
}

int main(){
    GNode r = GNode('r'), s = GNode('s'), t = GNode('t'), u = GNode('u');
    GNode v = GNode('v'), w = GNode('w'), x = GNode('x'), y = GNode('y');

    map<GNode*,vector<GNode*>> G;
    G[&r] = vector<GNode*>{&w, &v};
    G[&w] = vector<GNode*>{&s, &r, &t};
    G[&t] = vector<GNode*>{&s, &x, &w};
    G[&u] = vector<GNode*>{&y};
    G[&v] = vector<GNode*>{&r};
    G[&s] = vector<GNode*>{&w, &t, &x};
    G[&x] = vector<GNode*>{&s, &t};
    G[&y] = vector<GNode*>{&u};

    vector<char> res1 = LexSmallest(G, &t, &v);
    vector<char> res2 = LexSmallest(G, &u, &u);
    vector<char> res3 = LexSmallest(G, &w, &y);

    for(int i = 0; i < res1.size(); i++){
        printf("%c ", res1[i]);
    }
    printf("\n");

    for(int i = 0; i < res2.size(); i++){
        printf("%c ", res2[i]);
    }
    printf("\n");

    for(int i = 0; i < res3.size(); i++){
        printf("%c ", res3[i]);
    }
    printf("\n");

    return 0;
}

