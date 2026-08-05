#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool linear_search(vector<int> &nums , int num){
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(num == nums[i]){
                return true;
            }
        }
        return false;
    }
public:
    int brute(vector<int>& nums)
    {
        int largest = 1;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            int x = nums[i];
            int cnt = 1;
            while(linear_search(nums , x+1) == true){
                x += 1;
                cnt += 1;
            }
            largest = max(largest , cnt);
        }
        return largest;
    }
    int better(vector<int>& nums){
        if(nums.size() == 0) return 0;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int last_smaller = INT_MIN;
        int cnt = 0;
        int longest = 1;
        for(int i = 0; i < n; i++){
            if(nums[i]-1 == last_smaller){
                last_smaller = nums[i];
                cnt++;
            }
            else if(nums[i] != last_smaller){
                cnt = 1;
                last_smaller = nums[i];
            }
            longest = max(longest , cnt);
       }
       return longest;
    }
    int optimal(vector<int>& nums){
        if(nums.size() == 0) return 0;
        int n = nums.size();
        int longest = 1;
        unordered_set<int> st;
        for(int i = 0; i <n; i++){
            st.insert(nums[i]);
        }
        for(auto it : st){
            if(st.find(it-1) == st.end()){
                int cnt = 1;
                int x = it;
                while(st.find(x+1) != st.end()){
                    x += 1;
                    cnt+=1;
                }
                longest = max(longest , cnt);
            }
        }
        return longest;
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
    // int result = obj.better(nums);
    int result = obj.optimal(nums);

    cout << "Length of longest consecutive sequence: " << result << endl;

    return 0;
}

// brute : tc - O(n^2) , sc - O(1)
// better : tc - O(n)+ O(nlogn), sc - O(1)
// optimal : tc - O(n) + O(2n) ==> O(3n) ,  sc - O(n)