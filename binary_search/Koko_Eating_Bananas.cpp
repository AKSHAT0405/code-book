#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long sumByD(vector<int>& nums, long div){
        int n = nums.size();
        long long sum = 0;
        for(int i = 0; i<n; i++){
            sum += (nums[i] + div - 1) / div;
        }
        return sum;
    }

    int brute(vector<int>& piles, int h)
    {
        int M = *max_element(piles.begin(), piles.end());
        for(int k = 1; k <= M; k++)
        {
            long long hours = sumByD(piles , k);
            if(hours <= h)
            {
                return k; 
            }
        }
        return -1;
    }

    long optimal(vector<int>& piles, int h) {
        long n = piles.size();
        long ans = -1;
        long low = 1;
        long high = *max_element(piles.begin() , piles.end());
        while(low <= high){
            long mid = low + (high - low)/2;
            if(sumByD(piles,mid) <= h){
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans; 
    }
};

int main()
{
    int n;
    cout << "Enter number of piles: ";
    cin >> n;

    vector<int> piles(n);

    cout << "Enter " << n << " pile sizes: ";
    for (int i = 0; i < n; i++)
        cin >> piles[i];

    int h;
    cout << "Enter hours: ";
    cin >> h;

    Solution obj;

    int result = obj.optimal(piles, h);

    cout << "Minimum eating speed: " << result << endl;

    return 0;
}

// brute : tc - O(M*N) , sc - O(1)
// brute : tc - O(n*log2high) , sc - O(1)
