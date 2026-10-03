#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool canPaint(vector<int>& boards, int painters, long long limit) {
        int paintersUsed = 1;
        long long currentLength = 0;

        for (int boardLength : boards) {
            if (currentLength + boardLength <= limit) {
                currentLength += boardLength;
            }
            else {
                paintersUsed++;
                currentLength = boardLength;
            }

            if (paintersUsed > painters)
                return false;
        }

        return true;
    }

public:
    int brute(int painters, int timePerUnit, vector<int>& boards) {
        int n = boards.size();

        if (painters > n)
            return -1;

        long long minLimit = *max_element(boards.begin(), boards.end());
        long long maxLimit = accumulate(boards.begin(), boards.end(), 0LL);

        for (long long limit = minLimit; limit <= maxLimit; limit++) {
            if (canPaint(boards, painters, limit)) {
                return (limit * timePerUnit) % 10000003;
            }
        }

        return -1;
    }

    int optimal(int painters, int timePerUnit, vector<int>& boards) {
        int n = boards.size();

        if (painters > n)
            return -1;

        long long low = *max_element(boards.begin(), boards.end());
        long long high = accumulate(boards.begin(), boards.end(), 0LL);

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (canPaint(boards, painters, mid))
                high = mid - 1;
            else
                low = mid + 1;
        }

        return (low * timePerUnit) % 10000003;
    }
};

int main() {
    int painters, timePerUnit, n;

    cout << "Enter number of painters: ";
    cin >> painters;

    cout << "Enter time per unit: ";
    cin >> timePerUnit;

    cout << "Enter number of boards: ";
    cin >> n;

    vector<int> boards(n);

    cout << "Enter board lengths: ";
    for (int i = 0; i < n; i++)
        cin >> boards[i];

    Solution obj;

    // cout << "Brute: " << obj.brute(painters, timePerUnit, boards) << endl;
    cout << "Optimal: " << obj.optimal(painters, timePerUnit, boards) << endl;

    return 0;
}