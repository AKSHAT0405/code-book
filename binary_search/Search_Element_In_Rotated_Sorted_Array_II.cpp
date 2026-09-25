#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool brute(vector<int>& nums, int target)
    {
        for(int i =0; i < nums.size(); i++){
            if(nums[i] == target){
                return true;
            }
        }
        return false;
    }

    bool optimal(vector<int>& nums, int target)
    {
        int n = nums.size();
        int low = 0; int high = n-1;
        while (low <= high)
        {
            int mid = (low + high)/2;
            
            if(nums[mid] == target){
                return mid;
            }
            else if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
                low = low + 1;
                high = high - 1;
            }
            else if(nums[low] == nums[high]){
                low = low + 1;
                high = high - 1;
                continue;
            }
            else if(nums[low] <= nums[mid]){
                if(target >= nums[low] && target <= nums[mid]){
                    high = mid - 1;
                }
                else{
                    low = mid + 1;
                }
            }
            else{
                if(target >= nums[mid] && target <= nums[high]){
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }
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
    cout << "Enter target: ";
    cin >> target;

    Solution obj;

    // bool result = obj.brute(nums, target);
    bool result = obj.optimal(nums, target);

    if (result)
        cout << "Element found" << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}
// optimal - tc - O(log2n)  best
// TC - O(n/2)   worst