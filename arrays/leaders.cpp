#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> brute(vector<int>& nums)
    {
        vector<int> leaders;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            int flag = 1;
            for(int j = i+1; j < n; j++){
                if(nums[j] > nums[i]){
                    flag = 0;
                    break;
                }
            }
            if(flag == 1){
                leaders.push_back(nums[i]);
            }
        }
        return leaders;
    }
    vector<int> optimal(vector<int>& nums){
    int n = nums.size();
    vector<int> leaders;
    int leader = nums[n-1];
    for(int i = n-2; i >= 0; i--){
        if(nums[i] > leader){
            leaders.push_back(nums[i]);
            leader = nums[i];
        }
    }
    reverse(leaders.begin() , leaders.end());
    leaders.push_back(nums[n-1]);
    return leaders;
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
    // vector<int> result = obj.brute(nums);
    vector<int> result = obj.optimal(nums);

    cout << "Leaders: ";
    for (int x : result)
        cout << x << " ";

    cout << endl;

    return 0;
}
// brute : tc - O(n^2) , sc - O(n) { for storing result , not used in main logic }
// brute : tc - O(n) + O(n) { extra O(n) due to reverse of array }
//  sc - O(n) { for storing result , not used in main logic }