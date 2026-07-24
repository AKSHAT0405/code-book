#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int brute(vector<int>& nums){
        for(int i = 0;i<nums.size();i++){
            int cnt = 0;
            for(int j = 0; j < nums.size(); j++){
                if(nums[j] == nums[i]){
                    cnt++;
                }
            }
            if(cnt == 1){
                return nums[i];
            }
        }
    }

    int better_hash(vector<int>& nums){
        int maxi = nums[0];
        vector<int> hash;
        for(int i = 0; i< nums.size(); i++){
            maxi = max(maxi , nums[i]);
            hash[maxi] = 0;
        }
        for(int j = 0; j< nums.size(); j++){
            hash[nums[j]]++;
        }
        for(int j = 0; j< nums.size(); j++){
            if(hash[nums[j]] == 1){
                return nums[j];
            }
        }
    }
    int better_map(vector<int>& nums){
        map<int, int> newmap;
        for (int i = 0; i < nums.size(); i++)
        {
            newmap[nums[i]]++;
        }
        for(auto it:newmap){
            if(it.second == 1){
                return it.first;  
            }
        }  
    }
    int optimal(vector<int>& nums)
    {
        int missy = 0;
        for(int i = 0; i < nums.size(); i++){
            missy = missy^nums[i];
        }
        return missy;
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
    // int result = obj.optimal(nums);
    // int result = obj.better_hash(nums);
    int result = obj.better_map(nums);

    cout << "Single element: " << result << endl;

    return 0;
}

// brute : tc = O(n^2) , sc = O(1)
// better_hash : tc = O(3n) , sc = O(n)
// better_map : tc = O(nlogm)+ O((n/2)+1) { this is for ordered map , m - size of map} , sc = o((n/2)+1)
// optimal : tc = O(n) , sc = O(1)
// got problem in hashmap and finding complexities in map . 