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
const int M = 1e9 + 7;
const int N = 1e6 ;
typedef long long ll;
vector<vi> dp(N+1,vi(2,0));
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    dp[N][0] = 1, dp[N][1] = 1;
    for(int i = N-1 ; i >=1 ; i--){
        dp[i][0] = (2ll*dp[i+1][0] + dp[i+1][1]) % M;
        dp[i][1] = (4ll*dp[i+1][1] + dp[i+1][0]) % M;
    }

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << (dp[N+1-n][0] + dp[N+1-n][1]) % M << nline; // we shift the nth row to Nth row -> 1st row goes to N+1-n th row
    }
}

//dp[i][0] = number of ways to fill the tower from ith row to nth row such that a horizontal block extends from the ith row
//dp[i][1] = number of ways to fill the tower from ith row to nth row such that two vertical blocks extend from the ith row

//dp[i][0] = 2*dp[i+1][0] + dp[i+1][1]
//dp[i][1] = 4*dp[i+1][1] + dp[i+1][0] (make cases and find !)

//dp[n][0] = 1, dp[n][1] = 1 (no further extension)

//final subproblem = dp[1][0] + dp[1][1]