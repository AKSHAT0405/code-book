#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void brute(vector<int>& nums)
    {
        int count = 0;
        vector<int> temp;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] != 0){
                temp.push_back(nums[i]);
            }
        }
        int m = temp.size();
        for (int i = 0; i < m; i++)
        {
            nums[i] = temp[i];
        }
        cout<<endl;
        for (int i = m; i < n ; i++)
        {
            nums[i] = 0;
        }
    }
    void optimal(vector<int>& nums)
    {
        int n = nums.size();
        int j = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] != 0)
            {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                j++;
            }
        }
    }
};

int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++){
        cin >> nums[i];
    }

    Solution obj;
    // obj.brute(nums);
    // obj.optimal(nums);

    cout << "Array after operation: ";
    for (int x : nums)
        cout << x << " ";

    cout << endl;

    return 0;
}

// brute: tc - o(2n) , sc - o(m)
// optimal: tc - o(n) , sc - o(1)