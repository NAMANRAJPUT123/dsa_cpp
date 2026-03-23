#include <iostream>
#include <vector>
#include <string>
using namespace std;
int find(vector<int>& parent, int x) {
    if (parent[x] == x) return x;
    // Path compression optimization
    return parent[x] = find(parent, parent[x]);
}
void Union(vector<int>& parent, vector<int>& size, vector<int>& min_size,vector<int>& max_size, vector<int>& rank, int a, int b) {
    a = find(parent, a);
    b = find(parent, b);
    if (a != b) { // mtlb dono alag alag set mai hai
        // Union by rank optimization
        if (rank[a] < rank[b]) {
            parent[a] = b;
            size[b] += size[a];
            min_size[b] = min(min_size[b], min_size[a]);
            max_size[b] = max(max_size[b], max_size[a]);
        } 
        else if (rank[a] > rank[b]) {
            parent[b] = a;
            size[a] += size[b];
            min_size[a] = min(min_size[a], min_size[b]);
            max_size[a] = max(max_size[a], max_size[b]);
        } 
        else {
            parent[b] = a;
            rank[a]++;
            size[a] += size[b];
            min_size[a] = min(min_size[a], min_size[b]);
            max_size[a] = max(max_size[a], max_size[b]);
        }
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> parent(n + 1);
    vector<int> rank(n + 1, 0);
    vector<int> size(n + 1, 1);
    vector<int> min_size(n + 1);
    vector<int> max_size(n + 1);
    for (int i = 1; i <= n; i++) {
        parent[i] = min_size[i] = max_size[i] = i;
    }
    while (m--) {
        string str;
        cin >> str;
        if (str == "union") {
            int a, b;
            cin >> a >> b;
            Union(parent, size, min_size, max_size, rank, a, b);
        } else { // find query
            int a;
            cin >> a;
            int root = find(parent, a);
            cout << min_size[root] << " " << max_size[root] << " " << size[root] << endl;
        }
    }
    return 0;
}
// this is a Disjoint Set Union (DSU) (or Union-Find) implementation that tracks not just connectivity, but also:
// size of each connected component,
// minimum element in the component, and
// maximum element in the component.