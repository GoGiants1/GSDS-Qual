// Breadth First Search for graph
// Complexity = O(V+E)
// Algorithm
// 1. 시작은 다 white, distance = infinity, parent = none
// 2. root색은 gray, d = 0, parent = none으로 시작
// 3. queue = 0
// 4. enqueue(root)
// 5. u = dequeue()
// 6. u의 neighbor 가 하양이면 회색으로 바꿔주고 d=d+1, parent = u, enqueue해줌
// 7. u를 black 으로 바꿔줌
// 8. 5-7반복 queue에 아무것도 없을 때 까지

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

void addEdge(vector <int> g[], int u, int v){
    g[u].push_back(v);
    g[v].push_back(u);
}

void BFSSingleSource(vector <int> g[], vector <int> &d, vector <string> &color, vector <int> &p, int s){
    queue <int> q;
    q.push(s);

    d[s] = 0;
    color[s] = "black";

    while (!q.empty()){
        int u = q.front();
        q.pop();

        cout << u << " ";

        for (auto i = g[u].begin(); i != g[u].end(); i++){
            if (color[*i] == "white"){
                color[*i] = "gray";
                p[*i] = u;
                d[*i] = d[u] + 1;
                q.push(*i);
            }
        }
        color[u] = "black";
    }
}

void BFSFull (vector <int> g[], vector <int> &d, vector <string> &color, vector <int> &p,int n){
    for (int i = 0; i < n; i++){
        if (color[i]=="white"){
            BFSSingleSource(g,d,color,p,i);
        }
    }
}

int main(){
    int n = 9;
    vector <int> g[n];
    vector <string> color(n,"white");
    vector <int> d(n,-1);
    vector <int> p(n,-1);
    addEdge(g,0,1);
    addEdge(g,0,3);
    addEdge(g,0,5);
    addEdge(g,1,4);
    addEdge(g,1,2);
    addEdge(g,2,5);
    addEdge(g,3,4);
    addEdge(g,3,6);
    addEdge(g,4,7);
    addEdge(g,5,6);
    addEdge(g,6,7);
    addEdge(g,6,8);
    addEdge(g,7,8);

    BFSFull (g,d,color,p,n);

    return 0;
}