//Topological sort works for DAG only.
//node u will always appear before node v if there is a directed edge from node u towards node v(u -> v).
//this order may not be unique
#include<bits/stdc++.h>
using namespace std;

void DFS(vector<vector<int>>& adj, vector<int> &vis, int node, stack<int> &st){
    vis[node] = 1;
    for(auto x : adj[node]){
        if(!vis[x]){
            DFS(adj,vis,x,st);
        }
    }
    st.push(node); // push the node in stack after all its connected nodes are visited/ pushed
    return;
}
    
vector<int> topologicalSort(vector<vector<int>>& adj) {
    int n = adj.size();
    vector<int> vis(n,0);
    stack<int> st;
    for(int i = 0; i < n; i++){
        if(!vis[i]){
            DFS(adj,vis,i,st);
        }
    }
    
    vector<int> res;
    while(!st.empty()){
        res.push_back(st.top());
        st.pop();
    }
    return res;
}

int main()
{
    vector<vector<int>> adj = {{}, {3}, {3}, {}, {1,0}, {2,0}};

    vector<int> res = topologicalSort(adj);

    for(auto x : res){
        cout << x << " ";
    }
    string s = "abc";
    
}