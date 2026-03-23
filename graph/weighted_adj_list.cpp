#include<iostream>
#include<vector>
#include<list>
using namespace std;
vector<list<pair<int,int>>> graph; // vector of lists to represent adjacency list ,vector<list<pair<int,int>>>sath mai weight bhi store karne ke liye
int vertices; // number of vertices in the graph 
void addEdge(int u, int v, int weight, bool bi_directional=true) {
    graph[u].push_back({v, weight}); // Add v to u’s list, graph mai uss idx u pe jho list hai usme v ko add kar rhe hai
    if(bi_directional) {
        graph[v].push_back({u, weight}); // Since the graph is undirected
    }
}
int main() {
    cout << "Enter number of vertices: ";
    cin >> vertices;
    graph.resize(vertices, list<pair<int,int>>()); // Resize the graph to hold the number of vertices
    int edges;
    cout << "Enter number of edges: ";
    cin >> edges;
    cout << "Enter edges (u v weight) format:\n";
    for(int i = 0; i < edges; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        addEdge(u, v, weight);  // direction matters 0->2, u=0,v=2, weight=weight
    }
    // for(int i = 0; i < edges; i++) {
    //     int u, v, weight;
    //     cin >> u >> v >> weight;
    //     addEdge(u, v, weight, false);  // direction matters 0->2, u=0,v=2
    // }
    // Display the adjacency list
    for(int i = 0; i < vertices; i++) {
        cout << i << " -> ";
        for(const auto& neighbor : graph[i]) { // graph[i] is a list of neighbors pure pe iterate karega
            cout << "(" << neighbor.first << ", " << neighbor.second << ") ";
        }
        cout << endl;
    }
    return 0;
}