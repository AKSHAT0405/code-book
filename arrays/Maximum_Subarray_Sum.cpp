#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int brute(vector<int>& nums)
    {
        int n = nums.size();
        int max_sum = nums[0];
        for(int i = 0; i < n; i++ ){
            int sum = 0;
            for(int j = i ; j < n; j++){
                sum += nums[j];
                max_sum = max(max_sum , sum);
            }
        }
        return max_sum;
    }
    int me_before_kadane(vector<int>& nums){
        long n = nums.size();
        long long sum = nums[0];
        long long max_sum = nums[0];
        for(long i = 1; i < n; i++){
            sum += nums[i];
            if(sum  > max_sum){  
                max_sum = sum;
            }
            if(nums[i] > max_sum){    
                sum = nums[i];
                max_sum = nums[i];
            }
            if(nums[i] > 0 && nums[i]> sum){
                sum = nums[i];
            }
        }
        return max_sum;
    }
    int optimal(vector<int>& nums){

        long long maxi = LLONG_MIN; 
        long long sum = 0; 
        int ans_start = -1;
        int ans_end = -1;
        int start;
        
        for (int i = 0; i < nums.size(); i++) {
            if(sum == 0 ){
                start = i;
            }
            
            sum += nums[i]; 
            
            if (sum > maxi) {
                maxi = sum; 
                ans_start = start;
                ans_end = i;
            }
            
            if (sum < 0) {
                sum = 0; 
            }
        }
        return maxi;

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
    // int result = obj.me_before_kadane(nums);
    int result = obj.optimal(nums);

    cout << "Maximum subarray sum: " << result << endl;

    return 0;
}

// Brute : tc - O(n^2) , sc - O(1)
// me_before_kadane : this is my own rough approach before learning kadane . it was not that stable although it passed all tests. 
//  here i though like for a,b if we start from be and if b+a or b is greater then use them as max , also index changing was one as a challange . 
// optimal : tc - O(n) , sc - O(1)  
// optimal { kadane's approach/algorithm }  
