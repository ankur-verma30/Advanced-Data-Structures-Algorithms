#include <bits/stdc++.h>
using namespace std;

/**
 * Function to calculate the maximum points a ninja can obtain by performing tasks.
 *
 * @param index the current index of the ninja
 * @param last the index of the task done by the current ninja
 * @param points a matrix representing the points obtained by each task
 * @return the maximum points the ninja can obtain
 */

// this is the recursive method
int tasksPerformed(int index, int last, vector<vector<int>> &points)
{
    // Base case: when the ninja is at the first index.
    if (index == 0)
    {
        int maxi = 0;
        // Iterate over each task to find the maximum points.
        for (int task = 0; task < 3; task++)
        {
            // Exclude the task done by the current ninja.
            if (task != last)
            {
                // Calculate the points obtained by performing the task.
                maxi = max(maxi, points[0][task]);
            }
        }
        return maxi;
    }

    // Recursive case: find the maximum points by performing tasks.
    int maxi = 0;
    // Iterate over each task.
    for (int task = 0; task < 3; task++)
    {
        // Exclude the task done by the current ninja.
        if (task != last)
        {
            // Calculate the points obtained by performing the task.
            int point = points[index][task] + tasksPerformed(index - 1, task, points);
            // Update the maximum points.
            maxi = max(maxi, point);
        }
    }
    return maxi;
}

// Memoized method

int tasksPerformed2(int index, int last, vector<vector<int>> &points, vector<vector<int>> &dp)
{
    // Base case: when the ninja is at the first index.
    if (index == 0)
    {
        int maxi = 0;
        // Iterate over each task to find the maximum points.
        for (int task = 0; task < 3; task++)
        {
            // Exclude the task done by the current ninja.
            if (task != last)
            {
                // Calculate the points obtained by performing the task.
                maxi = max(maxi, points[0][task]);
            }
        }
        return maxi;
    }

    if (dp[index][last] != -1)
        return dp[index][last];

    int maxi = 0;
    // Iterate over each task.
    for (int task = 0; task < 3; task++)
    {
        if (task != last)
        {
            int point = points[index][task] + tasksPerformed2(index - 1, task, points, dp);
            maxi = max(maxi, point);
        }
    }
    return dp[index][last] = maxi;
}

// Tabulation method

int taskperformed3(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int>(4, 0));

    // Base case initialization
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max({points[0][0], points[0][1], points[0][2]});

    for (int day = 1; day < n; day++)
    {
        for (int last = 0; last < 4; last++)
        {
            dp[day][last] = 0;
            for (int task = 0; task < 3; task++)
            {
                if (task != last)
                {
                    int point = points[day][task] + dp[day - 1][task];
                    dp[day][last] = max(dp[day][last], point);
                }
            }
        }
    }
    return dp[n - 1][3];
}

int main()
{
    vector<vector<int>> points{
        {2, 1, 3},
        {3, 4, 6},
        {10, 1, 6},
        {8, 3, 7},
    };

    int n = points.size();
    int val = taskperformed3(n, points);
    cout << val;

    return 0;
}