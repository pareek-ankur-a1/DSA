#include<bits/stdc++.h>
using namespace std;
#define f(i,a,n) for(int i = a; i<n;i++)
typedef long long ll;

const int N = 101;
const int mod = 1e9 + 7;
int ar[N][N], I[N][N];

void mul (int A[][N], int B[][N], int dim){
    int res[dim][dim];
    f(i,0,dim) f(j,0,dim){
        res[i][j] = 0;
        f(k,0,dim) res[i][j] += A[i][k] * B[k][j];
    }
    f(i,0,dim) f(j,0,dim){
        A[i][j] = res[i][j];
    }
}
void power(int A[][N], int dim, int n){
    f(i,0,dim) f(j,0,dim){
        if(i == j) I[i][j] = 1;
        else I[i][j] = 0;
    }
    while(n){
        if(n%2){
            mul(I,A,dim); n--;
        }
        mul(A,A,dim); n/=2;
    }
    f(i,0,dim) f(j,0,dim) A[i][j] = I[i][j];
}

int main()
{   
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        ar[0][0] = 0;
        ar[0][1] = ar[1][0] = ar[1][1] = 1;

        power(ar,2,n-1);

        int fn = ar[1][0]*1; //as f1 = 0
        cout<<fn<<endl;
    }
}