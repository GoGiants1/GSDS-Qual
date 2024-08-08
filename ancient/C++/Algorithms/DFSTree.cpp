// Depth First Search for graph
// Complexity = O(V+E)
// Algorithm
// 1. Initialization: u.color = white, u.p = NIL
// 2. time = time +1, u.d = time, u.color = gray 
// 3. for neighbors, u.p = u, DFSVisit
// 4. time = time +1, u.f = time, u.color = black

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void addEdge(vector <int> g[], int u, int v){
    g[u].push_back(v);
}

void DFSVisit(vector <int> g[], int i, vector <string> &color, vector <int> &p, vector <int> &d, vector <int> &f, int n, int &time){
    time = time+1;
    d[i] = time;
    color[i] = "gray";
    cout << i << " ";
    for (auto j = g[i].begin(); j != g[i].end(); j++){
        if (color[*j] == "white"){
            p[*j] = i;
            DFSVisit(g,*j,color,p,d,f,n,time);
        }
    }
    time = time+1;
    f[i] = time;
    color[i] = "black";
    cout<< i << " ";
}

void DFS(vector <int> g[], int i, vector <string> &color, vector <int> &p, vector <int> &d, vector <int> &f, int n, int &time){
    for (int i = 0; i < n; i++){
        if (color[i] == "white"){
            DFSVisit(g,i,color,p,d,f,n,time);
        }
    }
}

int main(){
    int n = 6;
    vector <string> color(n,"white");
    vector <int> p(n,-1);
    vector <int> d(n,-1);
    vector <int> f(n,-1);
    vector <int> g[n];

    int time = 0;

    addEdge(g,0,1);
    addEdge(g,0,3);
    addEdge(g,1,4);
    addEdge(g,2,4);
    addEdge(g,2,5);
    addEdge(g,3,1);
    addEdge(g,4,3);
    addEdge(g,5,5);

    DFS(g,0,color,p,d,f,n,time);
}