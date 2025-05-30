#include<bits/stdc++.h>
using namespace std;
#define f(i,a,n) for(int i = a; i<n;i++)
#define all(x) (x).begin(),(x).end()
#define ss second
#define ff first
#define mi map<int,int>
#define vi vector<int>
typedef long long ll;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> ans;
    int top = 0, bottom = n-1, left = 0, right = m -1;
    while(top <= bottom && left <= right){
        for(int i = left; i<= right; i++){
            ans.push_back(matrix[top][i]);
        }
        top++;
        for(int i = top; i <= bottom; i++){
            ans.push_back(matrix[i][right]);
        }
        right--;
        if(top <= bottom){
            for(int i = right; i>= left; i--){
                ans.push_back(matrix[bottom][i]);
            }
        }
        bottom--;
        if(left <= right){
            for(int i = bottom ; i >= top; i--){
                ans.push_back(matrix[i][left]);
            }
        }
        left++;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
}