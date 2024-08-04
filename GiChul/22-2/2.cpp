#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct GNode{
    char id;
    GNode(char id) : id(id) {}
};

void expo(map<GNode*,vector<GNode*>> G, vector<GNode*> path, GNode *t, vector<vector<char>> *pathlists){
    if(path.back() == t) {
        vector<char> plist;
        for(int i = 0; i < path.size(); i++) plist.push_back(path[i]->id);
        (*pathlists).push_back(plist);
    }
    else{
        for(int i = 0; i < G[path.back()].size(); i++){
            if(find(path.begin(), path.end(), G[path.back()][i]) == path.end()){
                vector<GNode*> newpath = path;
                newpath.push_back(G[path.back()][i]);
                expo(G, newpath, t, pathlists);
            }
        }
    }
}

vector<vector<char>> paths(map<GNode*,vector<GNode*>> G, GNode *s, GNode *t){
    vector<vector<char>> pathlists;
    expo(G, vector<GNode*>{s}, t, &pathlists);

    return pathlists;
}

int main(){
    GNode a = GNode('a'), b = GNode('b'), c = GNode('c'), d = GNode('d');
    map<GNode*,vector<GNode*>> G;
    G[&a] = vector<GNode*>{&b, &c};
    G[&b] = vector<GNode*>{&d};
    G[&c] = vector<GNode*>{};
    G[&d] = vector<GNode*>{&c};

    vector<vector<char>> res = paths(G, &a, &c);

    for(int i = 0; i < res.size(); i++){
        for(int j = 0; j < res[i].size(); j++){   
            printf("%c ",res[i][j]);
        }
        printf("\n");
    }

    return 0;
}
