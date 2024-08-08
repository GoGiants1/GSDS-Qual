// Depth First Search for Strongly Connected Components
// Complexity = O(V+E)
// Algorithm
// 1. Initialization: u.color = white, u.p = NIL
// 2. time = time +1, u.d = time, u.color = gray 
// 3. for neighbors, u.p = u, DFSVisit
// 4. time = time +1, u.f = time, u.color = black

// SCC
// 1. DFS(G)
// 2. DFS(GT) but order = decreasing order of finishing time of 1.

#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

stack <int> order;

void addEdge(vector <int> g[], vector <int> gt[], int u, int v){
    g[u].push_back(v);
    gt[v].push_back(u);
}

void DFSVisit(vector <int> g[], int i, vector <string> &color, vector <int> &p, vector <int> &d, vector <int> &f, int n, int &time){
    time = time+1;
    d[i] = time;
    color[i] = "gray";
    for (auto j = g[i].begin(); j != g[i].end(); j++){
        if (color[*j] == "white"){
            p[*j] = i;
            DFSVisit(g,*j,color,p,d,f,n,time);
        }
    }
    time = time+1;
    f[i] = time;
    color[i] = "black";
    cout << i << " ";
    order.push(i);
}

void DFS(vector <int> g[], int i, vector <string> &color, vector <int> &p, vector <int> &d, vector <int> &f, int n, int &time){
    for (int i = 0; i < n; i++){
        if (color[i] == "white"){
            DFSVisit(g,i,color,p,d,f,n,time);
        }
    }
}

int main(){
    int n = 8;
    vector <string> color(n,"white");
    vector <string> colort(n,"white");
    vector <int> p(n,-1);
    vector <int> pt(n,-1);
    vector <int> d(n,-1);
    vector <int> dt(n,-1);
    vector <int> f(n,-1);
    vector <int> ft(n,-1);
    vector <int> g[n];
    vector <int> gt[n];

    int time = 0;
    int timet = 0;

    addEdge(g,gt,0,1);
    addEdge(g,gt,1,2);
    addEdge(g,gt,1,4);
    addEdge(g,gt,1,5);
    addEdge(g,gt,2,3);
    addEdge(g,gt,2,6);
    addEdge(g,gt,3,2);
    addEdge(g,gt,3,7);
    addEdge(g,gt,4,0);
    addEdge(g,gt,4,5);
    addEdge(g,gt,5,6);
    addEdge(g,gt,6,5);
    addEdge(g,gt,6,7);
    addEdge(g,gt,7,7);

    DFS(g,0,color,p,d,f,n,time);
    cout<< endl;
    
    while (order.empty() == false){
        int v = order.top();
        order.pop();

        if (colort[v]=="white"){
            DFSVisit(gt,v,colort,pt,dt,ft,n,timet);
            cout << endl;
        }
    }
}