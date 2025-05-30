#include<bits/stdc++.h>
using namespace std;

const int N = 1000001;
bool is_prime[N];

int main()
{
    for(int i = 0 ; i<=N; i++){
        is_prime[i] = 1;
    }
    is_prime[0] = is_prime[1] = 0;
    for(int i = 2; i*i<=N;i++){
        if(is_prime[i]){
            for(int j =i*i;j<=N;j+=i){
                is_prime[j] = 0;
            }
        }
    }

    cout<<"2027 is prime : "<<is_prime[2027];
    return 0;
}