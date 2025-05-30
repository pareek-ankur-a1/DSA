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
const int M = 1e9 + 7;

int power(int a, int m){
    int res = 1;
    while(m){
    if(m%2) {m--; res = (1ll*res*a) % M;}
    m = m/2;
    a = (1ll*a*a)%M;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int sum = n*(n+1)/2;
    if(sum % 2){
        cout << 0; return 0;
    }

    //dp[value][i] = number of ways to create sum = value till ith index
    //dp[value][i] = dp[value][i-1] + dp[value-i][i-1];
    //base case- dp[0][0] = 1

    vector<vi> dp(sum+1,vi(n+1,0));
    dp[0][0] = 1;
    f(i,1,n+1){
        f(j,0,sum/2+1){
            dp[j][i] = dp[j][i-1] % M;
            if(j-i >= 0) (dp[j][i] += dp[j-i][i-1]) %= M;
        }
    }
    cout << (1ll *(dp[sum/2][n]%M) * (power(2,M-2)%M)) % M;
    // since we have counted each partition twice
}