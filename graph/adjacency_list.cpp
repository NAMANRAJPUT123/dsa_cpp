#include<iostream>
#include<vector>
#include<list>
using namespace std;
vector<list<int>> graph; // vector of lists to represent adjacency list ,vector<list<pair<int,int>>>sath mai weight bhi store karne ke liye
int vertices; // number of vertices in the graph 
void addEdge(int u, int v, bool bi_directional=true) {
    graph[u].push_back(v); // Add v to u’s list, graph mai uss idx u pe jho list hai usme v ko add kar rhe hai
    if(bi_directional) {
        graph[v].push_back(u); // Since the graph is undirected
    }
}
int main() {
    cout << "Enter number of vertices: ";
    cin >> vertices;
    graph.resize(vertices, list<int>()); // Resize the graph to hold the number of vertices
    int edges;
    cout << "Enter number of edges: ";
    cin >> edges;
    cout << "Enter edges (u v) format:\n";
    for(int i = 0; i <edges; i++) { // by default bi_directional true hai
        int u, v;
        cin >> u >> v; 
        addEdge(u, v);  // ek particular edge kis kis ke bich mai hai bho daalna hai jese 2-5 =>u=2,v=5
    }
    // for(int i = 0; i <edges; i++) {
    //     int u, v;
    //     cin >> u >> v;
    //     addEdge(u, v,false);  // direction matters 0->2, u=0,v=2
    // }
    // Display the adjacency list
    for(int i = 0; i < vertices; i++) {
        cout << i << " -> ";
        for(int neighbor : graph[i]) { // graph[i] is a list of neighbors pure pe iterate karega
            cout << neighbor << " ";
        }
        cout << endl;
    }
    return 0;
}

