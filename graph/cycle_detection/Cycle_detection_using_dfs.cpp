#include <iostream>
#include <vector>
using namespace std;
bool dfs(int node, int parent, vector<vector<int>>& graph, vector<bool>& visited) {
    visited[node] = true;
    for (int nbr : graph[node]) {
        if (!visited[nbr]) {
            if (dfs(nbr, node, graph, visited))
                return true;   // ye wala true upar wale calls ko bhi true return kar dega
        }
        else if (nbr != parent) {
            // visited neighbor and it is not the parent -> cycle
            return true; // ye wala true last dfs call ko true return kar dega
        }
    }
    return false; // jaha cycle nhi mila
}
bool containsCycle(int n, vector<vector<int>>& graph) { 
    vector<bool> visited(n+1, false);
    for (int i = 1; i <= n; i++) {     // graph disconnected hai toh har component check karna padega uske liye
        if (!visited[i]) {
            if (dfs(i, -1, graph, visited))
                return true;
        }
    }
    return false;
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n+1); // 1 based indexing mtlb nodes 1 to n
    cout << "Enter edges:\n";
    while (m--) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);  // undirected graph
    }
    if (containsCycle(n, graph))
        cout << "Cycle detected\n";
    else
        cout << "No cycle\n";
    return 0;
}

