#include<bits/stdc++.h>
using namespace std;
vector<list<int>> graph;
int vertices; // no of vertices
void add_edge(int a ,int b){
    graph[a].push_back(b);
}
void topoBFS() {
    vector<int> indegree(vertices, 0);
    for (int i = 0; i < vertices; i++) {    // compute indegree of all nodes
        for (auto nbr : graph[i]) {
            indegree[nbr]++;
        }
    }
    queue<int> q;
    for (int i = 0; i < vertices; i++) {    // push nodes with 0 indegree
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int node = q.front(); 
        q.pop();
        cout << node << " ";
        // reduce indegree of all neighbors
        for (auto nbr : graph[node]) {
            indegree[nbr]--;
            if (indegree[nbr] == 0) {
                q.push(nbr);
            }
        }
    }
}

int main(){
    cout << "Enter number of vertices: ";
    cin >> vertices;
    graph.resize(vertices, list<int>()); // Resize the graph to hold the number of vertices
    int edges;
    cout << "Enter number of edges: ";
    cin >> edges;
    cout << "Enter edges (u v) format:\n";
    for(int i = 0; i < edges; i++) { // by default bi_directional true hai
        int u, v;
        cin >> u >> v; 
        add_edge(u, v);  // ek particular edge kis kis ke bich mai hai bho daalna hai jese 2-5 =>u=2,v=5
    }
    topoBFS(); // if cycle exist then less than n nodes will be printed 
    return 0;
}