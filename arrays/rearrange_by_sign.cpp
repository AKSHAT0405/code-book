#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> brute(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> pos;
        vector<int> neg;
        vector<int> res(n,0);
        int pos_index = 0;
        int neg_index = 1;
        for(int i = 0; i < n; i++){
            if(nums[i] > 0){
                pos.push_back(nums[i]);
                res[pos_index] = nums[i];
                pos_index += 2;
            }
            else{
                neg.push_back(nums[i]);
                res[neg_index] = nums[i];
                neg_index += 2;
            }
        }
        return res;
    }
    vector<int> optimal(vector<int>& nums){
        int n = nums.size();
        vector<int> res(n,0);
        int pos_index = 0;
        int neg_index = 1;
        for(int i = 0; i < n; i++){
            if(nums[i] < 0){
                res[neg_index] = nums[i];
                neg_index += 2;
            }
            else{
                res[pos_index] = nums[i];
                pos_index += 2;
            }
        }
        return res;
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
    vector<int> result = obj.brute(nums);

    cout << "Rearranged array: ";
    for (int x : result)
        cout << x << " ";

    cout << endl;

    return 0;
}
// brute : tc - O(n)+O(n) , sc - O(n)
// optimal : tc - O(n) , sc - O(n)
