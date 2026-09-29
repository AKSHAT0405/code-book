#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumByD(vector<int>& nums, int div){
        int sum = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            sum += ceil((double)(nums[i])/(double)(div));
        }
        return sum;
    }
    int brute(vector<int>& nums, int threshold)
    {
        int n = nums.size();
        if(n>threshold){
            return -1;
        }
        int M = *max_element(nums.begin() , nums.end());
        for(int d = 1; d<= M;d++){
            int sum = 0;
            for (int i = 0; i < n; i++)
            {
                sum += ceil((double)(nums[i])/(double)(d));
            }
            if(sum <= threshold){
                return d;
        }
            
        }
        return -1;
    }


    int optimal(vector<int>& nums, int threshold)
    {
        int n = nums.size();
        if(n>threshold){
            return -1;
        }
        int low = 1;
        int high = *max_element(nums.begin() , nums.end());
        while(low <= high){
            int mid = low +(high - low)/2;
            if(sumByD(nums,mid) <= threshold){
                high = mid-1;
            }
            else{
                low = mid+1;
            }

        }
        return low;
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

    int threshold;
    cout << "Enter threshold: ";
    cin >> threshold;

    Solution obj;

    int result = obj.brute(nums, threshold);
    // int result = obj.optimal(nums, threshold);

    cout << "Smallest divisor: " << result << endl;

    return 0;
}

// brute : tc - O(N*M) , sc - O(1)
// optimal : tc - O(N * log2(Max)) , sc - O(1)