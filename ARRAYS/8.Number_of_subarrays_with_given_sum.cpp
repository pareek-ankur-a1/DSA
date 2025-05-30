#include<bits/stdc++.h>
using namespace std;

int subarraySum(vector<int> &nums, int k){
    int n = nums.size();
    int ans = 0;
    unordered_map<int, int> mp;
    mp[0] = 1;
    int presum = 0;
    for (int i = 0; i < n; i++){
        presum += nums[i];
        int find = presum - k;
        ans += mp[find];
        mp[presum]++;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
}