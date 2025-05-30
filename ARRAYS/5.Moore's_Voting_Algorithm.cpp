//To find element with frequency > (n/2) in array
#include <bits/stdc++.h>
using namespace std;

// here we have assumed that majority element does exist
int majorityElement(vector<int> &nums)
{
    int n = nums.size();
    int cnt = 0, ele = 0;
    for (int i = 0; i < n; i++){
        if (cnt == 0) ele = nums[i];
        if (nums[i] == ele) cnt++;
        else cnt--;
    }
    return ele;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

}