// Find the maximum of sum of non adjecent elements

#include <bits/stdc++.h>

using namespace std;

// this is the recursion method
int MaximumSum(vector<int> &arr, int index)
{
    if (index == 0)
        return arr[index];
    if (index < 0)
        return 0;

    int pick = arr[index] + MaximumSum(arr, index - 2);
    int notPick = 0 + MaximumSum(arr, index - 1);
    return max(pick, notPick);
}

int MaximumSumMemoization(vector<int> &arr, int index, vector<int> &dp)
{
    if (index == 0)
        return arr[index];
    if (index < 0)
        return 0;

    if (dp[index] != -1)
        return dp[index];

    int pick = arr[index] + MaximumSum(arr, index - 2);
    int notPick = 0 + MaximumSum(arr, index - 1);
    return dp[index] = max(pick, notPick);
}

// this is the tabulation method
int MaximumSumTabulation(vector<int> &arr)
{
    int n = (int)arr.size();
    vector<int> dp(n);
    dp[0] = arr[0];
    dp[1] = max(arr[0], arr[1]);
    for (int i = 2; i < n; i++)
    {
        int pick = arr[i] + dp[i - 2];
        int notPick = dp[i - 1];
        dp[i] = max(pick, notPick);
    }
    return dp[n - 1];
}

// space optimiszed method
int MaximumSumSpaceOptimized(vector<int> &arr)
{
    int prev1 = arr[0];
    int prev = max(arr[1], prev1);

    for (int i = 2; i < arr.size(); i++)
    {
        int pick = arr[i] + prev1;
        int notPick = prev;
        int curr = max(pick, notPick);
        prev1 = prev;
        prev = curr;
    }
    return prev;
}

int main()
{
    vector<int> arr{2, 1, 4, 9};
    int n = (int)arr.size();
    vector<int> dp(n, -1);
    cout << MaximumSum(arr, n - 1) << endl;
    cout << MaximumSumMemoization(arr, n - 1, dp) << endl;
    cout << MaximumSumTabulation(arr) << endl;
    cout << MaximumSumSpaceOptimized(arr) << endl;

    cout << "Second Example " << endl;

    vector<int> arr1{1, 3, 4};
    int n1 = (int)arr1.size();
    vector<int> dp1(n1, -1);
    cout << MaximumSum(arr1, n1 - 1) << endl;
    cout << MaximumSumMemoization(arr1, n1 - 1, dp1) << endl;
    cout << MaximumSumTabulation(arr1) << endl;
    cout << MaximumSumSpaceOptimized(arr1);
}