// no. of positive integers upto n which are coprime to n
#include<bits/stdc++.h>
using namespace std;

int Phi(int n){
    int res = n;
    for(int i = 2 ; i*i<=n; i++){
        if(n%i==0){
            res *= (i-1);
            res /= i;
            while(n%i == 0) n /= i;
        }
    }
    if(n>1)
    res /=n , res*=(n-1);
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout<<Phi(n)<<endl;
    }
}