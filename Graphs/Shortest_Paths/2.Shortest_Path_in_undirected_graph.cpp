//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

//Back-end complete function Template for C++


// } Driver Code Ends

class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        int n = adj.size();
        vector<int> dist(n,-1);
        queue<int> q;
        q.push(src);
        dist[src] = 0;
        while(q.size()){
            int node = q.front();
            q.pop();
            for(auto x : adj[node]){
                if(dist[x] == -1) {
                    dist[x] = dist[node] + 1;
                    q.push(x);
                }
            }
        }
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int src;
        cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(adj, src);

        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
        cout << "~\n";

    }
}

// } Driver Code Ends