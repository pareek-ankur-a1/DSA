#include<bits/stdc++.h>
using namespace std;

vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
    vector<int> dist(V,1e8);
    dist[src] = 0;
    bool update = false; // to save iterations in avg case
    for(int i = 0; i < V-1; i++){
        update = false; 
        for(auto x : edges){
            int u = x[0], v = x[1], wt = x[2];
            if(dist[u] != 1e8 && dist[u] + wt < dist[v]){
                dist[v] = dist[u] + wt;
                update = true;
            }
        }
        if(update == false) break;
    }
    
    // check for negative cycles
    if(update == false) return dist;
    
    for(auto x : edges){
        int u = x[0], v = x[1], wt = x[2];
        if(dist[u] != 1e8 && dist[u] + wt < dist[v]){
            return {-1};
        }
    }
    return dist;
    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
}