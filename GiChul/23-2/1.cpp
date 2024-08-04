#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
    
vector<char> bfs(char start_node, map<char,vector<char>> graph){
    vector<char> queue = {start_node};
    vector<char> visited = {start_node};

    while(queue.size()!=0){
        char curr_node = queue.back();
        queue.pop_back();

        for(int i = 0; i < graph[curr_node].size(); i++){
            char next_node = graph[curr_node][i];
            if(find(visited.begin(), visited.end(), next_node) == visited.end()){
                visited.push_back(next_node);
                queue.push_back(next_node);
            }
        }
    }
    return visited;
}

void find_root(map<char,vector<char>> G){
    vector<char> key;
    for(map<char,vector<char>>::iterator it = G.begin(); it != G.end(); it++) {
        key.push_back(it->first);
    }

    vector<char> res(0);
    for(int i = 0; i < key.size(); i++){
        char start_node = key[i];
        if(bfs(start_node, G).size() == key.size()){
            res.push_back(start_node);
        }
    }

    printf("[");
    for(int i = 0; i < res.size(); i++){
        printf("%c",res[i]);
        if(i!=res.size()-1) printf(", ");
    }
    printf("]\n");
}

int main(){
    map<char,vector<char>> G;
    
    G['A'] = vector<char>{'C','D'};
    G['B'] = vector<char>{'A','F'};
    G['C'] = vector<char>{'D','B'};
    G['D'] = vector<char>{'E'};
    G['E'] = vector<char>{'F'};
    G['F'] = vector<char>{};

    find_root(G);

    return 0;
}
