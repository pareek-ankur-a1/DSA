//Flood Fill
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void DFS(vector<vector<int>> &ans, pair<int,int> node, int color, int oldcolor, int n, int m){
        int r = node.first;
        int c = node.second;
        ans[r][c] = color;
        int drow[4] = {0,0,-1,+1};
        int dcol[4] = {-1,+1,0,0};
        int nr , nc;
        for(int i = 0; i < 4 ; i++){
            nr = r + drow[i];
            nc = c + dcol[i];
            if(nr < n && nc < m && nr >= 0 && nc >= 0 && ans[nr][nc] == oldcolor){
                DFS(ans, {nr,nc}, color, oldcolor, n, m);
            }
        }
        return;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int oldcolor = image[sr][sc];
        if(oldcolor == color) return image;

        vector<vector<int>> ans = image;
        DFS(ans,{sr,sc},color,oldcolor,n,m);
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> image = {{1,1,1},{1,1,0},{1,0,1}};
    vector<vector<int>> newimage = sol.floodFill(image,1,1,2);
    for(auto x : newimage){
        for(auto y : x){
            cout << y << " ";
        }
        cout << endl;
    }
}