#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiral(vector<vector<int>>& matrix)
    {
        vector<int> res;
        int n = matrix.size();
        int m = matrix[0].size();
        int left = 0; int right = m-1;
        int top = 0; int bottom = n-1;
        while(top <= bottom && left <= right) {
            for(int i = left; i <= right; i++) {
                res.push_back(matrix[top][i]);
            }
            top++; 
            for(int i = top; i <= bottom; i++) {
                res.push_back(matrix[i][right]);
            }
            right--; 
            if(top <= bottom) {
                for(int i = right; i >= left; i--) {
                    res.push_back(matrix[bottom][i]);
                }
                bottom--; 
            }
            if(left <= right) {
                for(int i = bottom; i >= top; i--) {
                    res.push_back(matrix[i][left]);
                }
                left++; 
            }
        }
        return res;
    }
};

int main()
{
    int rows, cols;

    cout << "Enter number of rows: ";
    cin >> rows;

    cout << "Enter number of columns: ";
    cin >> cols;

    vector<vector<int>> matrix(rows, vector<int>(cols));

    cout << "Enter matrix elements:\n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> matrix[i][j];
        }
    }

    Solution obj;
    vector<int> result = obj.spiral(matrix);

    cout << "Spiral traversal: ";
    for (int x : result)
        cout << x << " ";

    cout << endl;

    return 0;
}