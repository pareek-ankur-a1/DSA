#include<bits/stdc++.h>
using namespace std;
#define f(i,a,n) for(int i = a; i<n;i++)
#define all(x) (x).begin(),(x).end()
#define ss second
#define ff first
#define mi map<int,int>
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int,int>
#define nline "\n" 
#define pb push_back
#define INF 1e18 + 10
const int M = 1e9 + 7; 
const int N = 1e6 + 1;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vi a(n+1), b(m+1);
    f(i,1,n+1) cin >> a[i];
    f(i,1,m+1) cin >> b[i];
    vector<vector<pii>> dp(n+1,vector<pii>(m+1));
    dp[0][0].ff = 0;
    dp[0][0].ss = 0;
    f(i,1,n+1){
        f(j,1,m+1){
            if(a[i] == b[j]) {
                dp[i][j].ff = 1+ dp[i-1][j-1].ff;
                dp[i][j].ss = 0;
            }
            else{
                if (dp[i][j-1].ff > dp[i-1][j].ff){
                    dp[i][j].ff = dp[i][j-1].ff;
                    dp[i][j].ss = 1;
                }
                else{
                    dp[i][j].ff = dp[i-1][j].ff;
                    dp[i][j].ss = 2;
                }
            }
        }
    }
    cout << dp[n][m].ff << nline;
    int res = dp[n][m].ff;
    
    //ans construction
    vi ans;
    int indexa = n;
    int indexb = m;
    while(res != 0){
        if(a[indexa] == b[indexb]) {
            ans.pb(a[indexa]);
            res--;
        }
        if(dp[indexa][indexb].ss == 0) indexa--, indexb--;
        else if(dp[indexa][indexb].ss == 1) indexb--;
        else indexa--;
    }
    reverse(all(ans));
    for(auto x : ans){
        cout << x << " ";
    }
    cout << nline;
}