#include <bits/stdc++.h>
using namespace std;
#define f(i, a, n) for (int i = a; i < n; i++)
#define all(x) (x).begin(), (x).end()
#define ss second
#define ff first
#define mi map<int, int>
#define vi vector<int>
typedef long long ll;
const int M = 1e9 + 7;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vi v(n + 1);
    f(i, 1, n + 1) cin >> v[i];
    sort(all(v)); // no need
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    // dp[i][j] = number of ordered ways to get money sum j using first i coins
    // dp[i][j] = dp[i-1][j] (don't select ith coin) + dp[i][j-v[i]] (select it)
    dp[0][0] = 1; // base case : one way to make a sum of 0
    f(i, 1, n + 1)
    {
        f(j, 0, k + 1)
        {
            dp[i][j] = dp[i - 1][j];
            if (j - v[i] >= 0)
                (dp[i][j] += dp[i][j - v[i]]) %= M; // write dp[i-1][j-v[i]] if the coins can't be repeated.
        }
    }
    cout << dp[n][k];
}