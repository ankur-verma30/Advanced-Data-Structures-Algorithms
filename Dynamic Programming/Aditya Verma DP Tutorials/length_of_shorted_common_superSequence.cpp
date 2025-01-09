#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s1, s2;
    cout << "Input both the strings " << endl;
    cout << "Enter the string 1 ";
    cin >> s1;
    cout << "Enter the string 2 ";
    cin >> s2;
    int n = s1.length();
    int m = s2.length();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1));

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < m + 1; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    int common = dp[n][m];

    cout << "The length of the shortest common supersequence is " << (n + m - common) << endl;

    return 0;
}