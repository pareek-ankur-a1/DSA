#include<bits/stdc++.h>
using namespace std;
vector<int> prime_factorization(int N){
    vector<int> v;
    for(int i = 2 ; i*i<=N; i++){
        if(N%i==0)
            while(N%i == 0){
                v.push_back(i);
                N /= i;
            }
    }
    if(N>1) v.push_back(N);
    return v;
}
int main()
{
    int N;
    cin >> N;
    vector<int> v = prime_factorization(N);
    for(int i = 0 ; i< v.size()-1; i++){
        cout<<v[i]<<"*";
    }
    cout<<v[v.size()-1];
}