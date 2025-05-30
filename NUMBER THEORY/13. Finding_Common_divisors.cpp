//https://www.codechef.com/problems/QNUMBER?tab=statement
// N, q is given. For each query a query type (t) and a no. k is given
// O(q*(logN)^2)
#include<bits/stdc++.h>
using namespace std;
#define f(i,a,n) for(int i = a; i<n;i++)
#define all(x) (x).begin(),(x).end()
#define ss second
#define ff first
typedef long long ll;

map<ll,ll> m;
ll total =1;
void prime_fact(ll N){
    //prime fact in sqrt(N)
    for(ll i = 2 ; i*i<=N; i++){
        if(N%i==0){
            ll x  = 0;
            while(N%i == 0){
                x++;
                N /= i;
            }
            m[i] = x;
            total *= (x+1);
        }
    }
    if(N>1) {m[N] = 1; total *= 2;}
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll N, q;
    cin >> N >> q;
    prime_fact(N);
    
    while(q--){
        ll t, k;
        cin >> t >> k;
        ll ans = 1;

        if(t == 1){
            //Find no. of common divisors of N and k
            for(auto i : m){
                ll x = 0;
                while(k%i.ff == 0){
                    x++; k = k/i.ff;
                }
                ans *= min(i.ss, x) +1;
            }
            cout<<ans<<endl;
        }

        else if(t == 2){
            //Find total no. of divisors of N which are divisible by k
            for(auto i : m){
                ll x = 0;
                while(k%i.ff == 0){
                    x++; k = k/i.ff;
                }
                if(x>i.ss){ ans = 0; break; }
                ans *= (i.ss - x + 1);
            }
            if(k>1) ans = 0;
            cout<<ans<<endl;
        }

        else{
            //Find total no. of divisors of N which are not divisible by k
            for(auto i : m){
                ll x = 0;
                while(k%i.ff == 0){
                    x++; k = k/i.ff;
                }
                if(x>i.ss){ ans = 0; break; }
                ans *= (i.ss - x + 1);
            }
            if(k>1) ans = 0;
            cout<<total - ans<<endl;
        }
    }
}