//https://cses.fi/problemset/result/11323149/
#include<bits/stdc++.h>
using namespace std;
#define f(i,a,n) for(int i = a; i<n;i++)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
const int N = 1e6+1;
const int MOD = 1e9 + 7;
int F[N]; //precalculate factorials

int power(int a, int b){
    int res =1 ;
    while(b){
        if(b%2) {b--; res = (1ll*res*a)%MOD;}
        b = b/2;
        a = (1ll*a*a)%MOD;
    }
    return res;
}

int C(int n, int k){
    //nCk % MOD = {n!/(k!*(n-k)!)}%MOD == {n! % MOD} * {(k!)^-1 % MOD} * {((n-k)!)^-1 % MOD}
    //MOD must be prime to find inverse
    if(k>n) return 0;
    int res = F[n];
    res = (1ll*res*power(F[k],MOD-2))%MOD;
    res = (1ll*res*power(F[n-k],MOD-2))%MOD;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    F[0] = 1;
    f(i,1,N){
        F[i] = 1ll*i*F[i-1]%MOD;
    }

    int t;
    cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b;
        cout<<C(a,b)<<endl;
    }
}


