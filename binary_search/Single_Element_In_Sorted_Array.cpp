#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int brute(vector<int>& nums)
    {
        int elem = 0;
        for(int i = 0; i < nums.size(); i++){
            elem = elem^nums[i];
        }
        return elem;
    }

    int my_approach(vector<int>& nums)
    {
        int n = nums.size();
        if(n == 1){
            return nums[0];
        }
        if(nums[0] != nums[1]){
            return nums[0];
        }
        if(nums[n-1] != nums[n-2]){
            return nums[n-1];
        }
        int low  = 1;
        int high = n-2;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(mid%2 == 0){
                if(nums[mid] == nums[mid-1]){
                    high = mid - 2;
                }
                else if(nums[mid] == nums[mid+1]){
                    low = mid+2;
                }
                else{
                    return nums[mid];
                }
            }
            else{
                if(nums[mid] == nums[mid-1]){
                    low = mid +1;
                }
                else if(nums[mid] == nums[mid + 1]){
                    high = mid - 1;
                }
                else{
                    return nums[mid];
                }
            }
        }
        return -1;
    }

    int optimal(vector<int>& nums)
    {
        int n = nums.size();
        if(n == 1){
            return nums[0];
        }
        if(nums[0] != nums[1]){
            return nums[0];
        }
        if(nums[n-1] != nums[n-2]){
            return nums[n-1];
        }
        int low  = 1;
        int high = n-2;
        while(low <= high){
            int mid = low + (high - low)/2;
            
            if(nums[mid] != nums[mid -1] && nums[mid] != nums[mid+1]){
                return nums[mid];
            }

            if((mid%2 == 1 && nums[mid] == nums[mid-1]) || (mid%2 == 0 && nums[mid] == nums[mid+1]) ){
                low = mid + 1;
            }
            else{
                high = mid - 1;
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

    Solution obj;

    // int result = obj.brute(nums);
    int result = obj.optimal(nums);

    cout << "Single element: " << result << endl;

    return 0;
}