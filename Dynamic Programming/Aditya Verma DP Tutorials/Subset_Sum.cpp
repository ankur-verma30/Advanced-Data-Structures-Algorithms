#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter the elements of the array: ";
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int sum;
    cout<<"Enter the subset sum ";
    cin>>sum;
    bool dp[n+1][sum+1];
    memset(dp, false, sizeof(dp));

     for (int i = 0; i <= n; i++) dp[i][0] = true;  // Subset sum 0 is always true
    for (int j = 1; j <= sum; j++) dp[0][j] = false;  // Empty subset cannot achieve sum > 0

    // Fill DP table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (arr[i - 1] <= j) {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    if(dp[n][sum])
    cout<<"Yes, there exists a subset with given sum"<<endl;
    else cout<<"No, there does not exist a subset with given sum"<<endl;

    return 0;
}