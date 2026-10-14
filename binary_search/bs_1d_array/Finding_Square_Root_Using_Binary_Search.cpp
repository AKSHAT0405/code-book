#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int brute(int n)
    {
        int ans = 0;
        for(int i = 0; i <= n; i++){
            long long prod = i*i;
            if(prod <= n){
                ans = i;
            }
            else{
                break;
            }
        }
        return ans;
    }

    int optimal(int n)
    {
        int low = 0;
        int high = n;
        int target = 1;
        while(low <= high){
            long mid = (low + high)/2;
            long long prod = mid*mid;
            if(prod <= n){
                target = mid;
                low = mid + 1;
            }
            else{
                high = mid -1;
            }
        }
        return target;
    }
};

int main()
{
    int n;

    cout << "Enter number: ";
    cin >> n;

    Solution obj;

    // int result = obj.brute(n);
    int result = obj.optimal(n);

    cout << "Square root: " << result << endl;

    return 0;
}

// brute : tc - O(n) , sc - O(1)
// optimal : tc - O(log2n) , sc - O(1) 