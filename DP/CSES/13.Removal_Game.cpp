#include<bits/stdc++.h>
using namespace std;
#define f(i,a,n) for(int i = a; i<n;i++)
#define all(x) (x).begin(),(x).end()
#define ss second
#define ff first
#define mi map<int,int>
#define vi vector<int>
#define pii pair<int,int>
#define nline "\n" 
#define pb push_back
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vi a(n);
    f(i,0,n) cin >> a[i];
    vector<vector<ll>> dp(n,vector<ll>(n));

    //dp[i][j] = max sum for subarray [i...j] for player whose turn it is
    //dp[i][j] = max(a[i] + sum[i+1][j] - dp[i+1][j], a[j] + sum[i][j-1] - dp[i][j-1]);
    //dp[i][i] = a[i]
    //dp[0][n-1]

    f(i,0,n){
        dp[i][i] = a[i];
    }
    vector<ll> presum(n+1);
    presum[0] = 0;
    f(i,1,n+1) presum[i] = presum[i-1] + a[i-1];
    for(int len = 2; len <= n; len++){
        int i = 0;
        f(j,len-1,n){
            dp[i][j] = max(1ll*a[i] + presum[j+1] - presum[i+1] - dp[i+1][j], 1ll*a[j] + presum[j]-presum[i] -dp[i][j-1]);
            i++;
        }
    }
    cout << dp[0][n-1];
}