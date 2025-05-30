#include<bits/stdc++.h>
using namespace std;
bool DFS(vector<vector<int>> &adj, vector<bool> &vis, int node, int parent){
    vis[node] = true;
    for(auto x : adj[node]){
        if(vis[x] == 0){
            if(DFS(adj,vis,x,node) == true) return true;
        }
        else if(x != parent){
            return true;
        }
    }
    return false;
}
bool isCycle(vector<vector<int>> adj, int n){
    vector<bool> vis(n+1,false);
    for(int i = 1; i <= n; i++){
        if(vis[i] == false){
            if(DFS(adj,vis,i,-1) == true) return true;
        }
    }
    return false;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1,vector<int>());
    for(int i = 0 ; i < m ; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if(isCycle(adj,n)) cout << "YES" << endl;
    else cout << "NO"<< endl;

}