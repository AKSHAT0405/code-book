#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int find_max_1(vector<int>& nums)
    {
        int maxi = 0;
        int counter = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 1){
                counter++;
                maxi = max(maxi , counter);
            }
            else{
                counter = 0;
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

    cout << "Enter " << n << " elements (0s and 1s): ";
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    Solution obj;
    int result = obj.find_max_1(nums);

    cout << "Maximum consecutive 1's: " << result << endl;

    return 0;
}
// tc = o(n) , sc - o(1)
// silly mistake - watching pattern for continous one as zero is exact sign of breaking of continuty
// we can use max() function to find the max rather if else 