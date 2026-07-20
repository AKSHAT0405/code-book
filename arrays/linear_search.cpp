#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target)
    {
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if (nums[i] == target){
                return i;
            }
        }
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

    int target;
    cout << "Enter target element: ";
    cin >> target;

    Solution obj;
    int result = obj.search(nums, target);

    if (result != -1)
        cout << "Element found at index: " << result << endl;
    else
        cout << "Element not found." << endl;

    return 0;
}

// tc : o(n) , sc : o(1)