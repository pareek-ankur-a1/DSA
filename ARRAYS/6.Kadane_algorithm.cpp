// to find maximum subarray sum in given array
#include <bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int> &nums){
    int n = nums.size();
    int sum = 0;
    int maxi = -1e4;
    for (int i = 0; i < n; i++){
        sum += nums[i];
        maxi = max(maxi, sum);
        if (sum < 0)
            sum = 0;
    }
    return maxi;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}