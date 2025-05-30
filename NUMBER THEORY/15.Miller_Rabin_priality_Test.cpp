//determinitsic version
#include<bits/stdc++.h>
using namespace std;
#define f(i,a,n) for(int i = a; i<n;i++)
#define all(x) (x).begin(),(x).end()
#define ss second
#define ff first
#define mi map<int,int>
#define vi vector<int>
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

ll binpower(ll base, ll e, ll mod) {
    ll result = 1;
    base %= mod;
    while (e) {
        if (e & 1)
            result = mulmod(base,result,mod);
        base = mulmod(base,base,mod);
        e >>= 1;
    }
    return result;
}

bool check_composite(ll n, ll a, ll d, int s) {
    ll x = binpower(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (int r = 1; r < s; r++) {
        x = mulmod(x,x,n);
        if (x == n - 1)
            return false;
    }
    return true;
}

bool MillerRabin(ll n) { // returns true if n is prime, else returns false.
    if (n < 2)
        return false;

    int r = 0;
    ll d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        r++;
    }

    for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (n == a)
            return true;
        if (check_composite(n, a, d, r))
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
        ll n;
        cin >> n;
        if(MillerRabin(n)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}