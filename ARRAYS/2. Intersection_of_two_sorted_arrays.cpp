#include<bits/stdc++.h>
using namespace std;

vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
{
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    int n = nums1.size(), m = nums2.size();
    int i = 0, j = 0;
    vector<int> ans;
    while (i < n && j < m)
    {
        if (nums1[i] < nums2[j])
            i++;
        else if (nums1[i] > nums2[j])
            j++;
        else
        {
            if (ans.empty() || ans.back() != nums1[i])
                ans.push_back(nums1[i]);
            i++;
            j++;
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
}