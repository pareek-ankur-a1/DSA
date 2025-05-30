#include<bits/stdc++.h>
using namespace std;
#define f(i,a,n) for(int i = a; i<n;i++)
#define all(x) (x).begin(),(x).end()
#define ss second
#define ff first
#define mi map<int,int>
#define vi vector<int>
typedef long long ll;
const int M = 1e9 + 7;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
        int n;
        cin >> n;
        char arr[n][n];
        f(i,0,n){
            f(j,0,n){
                cin >> arr[i][j];
            }
        }
        
        if(arr[0][0] == '*'){
            cout << 0;
            return 0;
        }
 
        vector<vector<int>> dp(n,vector<int>(n,0));
        dp[n-1][n-1] = 1;
        for(int i = n-1; i >= 0; i--){
            for(int j = n-1; j >=0; j--){
                if(i+1 < n && arr[i+1][j] != '*') dp[i][j] = (dp[i][j] + dp[i+1][j]%M)%M;
                if(j+1 < n && arr[i][j+1] != '*') dp[i][j] = (dp[i][j] + dp[i][j+1]%M)%M;
            }
        }
        cout << dp[0][0] ;
}


//space optimized-
// #include<bits/stdc++.h>
// using namespace std;
// #define f(i,a,n) for(int i = a; i<n;i++)
// #define all(x) (x).begin(),(x).end()
// #define ss second
// #define ff first
// #define mi map<int,int>
// #define vi vector<int>
// typedef long long ll;
// const int M = 1e9 + 7;
// int main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//         int n;
//         cin >> n;
//         char arr[n][n];
//         f(i,0,n){
//             f(j,0,n){
//                 cin >> arr[i][j];
//             }
//         }
        
//         if(arr[0][0] == '*'){
//             cout << 0;
//             return 0;
//         }
 
//         vi current(n,0);
//         vi previous(n,0);
//         vi temp(n,0);
//         current[n-1] = 1;
//         for(int i = n-1; i >= 0; i--){
//             for(int j = n-1; j >=0; j--){
//                 if(j+1 < n && arr[i][j+1] != '*') current[j] = (current[j] + current[j+1])%M;
//                 if(i+1 < n && arr[i+1][j] != '*') current[j] = (current[j] + previous[j])%M;
//             }
//             previous = current;
//             current = temp;
//         }
//         cout << previous[0];
// }