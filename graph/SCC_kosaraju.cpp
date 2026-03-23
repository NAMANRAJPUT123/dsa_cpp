#include <bits/stdc++.h>
using namespace std;

// Step 1: DFS to store finish order
void dfs1(int node, vector<vector<int>>& adj,
          vector<bool>& visited, stack<int>& st) {

    visited[node] = true;

    for (int neighbor : adj[node]) {
        if (!visited[neighbor])
            dfs1(neighbor, adj, visited, st);
    }

    st.push(node);
}

// Step 3: DFS on reversed graph
void dfs2(int node, vector<vector<int>>& revAdj,
          vector<bool>& visited) {

    visited[node] = true;
    cout << node << " ";

    for (int neighbor : revAdj[node]) {
        if (!visited[neighbor])
            dfs2(neighbor, revAdj, visited);
    }
}

int main() {

    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    vector<vector<int>> adj(V);

    cout << "Enter directed edges (u v):\n";

    // USER INPUT EDGES
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    stack<int> st;
    vector<bool> visited(V, false);

    // STEP 1
    for (int i = 0; i < V; i++) {
        if (!visited[i])
            dfs1(i, adj, visited, st);
    }

    // STEP 2: Reverse graph
    vector<vector<int>> revAdj(V);

    for (int i = 0; i < V; i++) {
        for (int neighbor : adj[i]) {
            revAdj[neighbor].push_back(i);
        }
    }

    fill(visited.begin(), visited.end(), false);

    // STEP 3
    cout << "\nStrongly Connected Components:\n";

    while (!st.empty()) {
        int node = st.top();
        st.pop();

        if (!visited[node]) {
            dfs2(node, revAdj, visited);
            cout << endl;
        }
    }

    return 0;
}