//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User Function Template
class Solution {
  public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex src.
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        int n = adj.size();
        set<pair<int,int>> s;
        vector<int> dist(n,1e9);
        
        s.insert({0,src});
        dist[src] = 0;
        while(s.size()){
            int dis = s.begin()->first;
            int node = s.begin()->second;
            s.erase(s.begin());
            for(auto x : adj[node]){
                int edgeweight = x.second;
                int adjnode = x.first;
                if(dis + edgeweight < dist[adjnode]){
                    if(dist[adjnode] != 1e9) s.erase({dist[adjnode],adjnode});
                    dist[adjnode] = dis + edgeweight;
                    s.insert({dist[adjnode],adjnode});
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
        vector<vector<pair<int, int>>> adj(V);
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            pair<int, int> t1 = {v, w}, t2 = {u, w};
            adj[u].push_back(t1);
            adj[v].push_back(t2);
        }
        int src;
        cin >> src;
        cin.ignore();

        Solution obj;
        vector<int> res = obj.dijkstra(adj, src);

        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends