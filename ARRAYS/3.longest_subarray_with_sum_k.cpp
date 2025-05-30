// this code works for array with negatives as well.
// For non-negatives only use sliding window
#include<bits/stdc++.h>
using namespace std;

int lenOfLongestSubarr(vector<int>& arr, int k) {
        long long sum = 0;
        int maxlen = 0;
        map<long long, int> mp;
        int n = arr.size();
        for(int i = 0; i < n; i++){
            sum += arr[i];
            if(sum == k) maxlen = max(maxlen, i+1);
            long long rem = sum - k;
            if(mp.find(rem) != mp.end()){
                int len = i - mp[rem];
                maxlen = max(maxlen, len);
            }
            if(mp.find(sum) == mp.end()) mp[sum] = i;
        }
        return maxlen;
    }

// For only non-negatives
int lsubarr_sumk(vector<int>& arr, int k){
    int n = arr.size();
    int l = 0, r = 0;
    long long sum = 0;
    int maxlen = 0;
    while(r<n){
        sum += arr[r];
        while(l <= r && sum > k) {
            sum -= arr[l];
            l++;
        }
        if (sum == k){
            maxlen = max(maxlen, r - l + 1);
        }
        r++;
    }
    return maxlen;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<int> v = {1,2,3,0,5,1,1,1,2};
    cout << lsubarr_sumk(v,5) << endl;
    cout << lenOfLongestSubarr(v,5);
}