#include<bits/stdc++.h>
using namespace std;
int findParent(int node, vector<int>& parent) {
    if (node == parent[node])
        return node;
    return parent[node] = findParent(parent[node], parent);
}
void unionSets(int u, int v, vector<int>& parent, vector<int>& rank) {
    u = findParent(u, parent);
    v = findParent(v, parent);
    if (u == v) return;
    if (rank[u] < rank[v]) {
        parent[u] = v;
    }
    else if (rank[v] < rank[u]) {
        parent[v] = u;
    }
    else {  // agar rank same hai to mtlb dono set ka size same hai
        parent[v] = u;
        rank[u]++;
    }
}
int kruskalMST(int n, vector<array<int, 3>>& edges) {
    // edges -> {weight, u, v}
    sort(edges.begin(), edges.end());
    vector<int> parent(n + 1), rank(n + 1, 0);
    for (int i = 1; i <= n; i++) parent[i] = i; // sabke parent khud h
    int mstWeight = 0;
    for (auto& edge : edges) { // ek ek edge dekhte jao
        int weight = edge[0];
        int u = edge[1];
        int v = edge[2];
        if (findParent(u, parent) != findParent(v, parent)) { // parent same mtlb cycle banega
            unionSets(u, v, parent, rank);
            mstWeight += weight;
        }
    }
    return mstWeight;
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<array<int, 3>> edges; // {weight, u, v}
    cout << "Enter edges (u v weight):\n";
    while (m--) {
        int u, v, weight;
        cin >> u >> v >> weight;
        edges.push_back({weight, u, v});
    }
    int mstWeight = kruskalMST(n, edges);
    cout << "Weight of MST: " << mstWeight << "\n";
    return 0;
}