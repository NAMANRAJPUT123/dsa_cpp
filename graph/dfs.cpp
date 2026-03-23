#include <iostream>
#include <vector>
using namespace std;
void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited) {
    visited[node] = true;
    cout << node << " ";
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, graph, visited);
        }
    }
}
int main() {
    int n = 5;
    vector<vector<int>> graph(n);
    graph[0] = {1, 2};
    graph[1] = {0, 3};
    graph[2] = {0, 4};
    graph[3] = {1};
    graph[4] = {2};
    vector<bool> visited(n, false);
    cout << "DFS Traversal: ";
    dfs(0, graph, visited);
}

// PATH_EXIST
// #include <iostream>
// #include <vector>
// using namespace std;
// bool dfsPath(int node, int dest, vector<vector<int>>& graph, vector<bool>& visited, vector<int>& path) {
//     visited[node] = true;
//     path.push_back(node);
//     if (node == dest)
//         return true; // Found the destination
//     for (int neighbor : graph[node]) {
//         if (!visited[neighbor]) {
//             if (dfsPath(neighbor, dest, graph, visited, path))
//                 return true; // If path found through this neighbor
//         }
//     }
//     // Backtrack
//     path.pop_back();
//     return false;
// }
// int main() {
//     int n = 7; // number of vertices
//     vector<vector<int>> graph(n);
//     // Example edges (undirected graph)
//     graph[0] = {1, 2};
//     graph[1] = {0, 5};
//     graph[2] = {0,5,3};
//     graph[3] = {2,6,4};
//     graph[4] = {6,3};
//     graph[5] = {1,2};
//     graph[6] = {4,3};
//     int src = 0, dest = 6;
//     vector<bool> visited(n, false);
//     vector<int> path;
//     if (dfsPath(src, dest, graph, visited, path)) {
//         cout << "Path exists: ";
//         for (int node : path)
//             cout << node << " ";
//         cout << endl;
//     } else {
//         cout << "No path exists between " << src << " and " << dest << endl;
//     }
//     return 0;
// }


// ALL_PATHS
// #include <iostream>
// #include <vector>
// using namespace std;
// void dfsAllPaths(int node, int dest, vector<vector<int>>& graph, vector<bool>& visited, vector<int>& path) {
//     visited[node] = true;
//     path.push_back(node);
//     if (node == dest) {
//         // Print the path
//         for (int v : path)
//             cout << v << " ";
//         cout << endl;
//     } else {
//         // Explore all neighbors
//         for (int neighbor : graph[node]) {
//             if (!visited[neighbor])
//                 dfsAllPaths(neighbor, dest, graph, visited, path);
//         }
//     }
//     // Backtrack
//     path.pop_back();
//     visited[node] = false;
// }
// int main() {
//     int n = 7; // Number of vertices
//     vector<vector<int>> graph(n);
//     // Example edges (undirected)
//     graph[0] = {1, 2};
//     graph[2] = {0,5,3};
//     graph[3] = {2,6,4};
//     graph[4] = {6,3};
//     graph[5] = {1,2};
//     graph[6] = {4,3};
//     graph[1] = {0, 5};
//     int src = 0, dest = 6;
//     vector<bool> visited(n, false);
//     vector<int> path;
//     cout << "All paths from " << src << " to " << dest << ":\n";
//     dfsAllPaths(src, dest, graph, visited, path);
//     return 0;
// }

