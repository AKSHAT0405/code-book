#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void brute(vector<vector<int>>& matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == 0){
                    for(int col = 0; col < n; col++){
                        if(matrix[i][col] != 0){
                            matrix[i][col] = -1;
                        }
                    }
                    for(int row = 0; row < n; row++){
                        if(matrix[row][j] != 0){
                            matrix[row][j] = -1;
                        }
                    }
                }
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == -1){
                    matrix[i][j]= 0;
                }
            }
        }
    }
    void better(vector<vector<int>>& matrix){
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> row_status(n,0);
        vector<int> col_status(m,0);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == 0){
                    row_status[i] = 1;
                    col_status[j] = 1;
                }
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(row_status[i] == 1 || col_status[j] == 1){
                    matrix[i][j] = 0;
                }
            }
        }
    }
    void optimal(vector<vector<int>>& matrix){
        int n = matrix.size();
        int m = matrix[0].size();
        int col0 = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    if(j != 0) matrix[0][j] = 0;
                    else col0 = 0;
                }
            }
        }
        for(int i = 1; i <n; i++){
            for(int j = 1; j < m; j++){
                if(matrix[i][j] != 0){
                    if(matrix[i][0] == 0 || matrix[0][j] == 0){
                        matrix[i][j] = 0;
                    }
                }
            }
        }
        if(matrix[0][0] == 0){
            for (int j = 0; j < m; j++)
            {
                matrix[0][j] = 0;
            }
        }
        if(col0 == 0){
            for(int i = 0; i < n; i++) matrix[i][0] = 0; 
        }
    
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
    // obj.brute(matrix);
    // obj.better(matrix);
    obj.optimal(matrix);

    cout << "Matrix after operation:\n";
    for (const auto& row : matrix)
    {
        for (int val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}


// brute : tc - O((n*m)^3) , sc - O(1)
// better : tc - O(2*(n*m)), sc - O(n+m)
// optimal : tc - O(2*(n*m)) ,  sc - O(1)