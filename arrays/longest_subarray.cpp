#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int brute(vector<int>& nums, int k)
    {
        int count = nums.size();
        int maxi;
        for (int i = 0; i < count; i++)
        {
            int sum = nums[i];
            for (int j = i+1; j < count; j++)
            {
                sum += nums[j];
                if(sum == k){
                    maxi = (j-i+1);
                    break;
                }
            }
        }
        return maxi;
    }
    int better_with_hash(vector<int>& nums, int k){    //  dry run to understand with example
        int max_len = 0;                   // example : nums = [2, -1, 2, 0, 3, -2, 4], k = 4
        map<long long, int> presum_map;
        long long sum = 0;
        for(int i = 0;i<nums.size();i++){
            sum += nums[i];     // total sum  
            if(sum == k){
                max_len = max(max_len , i+1); 
            }
            int rem = sum - k;    // remaining 
            if(presum_map.find(rem) != presum_map.end()){  // map.end represent the output when search fails(invalid element)
                int len = i - presum_map[rem];        // if we got (rem) in our map then we find index of that (rem) sum
                max_len = max(max_len , len);    
            }
            if(presum_map.find(sum) == presum_map.end()){ // check if there was already the sum to avoid identical sum having zero . 
                presum_map[sum] = i;    // only input data if above condiiton fullfills 
            }
        }
        return max_len;
    }
    int optimal(vector<int>& nums, int k){
        int max_len = 0;
        long long sum = nums[0];
        int left = 0;
        int right = 0;
        int n = nums.size();
        while(right < n){
            while(left <= right && sum > k){
                sum -= nums[left];
                left++;
            }
            if(sum == k){
                max_len = max(max_len , right-left + 1);
            }
            right++;
            if(right<n) sum += nums[right];
        }
        return max_len;
    }
};

int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter " << n << " positive elements: ";
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    int k;
    cout << "Enter target sum (k): ";
    cin >> k;

    Solution obj;
    // int result = obj.brute(nums, k);
    // int result = obj.better_with_hash(nums, k);
    int result = obj.optimal(nums, k);

    cout << "Length of longest subarray: " << result << endl;

    return 0;
}

//  brute : tc - O(n^2) , sc - O(1)

/*   better_with_hash : 
  -> tc - O(nlogn)             {for ordered}
  -> tc - O(n)                 {for unordered and less or no collision}
  -> (worst) tc - O(n^2)       {for unordered and collisions} 
  -> sc - O(n) */

/* optimal{greedy ,sliding window and two pointer} : {for positives and zeros array only}
   tc - O(2n)     { right moves for n and left too moves internally for n only so n+n not n^2}
   sc - O(1) */ 

/* the better was a beautiful use of [map data structure] to fetch index from given rem variable ,use 
of maths the problem I got further in hash was getting longest subarray for array including zeros.*/

/* presum_map.end() is a special iterator that represents “one past the last element” in the map. 
  It doesn’t point to any valid element; instead, it’s used as a sentinel to indicate that a search 
  failed.*/

