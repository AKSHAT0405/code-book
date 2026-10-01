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

    int better(vector<int>& nums, int k)
    {
        // Write your better solution here
        return -1;
    }

    int optimal(vector<int>& nums, int k)
    {
        // Write your optimal solution here
        return -1;
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