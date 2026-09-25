#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int brute(vector<int>& nums)
    {
        int ans = nums[0];
        for (int i = 0; i < nums.size(); i++)
        {
            if(nums[i] < ans){
                ans = nums[i];
            }
        }
        return ans;
    }

    int my_approach(vector<int>& nums)
    {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int mini = nums[0];
        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] < mini){
                mini = nums[mid];
            }
            if(nums[low] > nums[mid] && nums[high] > nums[mid]){
                if(nums[low] > nums[high]){
                    high = mid - 1;
                }
                else {
                    low = mid + 1; 
                }
            }
            else{
                if(nums[high] < nums[low]){
                    low = mid +1;
                }
                else{
                    high = mid -1;
                }
            }
        }
    }

    int optimal(vector<int>& nums)
    {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int mini = INT_MAX;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] < mini){
                mini = nums[mid];
            }
            if(nums[low] <= nums[mid]){
                if(nums[low] < mini){
                    mini = nums[low];
                }
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return mini;
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

    Solution obj;

    // int result = obj.brute(nums);
    // int result = obj.my_approach(nums);
    int result = obj.optimal(nums);

    cout << "Minimum element: " << result << endl;

    return 0;
}

// brute : tc - O(n) , sc - O(1)
// optimal : tc - O(log2n) , sc - O(1)