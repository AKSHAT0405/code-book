#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int brute(vector<int>& nums, int k)
    {
        int num = 1;
        int i = 0;
        while(true)
        {
            if(i < nums.size() && nums[i] == num)
            {
                i++;
            }
            else
            {
                k--;
                if (k == 0)
                return num;
            }
            num++;
        }
    }

    int better(vector<int>& nums, int k)
    {
        // Write your better solution here
        return -1;
    }

    int optimal(vector<int>& nums, int k)
    {
        // Write your optimal solution here
        return -1;
    }
};

int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    int k;
    cout << "Enter k: ";
    cin >> k;

    Solution obj;

    int result = obj.optimal(nums, k);

    cout << "Kth missing positive number: " << result << endl;

    return 0;
}