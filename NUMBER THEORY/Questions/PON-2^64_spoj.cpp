#include<bits/stdc++.h>
using namespace std;
#define f(i,a,n) for(int i = a; i<n;i++)
#define all(x) (x).begin(),(x).end()
#define ss second
#define ff first
#define mi map<int,int>
#define vi vector<int>
typedef long long ll;

int binpower(int a, int n, int m){
    int res = 1;
    while(n){
        if(n%2 != 0){
            n--; res = (1ll*res*a)%m;
        }
        n /= 2; 
        a = (1ll*a*a)%m;
    }
    return res;
}

bool probablyPrimeFermat(int n, int iter=5) {
    if (n < 4)
        return n == 2 || n == 3;

    for (int i = 0; i < iter; i++) {
        int a = 2 + rand() % (n - 3);
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
        int a;
        cin >> a;
        cout<<"is_prime("<<a<<") = "<<probablyPrimeFermat(a)<<endl;
    }
}