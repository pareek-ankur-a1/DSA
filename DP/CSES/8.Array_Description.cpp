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
    vector<vi> dp(n,vi(m+1,0));
    if(arr[0] == 0){
        f(i,1,m+1){
            dp[0][i] = 1;
        }
    }
    else{
        f(i,1,m+1){
            if(i == arr[0]) dp[0][i] =1 ;
            else dp[0][i] = 0;
        }
    }
    f(i,1,n){
        f(j,1,m+1){
            if(arr[i] == 0 || arr[i] == j){
                dp[i][j] = dp[i-1][j] % M;
                if(j > 1) (dp[i][j] += dp[i-1][j-1]) %= M;
                if(j < m) (dp[i][j] += dp[i-1][j+1]) %= M;
            }
        }
    }
    int ans = 0;
    // f(i,0,n){
    //     f(j,1,m+1) cout << dp[i][j] << " ";
    //     cout << endl;
    // }
    f(i,1,m+1){
        (ans += dp[n-1][i] ) %= M;
    }
    cout << ans << endl;
}