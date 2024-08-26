#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <climits>
 
using namespace std;
 
const int INF = INT_MAX;
 
void bellmanFord(const unordered_map<char, unordered_map<char, int>>& graph, const char& source, unordered_map<char, int>& distances) {
    distances[source] = 0;
 
    for (int i = 0; i < graph.size() - 1; ++i) {
        for (const auto& nodePair : graph) {
            char node = nodePair.first;
            for (const auto& neighborPair : graph.at(node)) {
                char neighbor = neighborPair.first;
                int weight = neighborPair.second;
                if (distances[node] != INF && distances[node] + weight < distances[neighbor]) {
                    distances[neighbor] = distances[node] + weight;
                }
            }
        }
    }
}
 
void dijkstra(const unordered_map<char, unordered_map<char, int>>& graph, const char& start, unordered_map<char, int>& distances) {
    priority_queue<pair<int, char>, vector<pair<int, char>>, greater<pair<int, char>>> pq;
    pq.push(make_pair(0, start));
    distances[start] = 0;
 
    while (!pq.empty()) {
        char current = pq.top().second;
        int currentDist = pq.top().first;
        pq.pop();
 
        if (currentDist > distances[current]) continue;
 
        for (const auto& neighborPair : graph.at(current)) {
            char neighbor = neighborPair.first;
            int weight = neighborPair.second;
            if (currentDist + weight < distances[neighbor]) {
                distances[neighbor] = currentDist + weight;
                pq.push(make_pair(distances[neighbor], neighbor));
            }
        }
    }
}
 
unordered_map<char, unordered_map<char, int>> modifyGraph(const unordered_map<char, unordered_map<char, int>>& originalGraph) {
    unordered_map<char, unordered_map<char, int>> modifiedGraph = originalGraph;
 
    // Add a temporary node and edges with weight 0 to all other nodes
    char tempNode = 'T';
    modifiedGraph[tempNode] = {};
    for (const auto& nodePair : originalGraph) {
        modifiedGraph[tempNode][nodePair.first] = 0;
    }
 
    return modifiedGraph;
}
 
unordered_map<char, unordered_map<char, int>> johnsonsAlgorithm(const unordered_map<char, unordered_map<char, int>>& graph) {
    unordered_map<char, int> distances;
    unordered_map<char, unordered_map<char, int>> modifiedGraph = modifyGraph(graph);
    bellmanFord(modifiedGraph, 'T', distances);
    modifiedGraph.erase('T');
 
    unordered_map<char, unordered_map<char, int>> adjustedGraph;
    for (const auto& nodePair : modifiedGraph) {
        char node = nodePair.first;
        adjustedGraph[node] = {};
        for (const auto& neighborPair : modifiedGraph.at(node)) {
            char neighbor = neighborPair.first;
            int weight = neighborPair.second;
            adjustedGraph[node][neighbor] = weight + distances[node] - distances[neighbor];
        }
    }
 
    unordered_map<char, unordered_map<char, int>> allPairsShortestPaths;
    for (const auto& nodePair : adjustedGraph) {
        char node = nodePair.first;
        unordered_map<char, int> shortestDistances;
        dijkstra(adjustedGraph, node, shortestDistances);
        allPairsShortestPaths[node] = shortestDistances;
    }
 
    for (auto& nodePair : allPairsShortestPaths) {
        char node = nodePair.first;
        for (auto& neighborPair : nodePair.second) {
            char neighbor = neighborPair.first;
            neighborPair.second += distances[neighbor] - distances[node];
        }
    }
 
    return allPairsShortestPaths;
}
 
int main() {
    unordered_map<char, unordered_map<char, int>> graph = {
        {'A', {{'B', -2}, {'C', 4}}},
        {'B', {{'C', 1}, {'D', 7}}},
        {'C', {{'E', -3}}},
        {'D', {{'B', 3}}},
        {'E', {{'D', -2}}}
    };
 
    unordered_map<char, unordered_map<char, int>> shortestPaths = johnsonsAlgorithm(graph);
 
    for (const auto& nodePair : shortestPaths) {
        char node = nodePair.first;
        cout << "Shortest paths from node " << node << ":\\n";
        for (const auto& neighborPair : nodePair.second) {
            char neighbor = neighborPair.first;
            int distance = neighborPair.second;
            cout << "To node " << neighbor << ": " << distance << endl;
        }
        cout << endl;
    }
 
    return 0;
}