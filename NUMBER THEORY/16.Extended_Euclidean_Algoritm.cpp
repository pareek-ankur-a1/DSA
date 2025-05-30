#include<bits/stdc++.h>
using namespace std;
#define f(i,a,n) for(int i = a; i<n;i++)
#define all(x) (x).begin(),(x).end()
#define ss second
#define ff first
#define mi map<int,int>
#define vi vector<int>
typedef long long ll;

int gcd_ext(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd_ext(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a, b, x, y;
    a = 81, b = 57;
    cout<<gcd_ext(a,b,x,y)<<endl;
    cout<<"x = "<<x<<" y = "<<y<<endl;
}