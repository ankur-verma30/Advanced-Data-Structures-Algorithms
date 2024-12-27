#include <bits/stdc++.h>

using namespace std;

int countTotalSubsetofGivenSum(vector<int> &nums, int sum)
{
    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));

    for (int i = 0; i < n + 1; i++) dp[i][0] = 1;

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (j >= nums[i - 1])
                dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - nums[i - 1]]);
            else
                dp[i][j]= dp[i - 1][j];
        }
    }

    return dp[n][sum];
}

int main()
{
    int n;
    cout << "Enter the size of the array ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int sum;
    cout << "Enter the count of subset sum ";
    cin >> sum;

    cout <<"The total count of the subset sum is "<< countTotalSubsetofGivenSum(arr, sum) << endl;
    return 0;
}