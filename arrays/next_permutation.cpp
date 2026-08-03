#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> better(vector<int>& nums){
        next_permutation(nums.begin() , nums.end());
        return nums;

    }
    void nextPermutation(vector<int>& nums) {
        int index = -1;

        for (int i = nums.size() - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                index = i;
                break;
            }
        }

        if (index == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        for (int i = nums.size() - 1; i > index; i--) {
            if (nums[i] > nums[index]) {
                swap(nums[i], nums[index]);
                break;
            }
        }

        reverse(nums.begin() + index + 1, nums.end());
    }
};

int main() {
    vector<int> nums = {3,1,2};
    Solution sol;

    // sol.nextPermutation(nums);
    sol.better(nums);

    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

// optimal -  tc - O(3n) , sc - O(1)
// its brute solution find all possible permutation , it take time complexity of very high order of N!xN 
// this is why we will not be using it 
// using in-built stl library { next_permutation } is better sol . 