#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    pair<int, int> brute(vector<int>& nums, int target)
    {
        int start = -1;
        int end = -1;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] == target){
                if(start == -1){
                    start = i;
                    end = i;
                }
                end = i;
            }
        }
        return {start , end };
    }

    pair<int, int> better(vector<int>& nums, int target)
    {
        int n = nums.size();
        int x = lower_bound(nums.begin(),nums.end() , target) - nums.begin();
        int y = upper_bound(nums.begin() , nums.end() , target) - nums.begin();
        if(x == n || nums[x] != target){
            return {-1,-1};
        }
        else{
            return {x , y-1};
        }
    }

    pair<int, int> optimal(vector<int>& nums, int target)
    {
        
        return {-1, -1};
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
    cout << "Enter target: ";
    cin >> target;

    Solution obj;
    pair<int, int> result = obj.brute(nums, target);

    cout << "First occurrence: " << result.first << endl;
    cout << "Last occurrence: " << result.second << endl;

    return 0;
}

//  brute : tc - O(n) , sc - (1)
//  better : tc - 2*O(n) -- base 2  , sc - (1)
