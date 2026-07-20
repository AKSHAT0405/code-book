#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> brute(vector<int>& nums1, vector<int>& nums2)
    {
        set<int> st;
        int s1 = nums1.size();
        int s2 = nums2.size();
        for (int i = 0; i < s1; i++)
        {
            st.insert(nums1[i]);
        }
        for (int j = 0; j < s2; j++)
        {
            st.insert(nums2[j]);
        }
        int n = st.size();
        vector<int> result(n);
        int k = 0;
        for(auto it:st){
            result[k++] = it;
        }
        return result;
    }
    vector<int> optimal(vector<int>& nums1, vector<int>& nums2)
    {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int> unionArr;
        int i = 0;
        int j = 0;
        while (i<n1 && j<n2)
        {
            if(nums1[i]<=nums2[j]){
                if(unionArr.size() == 0 || unionArr.back() != nums1[i]){
                    unionArr.push_back(nums1[i]);
                }
                i++;
            }
            else{
                if(unionArr.size() == 0 || unionArr.back() != nums2[j]){
                    unionArr.push_back(nums2[j]);
                    }
                    j++;
                }  
        }
        while(i<n1){
            if(unionArr.size() == 0 || unionArr.back() != nums1[i]){
                unionArr.push_back(nums1[i]);
            }
            i++;
        }
        while (j<n2)
        {
            if(unionArr.size() == 0 || unionArr.back() != nums2[j]){
            unionArr.push_back(nums2[j]);
            }  
            j++;
        }
        return unionArr;
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
    // vector<int> result = obj.brute(nums1, nums2);
    vector<int> result = obj.optimal(nums1, nums2);

    cout << "Union of arrays: ";
    for (int x : result)
        cout << x << " ";

    cout << endl;

    return 0;
}

// brute : tc-o(s1logn + s2logn) + o(n1+n2)  ,  sc - o(n1+n2) + o(n1+n2) ---[extra o(n1+n2)used to return answer]
// optimal : tc- o(n1+n2) , sc - o(n1+n2) ---[extra o(n1+n2)used to return answer]