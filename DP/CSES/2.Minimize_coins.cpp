#include<bits/stdc++.h>
using namespace std;
#define f(i,a,n) for(int i = a; i<n;i++)
#define all(x) (x).begin(),(x).end()
#define ss second
#define ff first
#define mi map<int,int>
#define vi vector<int>
typedef long long ll;
const int N = 1e6 + 1;
int dp[N];
 
int fun(int n, vi & v){
    if(dp[n] != 0) return dp[n];
    int ans = N+1;
    f(i,0,v.size()){
        if(n - v[i] > 0) ans = min(fun(n-v[i],v)+1,ans);
    }
    if(ans >= N) return -1;
    else return dp[n] = ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // int n, k;
    // cin >> n >> k;
    // vi v(n);
    // f(i,0,n) cin >> v[i];
    // f(i,0,n){
    //     dp[v[i]] = 1;
    // }
    // cout << fun(k,v);

    // iterative
    int n, k;
    cin >> n >> k;
    vi a(n);
    f(i,0,n) cin >> a[i];
    vi dp(k+1,1e9);
    dp[0] = 0;
    f(i,1,k+1){
        f(j,0,n){
            if(i -a[j] >= 0) dp[i] = min(dp[i-a[j]]+1,dp[i]);
        }
    }
    cout << ((dp[k] >= 1e9) ? -1 : dp[k]);
}