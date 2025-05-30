//O(n*logn + q*sqrt(n));

#include<bits/stdc++.h>
using namespace std;

const int N = 1e6;
int phi[N];
void init(int n){
    for(int i = 1; i<n; i++){
        phi[i] = i;
    }
    for(int i = 2; i<=n; i++){
        if(phi[i] == i){
            for(int j = i; j<=n; j+=i){
                phi[j] *= (i-1);
                phi[j] /= i;
            }
        }
    }
}
int get_count(int d, int n){
    return phi[n/d];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin >> q;
    init(N); // make the phi array using sieve
    while(q--){
        int n;
        cin >> n;
        int res  = 0;

        for(int i =1 ; i*i<= n; i++){
            if(n%i == 0){
                int d1 = i;
                int d2 = n/i;
                res += d1*get_count(d1, n);
                //get_count = no. of nos from 1 to n with gcd (no.,n) = d1
                if(d2 != d1) res += d2*get_count(d2,n);
            }
        }
        cout<<res<<endl;
    }
}