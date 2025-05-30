#include<bits/stdc++.h>
using namespace std;
#define f(i,a,n) for(int i = a; i<n;i++)
#define vi vector<int>
typedef long long ll;

//state- dp[i][j] = min number of cuts to convert reactangle of i*j into squares
//transition- dp[i][j] = min(1+dp[i][k]+dp[i][j-k], 1 + dp[k][j]+dp[i-k][j])
//base case- dp[i][i] = 0
//final subproblem- dp[n][m]

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int w, h;
    cin >> w >> h;
    vector<vi> dp(w+1,vi(h+1,0));
    f(i,1,w+1){
        f(j,1,h+1){
            if(i == j) continue;
            dp[i][j] = 1e9;
            f(k,1,i){
                dp[i][j] = min(dp[i][j],1+dp[k][j]+dp[i-k][j]);
            }
            f(k,1,j){
                dp[i][j] = min(dp[i][j],1+dp[i][k]+dp[i][j-k]);
            }
        }
    }
    cout << dp[w][h];
}