#include<bits/stdc++.h>
using namespace std;

const int M = 1e9 + 7;
const int N = 1e3+1;
int C[N][N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    C[0][0] = 1;
    for(int i = 1; i<N; i++){
        for(int j = 0; j<=i; j++){
            if(j == 0) C[i][j] = 1;
            else C[i][j] = (C[i-1][j] + C[i-1][j-1]) % M;
        }
    }

    int t;
    cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b;
        cout<<C[a][b]<<endl;
    }

}