#include <bits/stdc++.h>
using namespace std;
vector<int> dijkstraShortestPath(int n, vector<vector<pair<int,int>>>& adj, int src, int dest) {
    vector<int> dist(n, INT_MAX);
    vector<int> parent(n, -1);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    dist[src] = 0;
    pq.push({0, src});
    while (!pq.empty()) {
        pair<int,int> p = pq.top(); // {distance, node}
        pq.pop();
        int d = p.first;
        int u = p.second;
        if (u == dest) break;
        if (d != dist[u]) continue;
        for (auto &edge : adj[u]) {  // edge -> {v, weight}
            int v = edge.first;
            int w = edge.second;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
    if (dist[dest] == INT_MAX) return {};
    vector<int> path;
    for (int cur = dest; cur != -1; cur = parent[cur]) path.push_back(cur);
    reverse(path.begin(), path.end());
    return path;
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> adj(n);
    cout<<"Enter edges (u v w):\n";
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    int src, dest;
    cout<<"Enter source and destination nodes:\n";
    cin >> src >> dest;
    vector<int> path = dijkstraShortestPath(n, adj, src, dest);
    if (path.empty()) {
        cout << "No path found\n";
    } else {
        cout << "Shortest Path: ";
        for (auto x : path) cout << x << " ";
        cout << "\n";
    }
}
