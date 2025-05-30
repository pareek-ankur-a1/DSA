// T.C = O(n1 + n2)
#include <bits/stdc++.h>
using namespace std;

vector<int> findUnion(vector<int> &a, vector<int> &b)
{
    int n1 = a.size();
    int n2 = b.size();
    vector<int> temp;
    int i = 0, j = 0;
    while (i < n1 && j < n2)
    {
        if (a[i] <= b[j])
        {
            if (temp.size() == 0 || temp.back() != a[i])
            {
                temp.push_back(a[i]);
            }
            i++;
        }
        else
        {
            if (temp.size() == 0 || temp.back() != b[j])
            {
                temp.push_back(b[j]);
            }
            j++;
        }
    }
    while (i < n1)
    {
        if (temp.back() != a[i])
        {
            temp.push_back(a[i]);
        }
        i++;
    }
    while (j < n2)
    {
        if (temp.back() != b[j])
        {
            temp.push_back(b[j]);
        }
        j++;
    }
    return temp;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}