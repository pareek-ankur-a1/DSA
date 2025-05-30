#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>

vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
    int n = adj.size();
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<int> dist(n,1e9);
    
    pq.push({0,src});
    dist[src] = 0;
    while(pq.size()){
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        for(auto x : adj[node]){
            int edgeweight = x.second;
            int adjnode = x.first;
            if(dis + edgeweight < dist[adjnode]){
                dist[adjnode] = dis + edgeweight;
                pq.push({dist[adjnode],adjnode});
            }
        }
    }
    
    return dist;
}



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

        vector<int> res = dijkstra(adj, src);

        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends