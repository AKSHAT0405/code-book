#include <bits/stdc++.h>
using namespace std;

void solve(vector<int>& nums)
{
    int ans = 0;

    for (int i = 0; i < nums.size(); i += 2)
    {
        ans = ans^nums[i];
    }

    cout << ans << endl;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> nums(n);

        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }

        solve(nums);
    }

    return 0;
}