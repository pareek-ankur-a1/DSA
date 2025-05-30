//
#include<bits/stdc++.h>
using namespace std;
#define f(i,a,n) for(int i = a; i<n;i++)
#define all(x) (x).begin(),(x).end()
#define vi vector<int>
typedef long long ll;

const int N = 1e5+1;
vi is_prime(N,1);

void sieve(){
    is_prime[1] = 0;
    for(int i = 2; i*i<=N;i++){
        if(is_prime[i]){
            for(int j =i*i;j<=N;j+=i){
                is_prime[j] = 0;
            }
        }
    }   
    return;
}

void primes(int l, int r){
    if(l == 1) l++;
    int maxN = r-l+1;
    vi ar (maxN,1);
    
    for(int i = 2; i<N; i++){
        if(i*i<=r){
            if(is_prime[i]){
                int start = max(i * i, l + (i - l % i)%i); // not just l + i- l%i
                for(int j = start; j<=r; j+=i){
                    ar[j-l] = 0;
                }
            }
        }
        else break;
    }

    for(int i = 0; i< maxN; i++){ // not <=
        if(ar[i]) cout<<i+l<<endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    sieve();
    int t;
    cin >> t;
    while(t--){
        int l, r;
        cin >> l >> r;
        primes(l,r);
    }
}