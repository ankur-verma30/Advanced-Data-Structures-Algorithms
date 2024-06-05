// The frog has to reach at the nth stair and he can jump k steps at max at a time and loses some energy so how much he will lose to reach to reach at the top

#include <bits/stdc++.h>

using namespace std;

/**
 * Calculates the minimum number of jumps required for a frog to reach the end of a staircase with a given energy level.
 *
 * @param n The number of stairs.
 * @param k The maximum number of steps the frog can take at a time.
 * @param dp A vector to store the minimum number of jumps required to reach each stair.
 * @param energy A vector containing the energy level at each stair.
 *
 * @return The minimum number of jumps required to reach the end of the staircase.
 *
 * @throws None.
 */

// using recursion
int MinkJumps(int index, int k, vector<int> &energy)
{
    if (index == 0)
        return 0;
    int minJumps = INT_MAX;
    for (int i = 1; i <= k; i++)
    {
        if (index - i >= 0)
        {
            int jump = MinkJumps(index - i, k, energy) + abs(energy[index] - energy[index - i]);
            minJumps = min(minJumps, jump);
        }
    }
    return minJumps;
}

// memoization
int MinkJumpsMemoization(int index, int k, vector<int> &dp, vector<int> &energy)
{
    if (index == 0)
        return 0;
    if (dp[index] != -1)
        return dp[index];

    int minJumps = INT_MAX;

    for (int i = 1; i <= k; i++)
    {
        if (index - i >= 0)
        {
            int jump = MinkJumpsMemoization(index - i, k, dp, energy) + abs(energy[index] - energy[index - i]);
            minJumps = min(minJumps, jump);
        }
    }
    return dp[index] = minJumps;
}

// tabulation method

int MinkJumpsTabulation(int n, int k, vector<int> &dp, vector<int> &energy)
{
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        int minStep = INT_MAX;
        for (int j = 1; j <= j; j++)
        {
            if (i - j >= 0)
            {
                int jump = dp[i - j] + abs(energy[i] - energy[i - j]);
                minStep = min(minStep, jump);
            }
        }
        dp[i] = minStep;
    }

    return dp[n - 1];
}

int main()
{
    vector<int> energy;
    int n, k;
    cout << "Enter the number of stairs" << endl;
    cin >> n;
    cout << "Enter the number of steps" << endl;
    cin >> k;
    cout << "Enter the energy" << endl;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        energy.push_back(a);
    }

    vector<int> dp(n, -1);
    dp[0] = 0;
    cout << MinkJumps(n, k, energy) << endl;
}