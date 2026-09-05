//GOAL IS TO GET GOOD AT PROBLEM SOLVING, NOT TO SOLVE THIS PARTICULAR PROBLEM
#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;

vector<vector<int>> floyd_warshall(vector<vector<pair<int,int>>>&adj, int n){
    vector<vector<int>> dist(n+1,vector<int>(n+1,INF));
    for(int i = 1; i <= n; i++){
        dist[i][i] = 0; //important
        for(auto x : adj[i]){
            dist[i][x.first] = x.second; //assuming no duplicate edges
        }
    }
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(dist[i][k] != INF && dist[k][j] != INF){
                    dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }
    }
    return dist;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
}