#include<bits/stdc++.h>
using namespace std;

long long nCr(int n, int r){
    long long ans = 1;
    for (int i = 0; i < r; i++){
        ans *= (n-i);
        ans /= (i+1);
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << nCr(5,2);
}