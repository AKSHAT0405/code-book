#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void brute(vector<vector<int>>& matrix)
    {
        int n = matrix.size();
        vector<vector<int>> rotated(n, vector<int>(n));
        for (int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++){
                rotated[j][n-1-i] = matrix[i][j];

            }
        }
        for (int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++){
                matrix[i][j] = rotated[i][j];

            }
        }
    }
};

int main()
{
    int n;
    cout << "Enter size of square matrix: ";
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));

    cout << "Enter " << n * n << " elements:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }

    Solution obj;
    obj.brute(matrix);

    cout << "Rotated matrix:\n";
    for (const auto& row : matrix)
    {
        for (int x : row)
            cout << x << " ";
        cout << endl;
    }

    return 0;
}

// brute : tc - O(n^2)  , sc - O(n^2)
