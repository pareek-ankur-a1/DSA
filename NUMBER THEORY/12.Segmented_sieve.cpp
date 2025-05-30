//Disclaimer : not tested
//generate all primes from 10^6(N) to 2*10^6(2N)
#include<bits/stdc++.h>
using namespace std;
#define f(i,a,n) for(int i = a; i<n;i++)
#define all(x) (x).begin(),(x).end()
typedef long long ll;

const int N = 1000001;
bool is_prime1[N];
bool is_prime2[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0 ; i<=N; i++){
        is_prime1[i] = 1;
        is_prime2[i] = 1;
    }
    is_prime1[0] = is_prime1[1] = 0;
    for(int i = 2; i*i<=N;i++){
        if(is_prime1[i]){
            for(int j =i*i;j<=N;j+=i){
                is_prime1[j] = 0;
            }
        }
    }

    for(int i = 2; i<=N; i++){
        if(is_prime1[i]){
            for(int j =N+(i-N%i);j<=2*N;j+=i){
                is_prime2[j-N] = 0;
            }
        }
    }

    ll chk;
    cin >> chk;
    cout<<"isprime("<<chk<<")"<<" ="<<is_prime2[chk-N];
}