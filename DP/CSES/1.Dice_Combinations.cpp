#include<bits/stdc++.h>
using namespace std;

#define f(i,a,n) for(int i = a; i<n;i++)
typedef long long ll;
const int M = 1e9 + 7;
const int N = 1e6 + 10;

int dp[N];
int fun(int n){
    if(n < 0 ) return 0;
    if(dp[n] != 0) return dp[n];
    f(i,1,7){
        dp[n] = (1ll*dp[n]%M + 1ll*fun(n-i)%M) % M;
    }
    return dp[n];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    dp[0] = 1;
    cout << fun (n);

    // //***iterative***
    // int n;
    // cin >> n;
    // vector<int> dp(n+1,0);
    // dp[0] = 1;

    // f(i,1,n+1){
    //     f(j,1,7){
    //         if(i-j >=0) dp[i] = (1ll*dp[i]%M + 1ll*dp[i-j]%M) %M;
    //     }
    // }
    // cout << dp[n];

    // //***space optimization***
    // int n;
    // cin >> n;
    // vector<int> space = {0,0,0,0,0,1};
    // f(i,1,n+1){
    //     int dpi = 0;
    //     f(j,0,6){
    //         (dpi += space[j]) %= M;
    //     }
    //     f(j,1,6){
    //         space[j-1] = space[j]%M;
    //     }
    //     space[5] = dpi;
    // }
    // cout << space[5];
}