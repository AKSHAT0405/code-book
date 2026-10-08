#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int brute(vector<int>& nums){
        int n = nums.size();
        if(n == 1){
            return 0;
        }
        if(nums[0] > nums[1]){
            return 0;
        }
        if(nums[n-1] > nums[n-2]){
            return n-1;
        }
        for(int i = 1; i < nums.size()-1; i++){
            if(nums[i] > nums[i + 1] && nums[i] > nums[i - 1]){
                return i;
            }  
        }
        return -1;
    }
    int optimal(vector<int>& nums) {
        int n = nums.size();
        int low = 1; 
        int high = nums.size() - 2;
        if(n == 1){
            return 0;
        }
        if(nums[0] > nums[1]){
            return 0;
        }
        if(nums[n-1] > nums[n-2]){
            return n-1;
        }
        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] > nums[mid + 1] && nums[mid] > nums[mid - 1]){
                return mid;
            }
            else if(nums[mid] < nums[mid + 1]){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return -1; 
    }
};

int main() {
    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;

    cout << "Brute: " << obj.brute(nums) << endl;
    cout << "Optimal: " << obj.optimal(nums) << endl;

    return 0;
}