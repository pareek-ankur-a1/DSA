// T.C - n*(1e5)*logN since max sum can be 1e5
#include<bits/stdc++.h>
using namespace std;
#define f(i,a,n) for(int i = a; i<n;i++)
#define all(x) (x).begin(),(x).end()
#define ss second
#define ff first
#define mi map<int,int>
#define vi vector<int>

typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vi a(n);
    f(i,0,n) cin >> a[i];

    vector<set<int>> dp(n,set<int>());
    // dp[i] = money sums possible till index i
    // dp[i] => add or not add the current coin to all the sums possible in the previous state

    dp[0].insert(a[0]);
    f(i,1,n){
        dp[i] = dp[i-1];
        dp[i].insert(a[i]);
        for(auto x : dp[i-1]){
            dp[i].insert(x+a[i]);
        }
    }
    cout << dp[n-1].size() << endl;
    for(auto x : dp[n-1]){
        cout << x << " ";
    }

    // space optimization
    // set<int> curr;
    // set<int> prev;
    // prev.insert(a[0]);
    // f(i,1,n){
    //     curr = prev;
    //     curr.insert(a[i]);
    //     for(auto x : prev){
    //         curr.insert(x+a[i]);
    //     }
    //     prev = curr;
    // }
    // cout << prev.size() << endl;
    // for(auto x : prev){
    //     cout << x << " ";
    // }
}