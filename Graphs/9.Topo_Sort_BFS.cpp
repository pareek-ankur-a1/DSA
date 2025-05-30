//Kahn's Algorithm

#include<bits/stdc++.h>
using namespace std;

vector<int> topologicalSort(vector<vector<int>>& adj) {
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
    
    vector<int> topo;
    while(q.size()){
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for(auto x : adj[node]){
            indegree[x]--;
            if(indegree[x] == 0) q.push(x);
        }
    }
    return topo;
}


int main()
{
    vector<vector<int>> adj = {{}, {3}, {3}, {}, {0,1}, {0,2}};

    vector<int> res = topologicalSort(adj);

    for(auto x : res){
        cout << x << " ";
    }

}