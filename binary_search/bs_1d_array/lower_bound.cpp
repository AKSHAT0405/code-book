#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solution(vector<int>& nums, int target)
    {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int ans = n;
        while (low <= high)
        {
            int mid = (low + high)/2;
            if(nums[mid] >= target){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
    int stl_approach(vector<int>& nums, int target){
        int lb = lower_bound(nums.begin(),nums.end(),target) - nums.begin();
        return lb;
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

    // int result = obj.solution(nums, target);
    int result = obj.stl_approach(nums, target);

    cout << "Lower bound index: " << result << endl;

    return 0;
}
// tc = O(logn) -- base 2
// sc - O(1)
// we can also use inbuild stl library so find lower bound element which return answer if find else return size
// we can also implement the search in restricted index for low and high by manipulating nums.begin and end