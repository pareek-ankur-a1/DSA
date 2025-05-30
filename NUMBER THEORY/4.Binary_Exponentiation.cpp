//T.C = O(logn)
#include<bits/stdc++.h>
using namespace std;

int power(int a, int n){
    int res = 1;
    while(n){
        if(n%2 != 0){
            n--; res = res * a;
        }
        n /= 2; a = a*a; 
        //n must be even at this step. for n = 0, res is not affected
    }
    return res;
}

int power(int a, int n, int M){
    int res = 1;
    while(n){
        if(n%2 != 0){
            n--; res = ((res%M)*(a%M))%M;
        }
        n /= 2; a = ((a%M)*(a%M))%M; 
    }
    return res;
}
int main()
{
    int a, n;
    cin >> a >> n;
    cout<<power(a,n)<<endl;
}