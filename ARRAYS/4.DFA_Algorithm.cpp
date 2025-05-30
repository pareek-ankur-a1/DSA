// to sort array with only 0,1 and 2 in O(N) and O(1)
#include <bits/stdc++.h>
using namespace std;

void sortColors(vector<int> &nums)
{
    int n = nums.size();
    int low = 0, mid = 0, high = n - 1;
    while (mid <= high){
        if (nums[mid] == 0){
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        }
        else if (nums[mid] == 1) mid++;
        else{
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}