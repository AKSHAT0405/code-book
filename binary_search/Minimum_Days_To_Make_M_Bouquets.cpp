#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool possible(vector<int>& bloomDay, int day, int m, int k)
    {
        int flowers = 0;
        int bouquets = 0;
        for(int bloom : bloomDay)
        {
            if(bloom <= day)
            {
                flowers++;
                if(flowers == k)
                {
                    bouquets++;
                    if(bouquets >= m) return true;
                    flowers = 0;
                }
            }
            else
            {
                flowers = 0;
            }
        }
        return false;
    }

    int brute(vector<int>& bloomDay, int m, int k)
    {
        int n = (int)bloomDay.size();
 
        if ((long long)m * k > n) {
            return -1;
        }
        int minDay = *min_element(bloomDay.begin(), bloomDay.end());
        int maxDay = *max_element(bloomDay.begin(), bloomDay.end());
        for(int i = minDay; i <= maxDay; i++){
            if(possible(bloomDay , i , m , k)){
                return i;
            }
        }
        return -1;
    }


    int optimal(vector<int>& bloomDay, int m, int k) {
        if ((long long)m * k > bloomDay.size())
            return -1;
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (possible(bloomDay, mid, m, k)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};

int main()
{
    int n;
    cout << "Enter number of flowers: ";
    cin >> n;

    vector<int> bloomDay(n);

    cout << "Enter bloom days of " << n << " flowers: ";
    for (int i = 0; i < n; i++)
        cin >> bloomDay[i];

    int m, k;

    cout << "Enter number of bouquets: ";
    cin >> m;

    cout << "Enter flowers needed per bouquet: ";
    cin >> k;

    Solution obj;

    int result = obj.brute(bloomDay, m, k);
    // int result = obj.optimal(bloomDay, m, k);

    if (result == -1)
        cout << "Impossible to make bouquets." << endl;
    else
        cout << "Minimum days: " << result << endl;

    return 0;
}

// let D = high - low + 1
// brute : tc - O(D*N) , sc - O(1)
// optimal : tc - O(log2D*N) , sc - O(1)