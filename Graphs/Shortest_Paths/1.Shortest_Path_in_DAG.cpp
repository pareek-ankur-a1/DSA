#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void DFS(vector<vector<pair<int,int>>> &adj, int node, stack<int> & st, vector<int> &vis){
        vis[node] = 1;
        for(auto x : adj[node]){
            if(!vis[x.first]) DFS(adj,x.first,st,vis);
        }
        st.push(node);
    }
    stack<int> topologicalsort(vector<vector<pair<int,int>>> &adj, int V){
        vector<int> vis(V,0);
        stack<int> st;
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                DFS(adj,i,st,vis);
            }
        }
        return st;
    }
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(V,vector<pair<int,int>>());
        for(auto x : edges){
            adj[x[0]].push_back({x[1],x[2]});
        }
        
        vector<int> dist(V,-1);
        dist[0] = 0; // starting node
        stack<int> st = topologicalsort(adj,V);

        while(!st.empty()){
            int node = st.top();
            st.pop();
            for(auto x : adj[node]){
                int v = x.first;
                int wt = x.second;
                if(dist[node] != -1){
                    if(dist[v] == -1) dist[v] = dist[node] + wt;
                    else dist[v] = min(dist[v], dist[node] + wt);
                }
            }
        }
        
        return dist;
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
}

//4
//2
//0 1 2
//0 2 1