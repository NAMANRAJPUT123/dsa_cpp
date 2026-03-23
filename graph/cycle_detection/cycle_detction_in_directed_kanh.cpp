#include <bits/stdc++.h>
using namespace std;
bool hasCycle(int n, vector<vector<int>>& graph) {
    vector<int> indegree(n, 0);
    // Step 1: Compute indegree
    for (int u = 0; u < n; u++) {
        for (int v : graph[u]) {
            indegree[v]++;
        }
    }
    // Step 2: Push all 0-indegree nodes into queue
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0)
            q.push(i);
    }
    int count = 0; // processed nodes
    // Step 3: BFS (Kahn's Algorithm)
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        count++;
        for (int nbr : graph[node]) {
            indegree[nbr]--;
            if (indegree[nbr] == 0)
                q.push(nbr);
        }
    }
    // Step 4: If count != n, cycle exists
    return count != n; // agar topo sort possible hai to sare node process honge lekin cycle milte he topo ruk jaega 0 in degree nhi ho kisi ki badh mai
}
int main() {
    int n, e;
    cin >> n >> e;
    vector<vector<int>> graph(n);   // 0-based indexing
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);      // directed edge
    }
    if (hasCycle(n, graph))
        cout << "Cycle Exists\n";
    else
        cout << "No Cycle\n";
}
