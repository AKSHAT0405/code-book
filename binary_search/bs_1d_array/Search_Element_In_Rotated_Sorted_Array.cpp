#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int brute(vector<int>& nums, int target)
    {
        for(int i =0; i < nums.size(); i++){
            if(nums[i] == target){
                return i;
            }
        }
        return -1;
    }

    int optimal(vector<int>& nums, int target)
    {
        int n = nums.size();
        int low = 0; int high = n-1;
        while (low <= high)
        {
            int mid = (low + high)/2;
            
            if(nums[mid] == target){
                return mid;
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
    cout << "Enter size of rotated sorted array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    int target;
    cout << "Enter target: ";
    cin >> target;

    Solution obj;
    // int result = obj.brute(nums, target);
    int result = obj.optimal(nums, target);

    if (result != -1)
        cout << "Element found at index: " << result << endl;
    else
        cout << "Element not found." << endl;

    return 0;
}

// brute : tc - O(n) , sc - O(1)
// optimal : tc - O(logn) , sc - O(1)