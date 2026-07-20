#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> brute(vector<int>& nums1, vector<int>& nums2)
    {
        vector<int> result;
        int n = nums1.size();
        int m = nums2.size();
        int visited[m] = {0};
        for (int i = 0; i < n; i++)
        {
            for(int j = 0; j<m;j++){
                if(nums1[i] == nums2[j] && visited[j] == 0){
                    result.push_back(nums1[i]);
                    break;
                }
                if(nums2[j] > nums1[i])
                break;
            }
        }
        return result;
    }
    vector<int> optimal(vector<int>& nums1, vector<int>& nums2)
    {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int> ans;
        int i = 0;
        int j = 0;
        while (i<n1 && j<n2)
        {
            if(nums1[i]<nums2[j]){
                i++;
            }
            else if(nums1[i]>nums2[j]){
                j++;
            }
            else{
                ans.push_back(nums1[i]);
                i++;
                j++;
            }
        }
        return ans;
    }
};


int main()
{
    int n1;
    cout << "Enter size of first array: ";
    cin >> n1;
    vector<int> nums1(n1);
    cout << "Enter " << n1 << " elements: ";
    for (int i = 0; i < n1; i++)
        cin >> nums1[i];

    int n2;
    cout << "Enter size of second array: ";
    cin >> n2;
    vector<int> nums2(n2);
    cout << "Enter " << n2 << " elements: ";
    for (int i = 0; i < n2; i++)
        cin >> nums2[i];

    Solution obj;
    vector<int> result = obj.brute(nums1, nums2);
    // vector<int> result = obj.optimal(nums1, nums2);

    cout << "Intersection of arrays: ";
    for (int x : result)
        cout << x << " ";

    cout << endl;

    return 0;
}

// brute : tc-o(n1xn2)  ,  sc - o(n2) 
// optimal : tc- o(n1+n2) , sc - o(1) 
//  here result of intersected array can have repeating element unlike union.
