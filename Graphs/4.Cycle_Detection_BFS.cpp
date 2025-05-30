#include<bits/stdc++.h>
using namespace std;

bool isCycle(vector<vector<int>> &adj, vector<bool> &vis, int n, int start){
    pair<int,int> snode = {start,-1}; // no parent
    queue<pair<int,int>> q;
    q.push(snode);
    while(q.size()){
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();
        vis[node] = true;
        for(auto adjnode : adj[node]){
            if(!vis[adjnode]){
                q.push({adjnode,node});
            }
            else if(adjnode != parent){
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1,vector<int>()); 
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v); 
        adj[v].push_back(u);
    }

    vector<bool> vis(n + 1, false);
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            if(isCycle(adj,vis,n,i)) {
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
}

//SC- O(N)       
//TC- O(N+2E) (for BFS) + O(N) (for loop)