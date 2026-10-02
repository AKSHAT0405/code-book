#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int brute(vector<int>& nums, int k)
    {
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] <= k){
                k++;
            } 
            else{
                break;
            } 
        }
        return k;
    }

    int optimal(vector<int>& arr, int k)
    {
        int low = 0; int high = arr.size()-1;
        while(low <= high){
            int mid = low + (high - low)/2;
            int missing  = arr[mid] - (mid+1);
            if(missing<k) low = mid+1;
            else high = mid - 1;
        } 
        return low + k;
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

    int k;
    cout << "Enter k: ";
    cin >> k;

    Solution obj;

    int result = obj.brute(nums, k);

    cout << "Kth missing positive number: " << result << endl;

    return 0;
}

// brute : tc - O(n) , sc - O(1)
// optimal : tc - O(log2n) , sc - O(1)