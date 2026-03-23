#include <bits/stdc++.h>
using namespace std;
int timer = 0;
void dfs(int node, int parent,vector<vector<int>>& adj,vector<bool>& visited,vector<int>& disc,vector<int>& low,vector<bool>& isAP) {
    visited[node] = true;
    disc[node] = low[node] = timer++;
    int children = 0;
    for (int neighbor : adj[node]) {
        // Ignore parent edge
        if (neighbor == parent)
            continue;
        if (!visited[neighbor]) {
            children++;
            dfs(neighbor, node, adj,visited, disc, low, isAP);
            low[node] = min(low[node],low[neighbor]);
            // Non-root articulation condition
            if (parent != -1 &&
                low[neighbor] >= disc[node]) isAP[node] = true;
        }
        else {
            low[node] =min(low[node], disc[neighbor]);
        }
    }
    // Root articulation condition
    if (parent == -1 && children > 1)
        isAP[node] = true;
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
        adj[v].push_back(u);
    }
    vector<bool> visited(V, false);
    vector<bool> isAP(V, false);
    vector<int> disc(V), low(V);
    for (int i = 0; i < V; i++)
        if (!visited[i])
            dfs(i, -1, adj,visited, disc, low, isAP);

    cout << "\nArticulation Points:\n";
    for (int i = 0; i < V; i++)
        if (isAP[i])
            cout << i << " ";

    return 0;
}