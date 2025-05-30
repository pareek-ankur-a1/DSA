//Now you also have to print the indices of the selected coins
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

    int n, k;
    cin >> n >> k;
    vi a(n);
    f(i,0,n) cin >> a[i];
    vector<pii> dp(k+1,{1e9,0});
    dp[0].ff = 0;
    f(i,1,k+1){
        f(j,0,n){
            if(i -a[j] >= 0) {
                if(dp[i].ff > dp[i-a[j]].ff){
                    dp[i].ff = 1 + dp[i-a[j]].ff;
                    dp[i].ss = j;
                }
            }
        }
    }
    cout << ((dp[k].ff >= 1e9) ? -1 : dp[k].ff) << endl;

    //Answer construction
    vi ans;
    int sum = k;
    while(sum != 0){
        ans.pb(dp[sum].ss);
        sum -= a[dp[sum].ss];
    }
    sort(all(ans));
    for(auto x : ans){
        cout << x + 1 << " ";
    }
}