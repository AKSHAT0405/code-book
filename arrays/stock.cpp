#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int brute(vector<int>& prices)
    {
        int n = prices.size();
        int best = 0;
        for (int i = 0; i < n; i++)
        {
            int check  = 0;
            for(int j = i+1; j < n; j++){
                check = prices[j] - prices[i];
                if (check > best){
                    best = check;
                }
            }
        }
        return best;
    }
    int optimal(vector<int>& prices){
        int n = prices.size();
        int j = 0;
        int best = 0;
        for(int i = 1; i < n; i++){
            if(prices[i] < prices[j]){
                j = i;
            }
            else if(prices[i] - prices[j] > best){
                best = prices[i] - prices[j];
            }
            else{
                ;
            }
        }
        return best;
    }
};

int main()
{
    int n;
    cout << "Enter number of days: ";
    cin >> n;

    vector<int> prices(n);

    cout << "Enter stock prices: ";
    for (int i = 0; i < n; i++)
        cin >> prices[i];

    Solution obj;
    // int result = obj.brute(prices);
    int result = obj.optimal(prices);

    cout << "Maximum profit: " << result << endl;

    return 0;
}

// brute : tc - O(n^2) , sc - O(1)
// optimal : tc - O(n) , sc - O(1)