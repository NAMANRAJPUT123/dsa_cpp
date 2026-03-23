// #include <iostream>
// #include <vector>
// #include <queue>
// using namespace std;
// void bfs(int start, vector<vector<int>>& graph, int n) {
//     vector<bool> visited(n, false);
//     queue<int> q;
//     visited[start] = true;
//     q.push(start);
//     cout << "BFS Traversal: ";
//     while (!q.empty()) {
//         int node = q.front();
//         q.pop();
//         cout << node << " ";
//         for (int neighbor : graph[node]) {
//             if (!visited[neighbor]) {
//                 visited[neighbor] = true;
//                 q.push(neighbor);
//             }
//         }
//     }
//     cout << endl;
// }
// int main() {
//     int n = 7; // Number of vertices
//     vector<vector<int>> graph(n);
//     // Example edges
//     graph[0] = {1, 2};
//     graph[2] = {0,5,3};
//     graph[3] = {2,6,4};
//     graph[4] = {6,3};
//     graph[5] = {1,2};
//     graph[6] = {4,3};
//     graph[1] = {0, 5};
//     bfs(0, graph, n);
// }


//BFS_ANY_PATH

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm> 
using namespace std;
bool bfsPath(vector<vector<int>>& adj, int src, int dest, vector<int>& path) {
    int n = adj.size();
    vector<bool> visited(n, false);
    vector<int> parent(n, -1); 
    queue<int> q;
    q.push(src);
    visited[src] = true;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        if (node == dest) break; 
        for (int neigh : adj[node]) {
            if (!visited[neigh]) {
                visited[neigh] = true;
                parent[neigh] = node;
                q.push(neigh);
            }
        }
    }
    if (!visited[dest]) return false; 
    int curr = dest;
    while (curr != -1) {
        path.push_back(curr);
        curr = parent[curr];
    }
    reverse(path.begin(), path.end());
    return true;
}
int main() {
    int V, E;
    cout << "Enter vertices and edges: ";
    cin >> V >> E;
    vector<vector<int>> adj(V);
    cout << "Enter edges (u v):\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); 
    }
    int src, dest;
    cout << "Enter source and destination: ";
    cin >> src >> dest;
    vector<int> path;
    if (bfsPath(adj, src, dest, path)) {
        cout << "Path found: ";
        for (int node : path)
            cout << node << " ";
        cout << "\n";
    } else {
        cout << "No path exists.\n";
    }
    return 0;
}











