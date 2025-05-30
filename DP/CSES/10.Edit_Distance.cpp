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
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    vector<vector<int>> dp(n+1,vi(m+1));

    // dp[i][j] -> edit distance between string s[i:n-1] and t[j:m-1]
    // dp[i][j] == dp[i+1][j+1] if s[i] == s[j]
    // dp[i][j] == 1 + min(dp[i][j+1],dp[i+1][j],dp[i+1][j+1]) considering all five cases of insertion and removal of characters in the two strings
    // final subproblem = dp[0][0]
    // base case -> dp[n][j] = m - j, dp[i][m] = n - i
    
    f(i,0,n+1){
        dp[i][m] = n - i;
    }
    f(j,0,m){
        dp[n][j] = m - j;
    }

    for(int i = n-1; i >= 0; i--){
        for(int j = m-1; j >= 0; j--){
            if(s[i] == t[j]) dp[i][j] = dp[i+1][j+1];
            else dp[i][j] = 1 + min(dp[i][j+1],min(dp[i+1][j],dp[i+1][j+1]));
        }
    }
    cout << dp[0][0];
}  