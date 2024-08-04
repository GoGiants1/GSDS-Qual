#include <iostream>
#include <map>
#include <deque>
using namespace std;

//g++ -std=c++11 -o 2cpp 2.cpp

struct GNode{      
    char id;
    int distance = -1;
    GNode(char id): id(id) {}
};  

vector<GNode*> bfs(map<GNode*,vector<GNode*>> G, GNode *s){
    vector<GNode*> v(0);
    deque<GNode*> q(1,s);

    while(q.size()!=0){
        GNode *n = q.front();
        q.pop_front();
        if (find(v.begin(),v.end(),n) == v.end()){
            v.push_back(n);
            for(int i = 0; i < G[n].size(); i++){ 
                q.push_back(G[n][i]);
                if(G[n][i]->distance == -1) G[n][i]->distance = n->distance+1;
            }
        }
    }
    
    return v;
}

vector<vector<char>> level_partition(const map<GNode*,vector<GNode*>> G, GNode *s){
    s->distance = 0;
    vector<GNode*> v = bfs(G, s);
    vector<vector<char>> res(0);
    for(int i = 0; i < v.back()->distance+1; i++) res.push_back(vector<char>{});
    for(int i = 0; i < v.size(); i++) res[v[i]->distance].push_back(v[i]->id);
    
    return res;
}

int main(){
    GNode r = GNode('r'), s = GNode('s'), t = GNode('t'), u = GNode('u'), v = GNode('v');
    GNode w = GNode('w'), x = GNode('x'), y = GNode('y');
        
    map<GNode*,vector<GNode*>> G;
        
    G[&r] = vector<GNode*>{&s, &v};
    G[&s] = vector<GNode*>{&r, &w};
    G[&t] = vector<GNode*>{&w, &x, &u};
    G[&u] = vector<GNode*>{&t, &x, &y};
    G[&v] = vector<GNode*>{&r};
    G[&w] = vector<GNode*>{&s, &t, &x};
    G[&x] = vector<GNode*>{&w, &t, &u, &y};
    G[&y] = vector<GNode*>{&x, &u};

    vector<vector<char>> res = level_partition(G, &s);
    printf("[");
    for(int i = 0; i < res.size(); i++){
        printf("[");
        for(int j = 0; j < res[i].size(); j++){
            printf("'%c'",res[i][j]);
            if(j!=res[i].size()-1) printf(", ");
        }
        printf("]");
        if(i!=res.size()-1) printf(", ");
    }
    printf("]");


    return 0;
}