
#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 1;
int phi[N];

void init(int maxN){ //O(log(logN))
    for(int i = 1; i<= maxN; i++){
        phi[i] = i;
    }
    for(int i = 2; i<=maxN; i++){
        if(phi[i] == i){
            for(int j = i; j<=maxN; j+=i){
                phi[j] *= (i-1);
                phi[j] /= i;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    init(36);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout<<phi[n]<<endl; //O(1)
    }

}