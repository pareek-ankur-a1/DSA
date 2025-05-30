#include<bits/stdc++.h>
using namespace std;
#define f(i,a,n) for(int i = a; i<n;i++)
#define all(x) (x).begin(),(x).end()
#define ss second
#define ff first
#define mi map<int,int>
#define vi vector<int>
typedef long long ll;
const int M = 1e9 + 7;
const int N = 1e6 + 1;
int dp[N];

int fun(int n, vi & v){
    if(n < 0) return 0;
    if(dp[n] != -1) return dp[n];

    int ans = 0;
    f(i,0,v.size()){
        ans = (1ll*ans%M + 1ll*fun(n-v[i],v)%M) %M;
    }
    return dp[n] = ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vi v(n);
    f(i,0,n) cin >> v[i];
    f(i,0,N){
        dp[i] = -1;
    }
    dp[0] = 1;
    cout << fun(k,v);

    // iterative
    // int n,k;
    // cin >> n >> k;
    // vi a(n);
    // f(i,0,n) cin >> a[i];
    // vi dp(k+1,0);
    // dp[0] = 1;
    // f(i,1,k+1){
    //     f(j,0,n){
    //         if(i-a[j] >= 0) (dp[i] += dp[i-a[j]]) %= M;
    //     }
    // }
    // cout << dp[k];
}

// distict is very important!