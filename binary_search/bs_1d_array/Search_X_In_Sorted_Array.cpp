#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int binary_search(vector<int>& nums, int target)
    {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        while(low <= high){
            int mid = (low + high)/2;
            if(nums[mid] == target){
                return mid;
            }
            else if(target < nums[mid]){
                high = mid -1;
            }
            else{
                low = mid+1;
            }
        }
        return -1;
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

    int result = obj.binary_search(nums, target);

    if (result != -1)
        cout << "Element found at index: " << result << endl;
    else
        cout << "Element not found." << endl;

    return 0;
}
// Time Complexity: O(log n)
// Space Complexity: O(1)

/*  You start with the whole array of size 𝑛.
    Each iteration of the while loop cuts the search space in half (low to high shrinks by ~50%).
    After the first step → size 𝑛/2, then 𝑛/4, then 𝑛/8, and so on.
    This continues until the search space becomes 1 element.
    Mathematically, the number of iterations is about:
    log(base 2)𝑛
    So the time complexity is:𝑂(log𝑛) */