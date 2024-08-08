// Prim's algorithm for Minimum Spanning Tree
// Complexity = O((E+V)lgV)

// 1. random vertex를 root로 지정한다.
// 2. incomplete MST와 다른 vertex를 잇는 가장 작은 edge를 구한다.
// 3. 반복.

#include <iostream>
#include <list>
#include <queue>
#define INF 0x3f3f3f3f

using namespace std;

typedef pair<int, int> iPair;

class Graph{
    int V;
    list < pair<int,int> > *adj;

public:
    Graph(int V);
    void addEdge(int u, int v, int w);
    void PrimMST();
};

Graph::Graph(int V){
    this->V = V;
    adj = new list< iPair > [V];
}
 
void Graph::addEdge(int u, int v, int w){
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}

void Graph::PrimMST(){
    // priority_queue <자료형, Container, 비교함수> 변수명
    // 선언한 자료형 변수들을 비교함수에 따라 정렬
    priority_queue< iPair, vector <iPair> , greater<iPair> > pq;

    int src = 0; // Taking vertex 0 as source
 
    // Create a vector for keys and initialize all
    // keys as infinite (INF)
    vector<int> key(V, INF);
 
    // To store parent array which in turn store MST
    vector<int> parent(V, -1);
 
    // To keep track of vertices included in MST
    vector<bool> inMST(V, false);

    pq.push(make_pair(0, src));
    key[src] = 0;

    while (!pq.empty())
    {
        // The first vertex in pair is the minimum key
        // vertex, extract it from priority queue.
        // vertex label is stored in second of pair (it
        // has to be done this way to keep the vertices
        // sorted key (key must be first item
        // in pair)
        int u = pq.top().second;
        pq.pop();
         
          //Different key values for same vertex may exist in the priority queue.
          //The one with the least key value is always processed first.
          //Therefore, ignore the rest.
          if(inMST[u] == true){
            continue;
        }
       
        inMST[u] = true;  // Include vertex in MST
 
        // 'i' is used to get all adjacent vertices of a vertex
        list< pair<int, int> >::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            // Get vertex label and weight of current adjacent
            // of u.
            int v = (*i).first;
            int weight = (*i).second;
 
            //  If v is not in MST and weight of (u,v) is smaller
            // than current key of v
            if (inMST[v] == false && key[v] > weight)
            {
                // Updating key of v
                key[v] = weight;
                pq.push(make_pair(key[v], v));
                parent[v] = u;
            }
        }
    }
    for (int i = 1; i < V; ++i)
        printf("%d - %d\n", parent[i], i);

}

int main(){
    // create the graph given in above figure
    int V = 8;
    Graph g(V);
 
    //  making above shown graph
    g.addEdge(0, 1, 3);
    g.addEdge(0, 3, 2);
    g.addEdge(0, 5, 10);
    g.addEdge(1, 2, 5);
    g.addEdge(1, 3, 7);
    g.addEdge(1, 4, 9);
    g.addEdge(2, 7, 14);
    g.addEdge(3, 5, 6);
    g.addEdge(3, 6, 4);
    g.addEdge(4, 6, 1);
    g.addEdge(4, 7, 11);
    g.addEdge(5, 6, 12);
    g.addEdge(6, 7, 13);
 
    g.PrimMST();
 
    return 0;
}

