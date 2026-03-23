#include <iostream>
#include <vector>
#include <queue>
using namespace std;
bool bfs(int src, vector<vector<int>>& graph, vector<bool>& visited) {
    queue<pair<int,int>> q;  
    // pair -> (current_node, parent)
    visited[src] = true;
    q.push({src, -1});
    while (!q.empty()) {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();
        for (int nbr : graph[node]) {
            if (!visited[nbr]) {
                visited[nbr] = true;
                q.push({nbr, node});
            }
            else if (nbr != parent) { // agar visited hai aur parent bhi nhi hai toh cycle hai uss node pe pehele aa chuke hai
//                                       phirse agye
                return true;
            }
        }
    }
    return false;
}
bool containsCycle(int n, vector<vector<int>>& graph) {  // graph disconnected hai toh har component check karna padega uske liye 
    vector<bool> visited(n + 1, false);
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {   
            if (bfs(i, graph, visited)) //uss node se bfs call karenge pura component cover karne ke liye,durse component me jane ke liye loop se
                return true;
        }
    }
    return false;
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1); // 1 based indexing mtlb nodes 1 to n
    cout << "Enter edges:\n";
    while (m--) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u); // undirected
    }
    if (containsCycle(n, graph))
        cout << "Cycle detected\n";
    else
        cout << "No cycle\n";

    return 0;
}
