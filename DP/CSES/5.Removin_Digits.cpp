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
    int n;
    cin >> n;
    vector<int> dp(n + 1);
    dp[0] = 0;
    f(i, 1, n + 1)
    {
        int temp = i;
        int ans = INT_MAX;
        while (temp != 0)
        {
            if (temp % 10 != 0)
                ans = min(ans, 1 + dp[i - temp % 10]);
            temp /= 10;
        }
        dp[i] = ans;
    }
    cout << dp[n];
}