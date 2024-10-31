#include <bits/stdc++.h>
using namespace std;

int TotalPathCount(int row, int col)
{
    // Base Case 1: If either row or col is 0, there is only one way
    // to reach the bottom-right cell, from the top-left cell.
    if (row == 0 || col == 0)
    {
        return 1;
    }
    // Base Case 2: If either row or col is negative, there are no
    // paths from the top-left cell to the bottom-right cell.
    if (row < 0 || col < 0)
    {
        return 0;
    }
    // Recursive Case:
    // The total number of unique paths from the current cell is the
    // sum of the unique paths from the cell to the left, and the
    // unique paths from the cell above.
    int left = TotalPathCount(row, col - 1);
    int up = TotalPathCount(row - 1, col);
    return left + up;
}

// Memoization

int TotalPathCount(int row, int col, vector<vector<int>> &dp)
{
    // Base Case 1: If either row or col is 0, there is only one way
    // to reach the bottom-right cell, from the top-left cell.
    if (row == 0 || col == 0)
    {
        return 1;
    }
    // Base Case 2: If either row or col is negative, there are no
    // paths from the top-left cell to the bottom-right cell.
    if (row < 0 || col < 0)
    {
        return 0;
    }
    // If the result is already calculated, return it
    if (dp[row][col] != -1)
    {
        return dp[row][col];
    }
    // Recursive Case:
    // The total number of unique paths from the current cell is the
    // sum of the unique paths from the cell to the left and
    // the unique paths from the cell above.
    int left = TotalPathCount(row, col - 1, dp);
    int up = TotalPathCount(row - 1, col, dp);
    // Store the result and return it
    return dp[row][col] = left + up;
}

int TotalPathCount2(int row, int col, vector<vector<int>> &dp)
{
    // Initialize the first row and column with 1
    for (int i = 0; i < row; i++)
    {
        dp[i][0] = 1;
    }
    for (int j = 0; j < col; j++)
    {
        dp[0][j] = 1;
    }
    // Calculate the number of unique paths from each cell
    for (int i = 1; i < row; i++)
    {
        for (int j = 1; j < col; j++)
        {
            // The number of unique paths from the current cell is the
            // sum of the unique paths from the cell to the left and
            // the unique paths from the cell above.
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[row - 1][col - 1];
}

// space optimized solution
int TotalPathCount3(int row, int col, vector<vector<int>> &dp)
{

    vector<int> prev(row, 0);

    for (int i = 0; i < row; i++)
    {

        vector<int> temp(row, 0);
        for (int j = 0; j < col; j++)
        {
            if (i == 0 && j == 0)
            {
                temp[j] = 1;
                continue;
            }
            int up = 0, left = 0;

            up = (i > 0) ? prev[j] : 0;
            left = (j > 0) ? temp[j - 1] : 0;
            temp[j] = up + left;
        }
        prev = temp;
    }
    return prev[row - 1];
}

// Using Combinatorics

int TotalPathCount4(int row, int col)
{
    // The total number of unique paths can be calculated using
    // combinatorics. We consider the grid as a rectangle with N
    // rows and columns. The number of unique paths is the number
    // of ways to choose r steps down and (N - r) steps right.
    int N = row + col - 2; // Total number of steps
    int r = row - 1;       // Number of steps down
    double res = 1;

    // Calculate the number of unique paths using the formula
    // (N - r + i)!/i! * (N - r + i - 1)!
    for (int i = 1; i <= r; i++)
    {
        res = res * (N - r + i) / i;
    }

    return (int)res;
}
int main()
{
    int row, col;
    cout << "Enter the number of rows and columns " << endl;
    cin >> row >> col;
    // Recursive Approach
    //  cout << "The number of unique ways to reach the bottom of the grid is " << TotalPathCount(row - 1, col - 1);
    //  vector<vector<int>>dp(row,vector<int>(col,-1));
    // Memoization Approach
    //  cout<<"The number of unique ways to reach the bottom of the grid is "<<TotalPathCount(row-1,col-1,dp);

    // Tabulation Approaches
    vector<vector<int>> dp(row, vector<int>(col, 0));

    // cout << "The number of unique ways to reach the bottom of the grid " << TotalPathCount2(row, col, dp);

    // Space Optimized Dp
    // cout << "The number of unique ways to reach the bottom of the grid " << TotalPathCount3(row, col, dp);

    // Using Combinatorics
    cout << "The number of unique ways to reach the bottom of the grid " << TotalPathCount4(row, col);
    return 0;
}