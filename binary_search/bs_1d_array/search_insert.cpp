#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search_insert(vector<int>& nums, int target)
    {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int ans = n;
        while (low <= high)
        {
            int mid = (low + high)/2;
            if(nums[mid] >= target){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};

int main()
{
    int n;
    cout << "Enter size of sorted array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter " << n << " sorted elements: ";
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    int target;
    cout << "Enter target: ";
    cin >> target;

    Solution obj;
    int result = obj.search_insert(nums, target);

    cout << "Insert position: " << result << endl;

    return 0;
}