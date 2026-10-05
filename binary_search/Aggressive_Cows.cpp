#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool canPlace(vector<int>& stalls, int cows, int distance) {
        int cow_count = 1; 
        int last_stall = stalls[0];
        for(int i = 1; i < stalls.size(); i++){
            if(stalls[i] - last_stall >= distance){
                cow_count++;
                last_stall = stalls[i];
            }
        }
        if(cow_count >= cows){
            return true;
        }
        return false;
    }

public:
    int brute(vector<int>& stalls, int cows) {
        sort(stalls.begin() , stalls.end());
        int n = stalls.size();
        int low = 0; int high = stalls[n-1] - stalls[0];
        for(int i = low; i <= high; i++){
            if(! canPlace(stalls , cows , i)){
                return i-1;   
            }
        }
        return high;
    }

    int optimal(vector<int>& stalls, int cows) {
        sort(stalls.begin() , stalls.end());
        int n = stalls.size();
        int low = 0; int high = stalls[n-1] - stalls[0];
        while(low <= high){
            int mid = low + (high - low)/2;
            if(canPlace(stalls , cows , mid)){
                low = mid + 1;
            }
            else{
                high = mid - 1;  
            }
        }
        return high;
    }
};

int main() {
    int n, k;

    cout << "Enter number of stalls: ";
    cin >> n;

    vector<int> stalls(n);

    cout << "Enter stall positions: ";
    for (int i = 0; i < n; i++) {
        cin >> stalls[i];
    }

    cout << "Enter number of cows: ";
    cin >> k;

    Solution obj;

    cout << "Brute: " << obj.brute(stalls, k) << endl;
    cout << "Optimal: " << obj.optimal(stalls, k) << endl;

    return 0;
}

// brute : tc - O(nlogn) + O(n * (maxi - mini)) , sc - O(1)
// optimal : tc - O(nlogn) + O(n * log2(maxi - mini)) , sc - O(1)