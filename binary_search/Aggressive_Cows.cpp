#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool canPlace(vector<int>& stalls, int cows, int distance) {
        // write feasibility logic
        return false;
    }

public:
    int brute(vector<int>& stalls, int cows) {
        // write brute solution
        return -1;
    }

    int optimal(vector<int>& stalls, int cows) {
        // write binary search solution
        return -1;
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