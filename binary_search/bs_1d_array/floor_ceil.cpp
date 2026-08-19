#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x) {
        int low1 = 0; int high1 = n-1;
        int low2 = 0; int high2 = n-1;
        int floor = -1; int ceil = -1;
        while(low1 <= high1){
            int mid1 = (low1 + high1)/2;
            if(a[mid1] <= x){
                floor = a[mid1];
                low1 = mid1+1;
            }
            else{
                high1 = mid1-1;
            }
        }
        while(low2 <= high2){
            int mid2 = (low2 +high2)/2;
            if(a[mid2] >= x){
                ceil = a[mid2];
                high2 = mid2-1;
            }
            else{
                low2 = mid2+1;
            }
        }
        return {floor,ceil};
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
    pair<int, int> result = obj.getFloorAndCeil(nums,n,target);

    cout << "Floor: " << result.first << endl;
    cout << "Ceil: " << result.second << endl;

    return 0;
}