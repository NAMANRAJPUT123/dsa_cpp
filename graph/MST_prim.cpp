#include<bits/stdc++.h>
using namespace std;
vector<list<pair<int,int>>> gr;
void add_edge(int u,int v,int w){
    gr[u].push_back({v,w});
    gr[v].push_back({u,w});
}
long long primsMST(int src){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,src}); // {weight,node}
    vector<bool> inMST(gr.size(),false);
    long long mstWeight = 0;
    while(!pq.empty()){
        auto p = pq.top();
        pq.pop();
        int weight = p.first;
        int node = p.second;
        if(inMST[node]) continue;
        inMST[node] = true;
        mstWeight += weight;
        for(auto &nbrPair : gr[node]){
            int nbr = nbrPair.first;
            int edgeWeight = nbrPair.second;
            if(!inMST[nbr]){
                pq.push({edgeWeight, nbr});
            }
        }
    }
    return mstWeight;
}
int main(){
    int n,m;
    cin>>n>>m;
    gr.resize(n + 1, list<pair<int,int>>());
    cout<<"Enter edges (u v w):\n";
    while(m--){
        int u,v,w;
        cin>>u>>v>>w;
        add_edge(u, v, w);
    }
    int src;
    cout<<"Enter source vertex:";
    cin>>src;
    cout << primsMST(src);   // <-- FIXED: actually print the answer
    return 0;
}
