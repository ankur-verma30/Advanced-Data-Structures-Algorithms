// fibonacci series using dynamic programming

#include <bits/stdc++.h>

using namespace std;

// this is a memoization method to solve the question using space complexity O(n) for recursion and + O(n) for dp array
int fibonacci(int n, vector<int> &dp)
{
    if (n <= 1)
        return n;
    if (dp[n] != -1)
        return dp[n];

    return dp[n] = fibonacci(n - 1, dp) + fibonacci(n - 2, dp);
}

// this is the tabulation method using space complexity o(n)
int fibonacci2(int n, vector<int> &dp)
{
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

// using no space
int fibonacci3(int n)
{
    if(n<=1) return n;
    int prev1 = 0;
    int prev = 1;
    for (int i = 2; i <= n; i++)
    {
        int curr = prev1 + prev;
        prev1 = prev;
        prev = curr;
    }
    return prev;
}

int main()
{
    int n;
    cout << "Enter the number ";
    cin >> n;
    vector<int> dp(n + 1, -1);
    cout << "The fibonacci number is " << fibonacci(n, dp) << endl;
    cout << "The fibonacci number is " << fibonacci2(n, dp) << endl;
    cout << "The fibonacci number is " << fibonacci3(n) << endl;
}