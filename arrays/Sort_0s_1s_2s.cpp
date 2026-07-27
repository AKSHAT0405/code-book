#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void brute(vector<int>& nums)
    {
        int count0 = 0;
        int count1 = 0;
        int count2 = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 0){
                count0++;
            }
            else if(nums[i] == 1){
                count1++;
            }
            else{
                count2++;
            }
        }
        for (int i = 0; i < count0; i++)
        {
            nums[i] = 0;
        }
        for (int j = count0; j < count0+count1; j++)
        {
            nums[j] = 1;
        }
        for (int k = count0+count1; k < count0+count1+count2; k++)
        {
            nums[k] = 2;
        }
    }
    void optimal(vector<int>& nums){
        int n = nums.size();
        int low = 0;
        int mid = 0;
        int high = n-1;

        while(mid <= high){
            if(nums[mid] == 0){
                swap(nums[low] , nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid] ==1){
                mid++;
            }
            else{
                swap(nums[mid] , nums[high]);
                high--;
            }
        }
    }
};

int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter " << n << " elements (0, 1, or 2): ";
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    Solution obj;
    // obj.brute(nums);
    obj.optimal(nums);

    cout << "Sorted array: ";
    for (int x : nums)
        cout << x << " ";

    cout << endl;

    return 0;
}

//  brute : tc - O(2n) , sc - O(1)
//  optimal {3 pointer}: tc - O(n) , sc - O(1)
//  optimal -- dutch national flag algoroithm , 3 pointer 