#include<bits/stdc++.h>
using namespace std;

vector<int> BFS_Graph(vector<vector<int>> adj, int n){
    vector<bool> vis(n+1,0);
    vector<int> bfs;
    queue<int> q;
    vis[1] = 1; // 1 based indexing (1 is starting node)
    q.push(1);

    while(q.size()){
        int node = q.front();
        q.pop();
        bfs.push_back(node);
        for(auto x : adj[node]){
            if(!vis[x]){
                q.push(x);
                vis[x] = 1;
            }
        }
    }

    return bfs;
}

int main()
{
    int n, m; // n- nodes, m- edges
    cin >> n >> m;
    vector<vector<int>> adj(n+1,vector<int>()); // adjacency list
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v); // undirected
        adj[v].push_back(u);
    }

    vector<int> bfs = BFS_Graph(adj, n);

    for(int x : bfs){
        cout << x << " ";
    }
}

//SC- O(3N) - queue + bfs + visited
//TC- O(N) - for while loop + O(2E) - for inner for loop (beacuse it runs for summation of degrees times)

//MultiSource BFS- keep multiple starting nodes in the queue