//https://www.codechef.com/problems/GCDMOD?tab=statement
#include<bits/stdc++.h>
using namespace std;
#define f(i,a,n) for(int i = a; i<n;i++)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
const int MOD = 1e9+7;

ll power(ll a, ll n, ll d){
    ll res = 1;
    while(n){
        if(n%2){
            n--; res = (res%d*a%d)%d;
        }
        n = n/2;
        a = (a%d*a%d)%d;
    }
    return res%d;
}

ll gcd(ll a, ll b ,ll n){
    if(a == b){
        return (power(a,n,MOD)+ power(b,n,MOD))%MOD;
    }

    ll num = a - b;
    ll ans = 1;
    for(ll i = 1; i*i <=num ; i++){
        if(num % i == 0){
            if((power(a,n,i) + power(b,n,i))%i == 0){
                ans = max(ans,i);
            }
            if((power(a,n,num/i) + power(b,n,num/i))%(num/i) == 0){
                ans = max(ans,num/i);
            }
        }
        
    }
    return ans%MOD;    
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        ll a , b, n;
        cin >> a >> b >> n;
        cout<<gcd(a,b,n)<<endl;
    }
}