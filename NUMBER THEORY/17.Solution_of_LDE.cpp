//Find any solution of a*x +b*y = c
#include<bits/stdc++.h>
using namespace std;

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

bool find_any_solution(int a, int b, int c, int &x, int &y){
    int x0, y0;
    int g = gcd_ext(abs(a),abs(b),x0,y0);
    
    if(c%g) return false;

    x = x0*c/g;
    y = y0*c/g;

    if(a<0) x = -x;
    if(b<0) y = -y;
    return true; 
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int a, b, c, x, y;
        cin >> a >> b >> c;
        if(find_any_solution(a,b,c,x,y) == false){
            cout<<"NO Solution"<<endl;
        }
        else{
            cout<<"x = "<<x<<endl;
            cout<<"y = "<<y<<endl;
        }
    }
}