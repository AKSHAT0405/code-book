#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> brute(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> pos;
        vector<int> neg;
        for(int i = 0; i < n; i++){
            if(nums[i] > 0){
                pos.push_back(nums[i]);
            }
            else{
                neg.push_back(nums[i]);
            }
        }
        if(pos.size() > neg.size()){
            for(int j = 0; j < pos.size(); j++){
                nums[j*2] = pos[j];
                nums[j*2+1] = neg[j];
            }
            int index = neg.size()*2;
            for(int k = neg.size(); k < pos.size(); k++){
                nums[index] = pos[k];
                index++;
            }
        }
        else{
            for(int j = 0; j < neg.size(); j++){
                nums[j*2] = pos[j];
                nums[j*2+1] = neg[j];
            } 
            int index = pos.size()*2;
            for(int k = pos.size(); k < neg.size(); k++){
                nums[index] = pos[k];
                index++;
            }
        }
        return nums;
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
// brute : tc - O(n)+O(min(pos.size() , neg.size())  , O(leftovers) ---- O(n) + O(n) = O(2n)
//  sc - O(n)