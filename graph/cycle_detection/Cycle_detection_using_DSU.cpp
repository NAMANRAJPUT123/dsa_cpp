#include<iostream>
#include<vector>
using namespace std;
int find(vector<int>& parent, int x){
    if(parent[x] == x){
        return x;
    }
    // Path compression optimization
    return parent[x] = find(parent, parent[x]);
}
bool Union(vector<int>& parent, vector<int>& rank, int a, int b){
    a = find(parent, a);
    b = find(parent, b);
    if(a==b) return true;
        // Union by rank optimization
        if (rank[a] < rank[b])
            parent[a] = b;
        else if (rank[a] > rank[b])
            parent[b] = a;
        else {
            parent[b] = a;
            rank[a]++;
        }
    return false;
}
int main(){
    int n,m;
    cin>>n>>m;
    // n-> elements , m -> number of queries
    vector<int> parent(n+1); // 1 based indexing chahiye
    vector<int> rank(n+1,0);
    // Initialize parent array
    for(int i = 1; i <= n; i++){
        parent[i] = i;
    }
    cout<<"Enter Edges"<<"\n";
    while(m--){
            int a,b;
            cin>>a>>b;
            bool bo = Union(parent, rank, a, b);
            if(bo==true){
                cout<<"Cycle detected.";
                break;
            }
    }
    return 0;
}