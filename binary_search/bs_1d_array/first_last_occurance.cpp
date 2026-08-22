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

    pair<int, int> optimal(vector<int>& nums, int target)
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

    int firstOccurrence(vector<int> &nums, int n, int x) {
        int low = 0, high = n - 1;
        int first = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] == x) {
                first = mid;
                high = mid - 1; 
            } else if (nums[mid] < x) {
                low = mid + 1; 
            } else {
                high = mid - 1;
            }
        }
        return first;
    }
    int lastOccurrence(vector<int> &nums, int n, int x) {
        int low = 0, high = n - 1;
        int last = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] == x) {
                last = mid;
                low = mid + 1; 
            } else if (nums[mid] < x) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return last;
    }

    pair<int, int> manual_binary_search(vector<int> &nums, int k) {
        int n = nums.size();
        int first = firstOccurrence(nums, n, k);
        if (first == -1) {
            return {-1, -1}; 
        }
        int last = lastOccurrence(nums, n, k);
        return {first, last};
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
    // pair<int, int> result = obj.optimal(nums, target);
    // pair<int, int> result = obj.manual_binary_search(nums, target);

    cout << "First occurrence: " << result.first << endl;
    cout << "Last occurrence: " << result.second << endl;

    return 0;
}

//  brute : tc - O(n) , sc - (1)
//  optimal : tc - 2*O(n) -- base 2  , sc - (1)
//  manual binary search -- is for interviews when interviewer wants manual use of binary search
//  and he is not satisfied by stl library of lower and upper bound
