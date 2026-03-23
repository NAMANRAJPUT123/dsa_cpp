#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> graph;
vector<int> visited;
stack<int> st;
int vertices;
void dfs(int node) {
    visited[node] = 1;
    for (int nbr : graph[node]) {
        if (!visited[nbr])
            dfs(nbr);
    }
    // Push after all neighbors are visited → postorder
    st.push(node);
}
void topoDFS() {
    visited.assign(vertices, 0);

    for (int i = 0; i < vertices; i++) { // for disconnected components
        if (!visited[i])
            dfs(i);
    }
    // Print stack content (topological order)
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
}
int main() {
    cout << "Enter number of vertices: ";
    cin >> vertices;
    graph.assign(vertices, vector<int>());
    int edges;
    cout << "Enter number of edges: ";
    cin >> edges;
    cout << "Enter edges (u v) :\n";
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }
    cout << "Topological Sort (DFS method): ";
    topoDFS();
    return 0;
}
