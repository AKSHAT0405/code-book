#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> brute(vector<int>& nums, int target)
    {
        for(int i = 0; i< nums.size(); i++){
            for(int j = i+1; j<nums.size(); j++){
                if(nums[i]+nums[j] == target){
                    return {i , j};
                }
            }
        }
    return {-1 , -1};
    }
    vector<int> better(vector<int>& nums, int target){
        map <long , long> mpp;
        for (int i = 0; i < nums.size(); i++)
        {
            int rem = target - nums[i];
            if(mpp.find(rem) != mpp.end()){
                return { mpp[rem] , i };
            }
            mpp[nums[i]] = i;
            
        }
        return {-1,-1};
    }
    string optimal(vector<int>& nums, int target){
        int left = 0; int right = nums.size()-1;
        sort(nums.begin() , nums.end());
        while(left<right){
            int sum = nums[left] + nums[right];
            if(sum == target){
                return "YES";
            }
            else if (sum < target) left++;   // moving from left increase to match target
            else right--;           // if got bigger then we move nums[j] to right to reduce .. 
        }
        return "NO";
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

    int target;
    cout << "Enter target sum: ";
    cin >> target;

    Solution obj;
    // vector<int> result = obj.brute(nums, target);
    // vector<int> result = obj.better(nums, target);
    string result = obj.optimal(nums, target);

    if (result.empty())
    {
        cout << "No valid pair found." << endl;
    }
    else
    {
        cout << "Indices: ";
        for (auto index : result)
            cout << index << " ";
        cout << endl;
    }

    return 0;
}

// brute : tc - O(n^2) , sc - O(1)
// brute : tc - O(n*logn) {ordered} OR tc - O(n)/O(n^2) { worst unordered }, sc - O(n)     
// optimal[greedy] : tc - O(n) + O(nlogn), sc - O(1)    // downfall is if we want the index of result here then we need another hashmap to store key index