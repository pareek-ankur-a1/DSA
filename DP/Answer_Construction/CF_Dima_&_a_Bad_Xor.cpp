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
    int n, m;
    cin >> n >> m;
    vector<vi> v(n,vector<int>(m));
    f(i,0,n) f(j,0,m) cin >> v[i][j];

    // state- dp[i][x] = can we get a xor = x till the ith row
    // transition dp[i][x] = dp[i-1][x^a[i][j]] ? 1 : 0
    // base- dp[0][j] = v[0][j]

    vector<vector<pair<bool,int>>> dp(n,vector<pair<bool,int>>(1024,pair<bool,int>(false,0)));
    f(j,0,m){
        dp[0][v[0][j]].ff = true;
        dp[0][v[0][j]].ss = j;   
    }
    f(row,1,n){
        f(i,0,1024){
            f(j,0,m){
                if(dp[row-1][i^v[row][j]].ff == true){
                    dp[row][i].ff = true; 
                    dp[row][i].ss = j;
                    break;
                }
            }
        }
    }
    bool ans = false;
    int last = -1;
    f(i,1,1024){
        if(dp[n-1][i].ff == true){
            ans = true; 
            last = i;
            break;
        }
    }

    if(ans == false){
        cout <<"NIE"; return 0;
    }
    //answer construction
    vi res;
    for(int i = n-1; i >= 0; i--){
        res.pb(dp[i][last].ss);
        last ^= v[i][res.back()];
    }
    cout << "TAK" << endl;
    reverse(all(res));
    for(auto x : res){
        cout << x+1 << " ";
    }
    // f(i,0,2){
    //     f(j,0,16){
    //         cout << dp[i][j].ff << " ";
    //     }
    //     cout << nline;
    // }
}