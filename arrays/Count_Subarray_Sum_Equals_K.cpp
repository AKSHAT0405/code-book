#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int brute(vector<int>& nums, int k)
    {
        int n = nums.size();
        int count = 0;
        for(int i = 0; i < n; i++){
            int sum = 0;
            for(int j = i; j < n; j++){
                sum += nums[j];
                if(sum == k){
                    count++;
                }
            }
        }
        return count;
    }

    int optimal(vector<int>& nums, int k)
    {
        int n = nums.size();
        int count = 0;
        int sum = 0;
        map<long , long> mpp;
        mpp[0] = 1;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            int rem = sum - k;
            count += mpp[rem];
            mpp[sum] += 1;
        }
        return count;
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
    cout << "Enter target sum (k): ";
    cin >> k;

    Solution obj;

    int result = obj.brute(nums, k);

    cout << "Number of subarrays with sum " << k << ": "
         << result << endl;

    return 0;
}

// brute : tc - O(n^2) , sc - O(1)
// optimal : tc - O(n*logn) , sc - O(n)
// optimal { use of prefix sum concept and map }