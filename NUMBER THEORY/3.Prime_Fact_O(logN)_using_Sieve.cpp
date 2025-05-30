#include<bits/stdc++.h>
using namespace std;
const int N = 2*1e8 + 10;
int ar[N];
int main()
{   
    //making ar so that each element stores it's smallest divisor - O(n*log(log(n)))
    for(int i = 1 ; i<N ; i++){
        ar[i] = i;
    }
    for(int i = 2 ; i*i< N ; i++){
        if(ar[i] == i){
            for(int j = i*i ; j<N ; j+=i){
                if(ar[j] == j){
                    ar[j] = i;
                }
            }
        }
    }
    //find prime factors in O(log(n))
    int n;
    cin >> n;
    vector<int> v;
    while(n!=1){
        v.push_back(ar[n]);
        n = n/ar[n];
    }
    for(int i = 0 ; i< v.size()-1; i++){
        cout<<v[i]<<"*";
    }
    cout<<v[v.size()-1];
}