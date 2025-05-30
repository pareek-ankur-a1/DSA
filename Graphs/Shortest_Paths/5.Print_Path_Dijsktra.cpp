//start node = 1, end node = n
#include<bits/stdc++.h>
using namespace std;

vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
    vector<vector<pair<int,int>>> adj(n+1,vector<pair<int,int>>());
    for(int i = 0; i < m; i++){
        int node1 = edges[i][0];
        int node2 = edges[i][1];
        int wt = edges[i][2];
        adj[node1].push_back({node2,wt});
        adj[node2].push_back({node1,wt});
    }
    
    priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
    vector<int> dist(n+1,1e9);
    vector<int> parent(n+1);
    parent[1] = 1;
    dist[1] = 0;
    pq.push({0,1});
    
    while(pq.size()){
        int node = pq.top().second;
        int dis = pq.top().first;
        pq.pop();
        for(auto x : adj[node]){
            int adjnode = x.first;
            int edW = x.second;
            if(edW + dis < dist[adjnode]){
                dist[adjnode] = edW + dis;
                parent[adjnode] = node;
                pq.push({edW+dis,adjnode});
            }
        }
    }
    
    if(dist[n] == 1e9) return {-1};
    vector<int> path;
    int node = n;
    while(parent[node] != node){
        path.push_back(node);
        node = parent[node];
    }
    path.push_back(1);
    path.push_back(dist[n]);
    reverse(path.begin(), path.end());
    return path;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
}