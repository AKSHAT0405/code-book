#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int recursive(vector<int>& nums, int target, int low, int high)
    {
        int mid = (low+high)/2;
        if(nums[mid] == target){
            return mid;
        }
        else if(low > high){
            return -1;
        }
        else if(mid > low ){
            low = mid+1;
            recursive(nums,target,low,high);
        }
        else{
            high = mid -1;
            recursive(nums,target, low,high);
        }
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
    cout << "Enter element to search: ";
    cin >> target;

    Solution obj;

    int result = obj.recursive(nums, target, 0, n - 1);

    if (result != -1)
        cout << "Element found at index: " << result << endl;
    else
        cout << "Element not found." << endl;

    return 0;
}
// Time Complexity: O(log n)
// Space Complexity: O(1)

// for overflow case where max element is int max ,, we take mid = low + (high - low)/2 
//  it finds mid and also prevent from overlfow of memory in varaible due to (INT_MAX+INT_MAX)
//  either we use this or use long long for low , high and mid. 