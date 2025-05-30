#include<bits/stdc++.h>
using namespace std;

void DFS_Graph(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &dfs){
    vis[node] = 1;
    dfs.push_back(node);
    for(auto x : adj[node]){
        if(!vis[x]) DFS_Graph(x,adj,vis,dfs);
    }
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

    vector<int> dfs;
    vector<int> vis(n+1,0);
    int node = 1; //starting node (1 based)
    DFS_Graph(node, adj, vis, dfs);

    for(auto x : dfs){
        cout << x << " ";
    }
}

//SC- O(3N)- stack space + visisted array + bfs (extra space)
//TC- O(N) + O(2E) for undirected graph, O(N) + O(E) for directed graph. 
// for each node the loop runs for N = degree of that node. So, in total it runs for summation of degrees, which is 2*E. Also, N recursive calls are made.