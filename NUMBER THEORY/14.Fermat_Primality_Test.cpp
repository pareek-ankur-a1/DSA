#include<bits/stdc++.h>
using namespace std;
#define f(i,a,n) for(ll i = a; i<n;i++)
#define all(x) (x).begin(),(x).end()
#define ss second
#define ff first
#define mi map<ll,ll>
#define vi vector<ll>
typedef long long ll;

ll mulmod(ll a, ll b,ll c){
    //we add a, b times, as a*b can't be done
    ll x = 0, y=a%c;
    while(b > 0){
        if(b%2 == 1){
        x = (x+y)%c;
        }
        y = (y*2LL)%c;
        b /= 2;
    }
    return x%c;
}

ll binpower(ll a, ll n, ll m){
    ll res = 1;
    while(n){
        if(n%2 != 0){
            n--; res = mulmod(res,a,m);
        }
        n /= 2; 
        a = mulmod(a,a,m);
    }
    return res;
}

bool probablyPrimeFermat(ll n, ll iter=5) {
    if (n < 4)
        return n == 2 || n == 3;

    for (ll i = 0; i < iter; i++) {
        ll a = 2 + rand() % (n - 3);
        if (binpower(a, n - 1, n) != 1)
            return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        ll a;
        cin >> a;
        if(probablyPrimeFermat(a)){
            cout<<"YES"<<endl;
        }
        else cout<<"NO"<<endl;
    }
}