#include<bits/stdc++.h>
using namespace std;

bool DFS(vector<vector<int>> &adj, vector<int> &vis, vector<int> &pathvis, int node){
    vis[node] = 1;
    pathvis[node] = 1;
    for(auto x : adj[node]){
        if(!vis[x]){
            if(DFS(adj,vis,pathvis,x) == false) return false;
        }
        else{
            // if the node has been previously visited
            // but it has to be visited on the same path to form a cycle
            if(pathvis[x]) return false;
        }
    }
    pathvis[node] = 0; // erase path visited
    return true;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1,vector<int>());
    for(int i = 0 ; i < m ; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v); // directed graph
    }

    vector<int> vis(n, 0);
    vector<int> pathvis(n, 0);

    for(int i = 0; i < n; i++){
        if(!vis[i]){
            if(DFS(adj,vis,pathvis,i) == false){
                cout << "Cycle/s present";
                return 0;
            }
        }
    }

    cout << "No Cycles Present";
    return 0;
}

//we can also use one array just store 2 for current path and one for previous paths is vis array