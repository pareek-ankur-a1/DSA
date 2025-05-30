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
    int n, x;
    cin >> n >> x;
    vi cost(n+1), pages(n+1);
    f(i,1,n+1) cin >> cost[i];
    f(i,1,n+1) cin >> pages[i];

    vector<vi> dp(n+1,vi(x+1,0));
    //dp[i][j] = max number of pages that can be bought from books [1...i] if I were to spend j rupees
    // base case dp[0][any] = 0 
    f(i,1,n+1){
        f(j,0,x+1){
            dp[i][j] = dp[i-1][j];
            if(j-cost[i] >= 0) dp[i][j] = max(dp[i][j], dp[i-1][j-cost[i]] + pages[i]);
        }
    }
    cout << dp[n][x];
}