#include <bits/stdc++.h>
using namespace std;

void solve(vector<int>& nums)
{
    int n = nums.size();
    for(int i = 0; i < n; i++){
        int x = nums[i];
        int xorr = 0;
        for(int j = 0; j<n; j++){
            if(j != i){
                xorr = xorr^nums[j];
            }
        }
        if(xorr == x){
            cout<<x<<endl;
            break;
        }
    }
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

// codeforces problem - 1698A