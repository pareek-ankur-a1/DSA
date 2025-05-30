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

int N, M;
vector<vi> grid;
vector<vector<pii>> dp;

int func(int i, int j){
    if(i == N || j == M) return 1e9;
    if(i == N-1 && j == M-1) return grid[i][j];
    if(dp[i][j].ff != -1) return dp[i][j].ff; //memoization check

    int ans1 = func(i,j+1);
    int ans2 = func(i+1,j);
    if(ans1 < ans2) dp[i][j].ss = 1;
    return dp[i][j].ff = grid[i][j] + min(ans1,ans2);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    dp.assign(N, vector<pii>(M,{-1,0})); //0- down // 1- right
    grid.assign(N, vi(M));

    f(i,0,N) f(j,0,M) cin >> grid[i][j];

    cout << func(0,0) << nline;

    //Answer_Construction
    pii xy = {0,0};
    while(xy != make_pair(N-1,M-1)){
        cout << xy.ff + 1<< " " << xy.ss +1<< nline;
        if(dp[xy.ff][xy.ss].ss == 0) xy.ff++;
        else xy.ss++;
    }
    cout << xy.ff +1 << " " << xy.ss+1 << nline;
}