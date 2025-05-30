#include<bits/stdc++.h>
using namespace std;

    bool DFS(int node, vector<vector<int>>& graph, vector<int> &vis, int color){
        vis[node] = color;
        for(auto x : graph[node]){
            if(vis[x] == -1){
                //DFS(x, graph, vis, !color); ❌ Ignoring the return value
                if(DFS(x,graph,vis,!color) == false) return false;
            }
            else{
                if(color == vis[x]) return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n,-1); //-1 means not colored
        for(int i = 0; i < n; i++){
            if(vis[i] == -1){
                if(DFS(i,graph,vis,0) == false) return false;
            }
        }
        return true;
    }
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<vector<int>> adj = {{},{2},{1},{4},{3}};
    cout << isBipartite(adj);
}

//If a graph has odd length cylce then it can't be bipartite, otherwise it can be
//TC - O(V+2E)
//SC - O(3V) - stack, vis, graph