#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int brute(vector<int>& nums)
    {
        int mini = nums[0];
        int ind = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < mini){
                mini = nums[i];
                ind = i;
            }
        }
        return ind;
    }

    int optimal(vector<int>& nums)
    {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int mini = INT_MAX;
        while (low <= high)
        {
            int mid = low + (high - low)/2;
            mini  = min(mini , nums[mid]);
            if(nums[mid] >= nums[low]){
                mini = min(mini , nums[low]);  
                low = mid + 1;
            }
            else{
                high = mid - 1;              
            }
        }

        int idx = find(nums.begin(), nums.end(), mini) - nums.begin();
        
        return idx;
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
    int result = obj.optimal(nums);

    cout << "Array was rotated " << result << " times." << endl;

    return 0;
}   

// brute : tc - O(n) , sc - O(1)
// optimal : tc - O(log2n) , sc - O(1)