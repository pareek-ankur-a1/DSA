#include<bits/stdc++.h>
using namespace std;

vector<int> generate_rows(int N){
    vector<int> row;
    row.push_back(1);
    int ans = 1;
    for (int i = 1; i < N; i++){
        ans *= (N - i);
        ans /= i;
        row.push_back(ans);
    }
    return row;
}
vector<vector<int>> generate(int numRows){
    vector<vector<int>> v;
    for (int i = 1; i <= numRows; i++){
        v.push_back(generate_rows(i));
    }
    return v;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
}