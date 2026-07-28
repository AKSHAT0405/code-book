#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int brute(vector<int>& nums)
    {
        int n = nums.size();
        int limit = int(n/2);
        for(int i = 0; i < n; i++){
            int count = 1;
            for(int j = 0; j < n; j++){
                if(nums[j] == nums[i]){
                    count++;
                }
            }
            if(count > limit){
                return nums[i];
            }
        }
        return -1;
    }
    int better(vector<int>& nums){
       map<int , long> mpp;
        int n = nums.size();
        int limit = int(n/2);
        for (int i = 0; i < n; i++)
        {
            mpp[nums[i]]++;
        }
        for (auto& p : mpp) {
            if (p.second > limit) {
                return p.first;  
            }
        }
        return -1;  
    }
    int optimal(vector<int>& nums){
        int n = nums.size();
        int cnt = 0;
        int el = 0;
        for(int i = 0; i < n; i++){
            if(cnt == 0){
                cnt = 1;
                el = nums[i];
            }
            else if(nums[i] == el){
                cnt++;
            }
            else{
                cnt--;
            }
        }
        int check = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == el){
                check++;
            }
        }
        if(check > int(nums.size()/2)){
            return el;
        }
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

    Solution obj;
    // int result = obj.brute(nums);
    int result = obj.better(nums);

    cout << "Majority element: " << result << endl;

    return 0;
}

// brute : tc - O(n^2) , sc - o(1)
// better : tc - O(nlogn + n) {ordered map}, sc - o(n)
// optimal : tc - O(n) + O(n){considered if question dont state alwars existance of any element}, sc - o(1) 
// optimal { moore's voting algorithm } introduced here.