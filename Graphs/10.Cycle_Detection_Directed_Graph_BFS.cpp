//Apply Kahn's ALGO and if the topo sort array does not have a size of n, it means there is/are cycles.
#include<bits/stdc++.h>
using namespace std;
int topologicalSort(vector<vector<int>>& adj) {
    int n = adj.size();
    vector<int> indegree(n,0);
    for(auto x : adj){
        for(auto y : x){
            indegree[y]++;
        }
    }
    
    queue<int> q;
    for(int i = 0; i < n; i++){
        if(indegree[i] == 0) q.push(i);
    }
    
    int topo = 0;
    while(q.size()){
        int node = q.front();
        q.pop();
        topo++;
        for(auto x : adj[node]){
            indegree[x]--;
            if(indegree[x] == 0) q.push(x);
        }
    }
    return topo;
    
}

bool isCyclic(vector<vector<int>> &adj) {
    int n = adj.size();
    if(topologicalSort(adj) == n){
        return false;
    }
    return true;
}

int main()
{
    vector<vector<int>> adj = {{}, {3}, {3}, {}, {0,1}, {0,2}};
    
    if(isCyclic(adj)) cout << "Cycle present";
    else cout << "No Cycle present";
    
}