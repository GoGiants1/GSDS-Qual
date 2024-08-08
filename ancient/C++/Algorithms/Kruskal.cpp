// Kruskal Algorithm for Minimum Spanning Tree
// Complexity = O(ElgV)

// 1. 현재 MST에 있는 노드들과 연결된 edge들 중에서 가장 작은 것을 고름
// 2. 그 엣지가 사이클을 만들면 추가안함.

#include <iostream>

using namespace std;
 
// DSU data structure
// path compression + rank by union
class DSU {
    int* parent;
    int* rank;
 
public:
    DSU(int n)
    {
        parent = new int[n];
        rank = new int[n];
 
        for (int i = 0; i < n; i++) {
            parent[i] = -1;
            rank[i] = 1;
        }
    }
 
    // Find function
    int find(int i)
    {
        if (parent[i] == -1)
            return i;
 
        return parent[i] = find(parent[i]);
    }
 
    // Union function
    void unite(int x, int y)
    {
        int s1 = find(x);
        int s2 = find(y);
 
        if (s1 != s2) {
            if (rank[s1] < rank[s2]) {
                parent[s1] = s2;
            }
            else if (rank[s1] > rank[s2]) {
                parent[s2] = s1;
            }
            else {
                parent[s2] = s1;
                rank[s1] += 1;
            }
        }
    }
};
 
class Graph {
    vector<vector<int> > edgelist;
    int V;
 
public:
    Graph(int V) { this->V = V; }
 
    // Function to add edge in a graph
    void addEdge(int x, int y, int w)
    {
        edgelist.push_back({ w, x, y });
    }
 
    void kruskals_mst()
    {
        // Sort all edges
        sort(edgelist.begin(), edgelist.end());
 
        // Initialize the DSU
        DSU s(V);
        int ans = 0;
        cout << "Following are the edges in the "
                "constructed MST"
             << endl;
        for (auto edge : edgelist) {
            int w = edge[0];
            int x = edge[1];
            int y = edge[2];
 
            // Take this edge in MST if it does
            // not forms a cycle
            if (s.find(x) != s.find(y)) {
                s.unite(x, y);
                ans += w;
                cout << x << " -- " << y << " == " << w
                     << endl;
            }
        }
        cout << "Minimum Cost Spanning Tree: " << ans;
    }
};
 
// Driver code
int main()
{
    Graph g(8);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 7, 4);
    g.addEdge(1, 6, 5);
    g.addEdge(2, 3, 6);
    g.addEdge(2, 7, 11);
    g.addEdge(3, 4, 1);
    g.addEdge(3, 7, 7);
    g.addEdge(3, 5, 8);
    g.addEdge(4, 5, 9);
    g.addEdge(4, 7, 2);
    g.addEdge(6, 7, 7);
 
    // Function call
    g.kruskals_mst();
 
    return 0;
}