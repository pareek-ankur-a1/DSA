#include<bits/stdc++.h>
using namespace std;
#define f(i,a,n) for(int i = a; i<n;i++)
#define vi vector<int>
typedef long long ll;
const int M = 1e9 + 7;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vi arr(n);
    f(i,0,n) cin >> arr[i];
    vector<vi> dp(2,vi(m+1,0));
    //dp[i][j] == no. of ways to fill [1...i] such that element i is j
    if(arr[0] == 0){
        f(i,1,m+1){
            dp[1][i] = 1;
        }
    }
    else{
        f(i,1,m+1){
            if(i == arr[0]) dp[1][i] =1 ;
            else dp[1][i] = 0;
        }
    }
    f(i,1,n){
        dp[0] = dp[1]; 
        f(j,1,m+1){
            if(arr[i] == 0 || arr[i] == j){
                dp[1][j] = dp[0][j] % M;
                if(j > 1) (dp[1][j] += dp[0][j-1]) %= M;
                if(j < m) (dp[1][j] += dp[0][j+1]) %= M;
            }
            else dp[1][j] = 0;
        }
    }
    int ans = 0;
    f(i,1,m+1){
        (ans += dp[1][i] ) %= M;
    }
    cout << ans << endl;
}