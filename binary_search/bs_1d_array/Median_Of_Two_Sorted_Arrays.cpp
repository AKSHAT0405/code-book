#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    float my_brute(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.end(),nums2.begin(),nums2.end());
        sort(nums1.begin() , nums1.end());
        int mid = nums1.size()/2;
        double ans = -1;
        if((nums1.size())%2 != 0){
            ans = nums1[mid];
        }
        else{
            ans = (nums1[mid-1] + nums1[mid])/2.00;
        }
        return ans;
    }

    double optimal(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return optimal(nums2, nums1);
        }
 
        int n = nums1.size();
        int m = nums2.size();
 
        int leftSize = (n + m + 1) / 2;
 
        int low = 0;
        int high = n;
 
        while (low <= high) {
            int cut1 = low + (high - low) / 2;
 
            int cut2 = leftSize - cut1;
 
            int left1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
 
            int right1 = (cut1 == n) ? INT_MAX : nums1[cut1];
 
            int left2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
 
            int right2 = (cut2 == m) ? INT_MAX : nums2[cut2];
 
            if (left1 <= right2 && left2 <= right1) {
                if ((n + m) % 2 == 1) {
                    return max(left1, left2);
                } else {
                    return (
                        (double)max(left1, left2) +
                        min(right1, right2)
                    ) / 2.0;
                }
            } else if (left1 > right2) {
                high = cut1 - 1;
            } else {
                low = cut1 + 1;
            }
        }
        return 0.0;
    }

};

int main() {
    int n, m;

    cout << "Enter size of first array: ";
    cin >> n;

    vector<int> nums1(n);

    cout << "Enter first sorted array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums1[i];
    }

    cout << "Enter size of second array: ";
    cin >> m;

    vector<int> nums2(m);

    cout << "Enter second sorted array: ";
    for (int i = 0; i < m; i++) {
        cin >> nums2[i];
    }

    Solution obj;

    cout << "Brute: " << obj.my_brute(nums1, nums2) << endl;
    // cout << "Better: " << obj.better(nums1, nums2) << endl;
    // cout << "Optimal: " << obj.optimal(nums1, nums2) << endl;

    return 0;
}

// my _brute : tc - O((n+m)*log(n+m)) , tc - O(log(n+m))​ due to recursion stack 
// optimal : tc - O(log(min(N, M)))