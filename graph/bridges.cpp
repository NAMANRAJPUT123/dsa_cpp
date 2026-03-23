#include <bits/stdc++.h>
using namespace std;
int timer;
void dfs(int node, int parent,vector<vector<int>>& adj,vector<int>& disc,vector<int>& low,vector<bool>& visited) {
    visited[node] = true;
    disc[node] = low[node] = timer++;
    for (int neighbor : adj[node]) {
        if (neighbor == parent)
            continue;
        if (!visited[neighbor]) {
            dfs(neighbor, node, adj, disc, low, visited);
            low[node] = min(low[node], low[neighbor]);
            // Bridge condition
            if (low[neighbor] > disc[node]) {
                cout << "Bridge: "
                     << node << " - "
                     << neighbor << endl;
            }
        }
        else {
            low[node] = min(low[node], disc[neighbor]);
        }
    }
}
int main() {
    int V, E;
    cout << "Enter vertices: ";
    cin >> V;
    cout << "Enter edges: ";
    cin >> E;
    vector<vector<int>> adj(V);
    cout << "Enter undirected edges (u v):\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);   // undirected
    }
    vector<int> disc(V, -1), low(V, -1);
    vector<bool> visited(V, false);
    timer = 0;
    for (int i = 0; i < V; i++)
        if (!visited[i])
            dfs(i, -1, adj, disc, low, visited);

    return 0;
}