#include <bits/stdc++.h>
using namespace std;
bool dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &pathVis) {
    vis[node] = 1;
    pathVis[node] = 1;
    for (int nbr : adj[node]) {
        if (!vis[nbr]) {
            if (dfs(nbr, adj, vis, pathVis))
                return true;
        }
        else if (pathVis[nbr]) { // upper neighbour visited hai aur current path me bhi hai to cycle
            return true;
        }
    }
    pathVis[node] = 0;  // Remove from current path
    return false;
}
bool isCyclic(int V, vector<int> adj[]) {
    vector<int> vis(V, 0), pathVis(V, 0);
    for (int i = 0; i < V; i++) { // For disconnected components
        if (!vis[i]) {
            if (dfs(i, adj, vis, pathVis))
                return true;
        }
    }
    return false;
}
int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;
    vector<int> adj[V]; // vector ke andhr array
    cout << "Enter edges (u v) meaning u -> v:\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    if (isCyclic(V, adj)) {
        cout << "Cycle detected\n";
    } else {
        cout << "No cycle\n";
    }

    return 0;
}
