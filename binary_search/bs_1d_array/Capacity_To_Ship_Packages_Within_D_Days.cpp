#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int possible(vector<int>& weights , int c , int days){
        long sum = 0;
        int day = 1;
        for(int weight : weights){
            if(sum + weight <= c){
                sum += weight;
            }
            else{
                day++;
                sum = weight;
            }

        }
        return day <= days;
    }

    int brute(vector<int>& weights, int days)
    {
        int low = *max_element(weights.begin() , weights.end());
        int n = weights.size();
        int high = 0;
        for(int i = 0; i < n ; i++){
            high += weights[i];
        }

        for(int i = low; i <= high; i++){
            if(possible(weights , i , days)){
                return i;
            }  
        }
        return -1;
    }

    int my_approach(vector<int>& weights, int days)
    {
        int low = *max_element(weights.begin() , weights.end());
        int n = weights.size();
        int high = 0;
        int day = -1;
        for(int i = 0; i < n ; i++){
            high += weights[i];
        }

        while(low <= high){
            int mid = low + (high - low)/2;
            if(possible(weights , mid , days)){
                day = mid;
                high = mid - 1;
            } 
            else{
                low = mid + 1;
            } 
        }
        return day;
    }

    int optimal(vector<int>& weights, int days)
    {
        int low = *max_element(weights.begin() , weights.end());
        int high = 0;
        int n = weights.size();
        for(int i = 0; i < n ; i++){
            high += weights[i];
        }

        while(low <= high){
            int mid = low + (high - low)/2;
            if(possible(weights , mid , days)){
                high = mid - 1;
            } 
            else{
                low = mid + 1;
            } 
        }
        return low;
    }
};

int main()
{
    int n;
    cout << "Enter number of packages: ";
    cin >> n;

    vector<int> weights(n);

    cout << "Enter " << n << " package weights: ";
    for (int i = 0; i < n; i++)
        cin >> weights[i];

    int days;
    cout << "Enter number of days: ";
    cin >> days;

    Solution obj;

    // int result = obj.brute(weights, days);
    // int result = obj.my_approach(weights, days);
    int result = obj.optimal(weights, days);

    cout << "Minimum ship capacity: " << result << endl;

    return 0;
}
// let S = total weight , M = max weight 
//  so binary or linear search work for (S-w+1) or just S
// brute : tc - O(n*S) , sc - O(1)
//  optimal : tc - O(n*log2S) , sc  - O(1)