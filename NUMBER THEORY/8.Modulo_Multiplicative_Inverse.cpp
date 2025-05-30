//#Fermi's Little Theorem
//Valid when m is prime and a,p are coprimes
#include<bits/stdc++.h>
using namespace std;

int power(int a, int m){
    int res = 1;
    while(m){
    if(m%2) {m--; res = res*a;}
    m = m/2;
    a *= a;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a,m;
    cin >> a >> m;
    cout<<"a^-1 = "<<power(a,m-2);
}