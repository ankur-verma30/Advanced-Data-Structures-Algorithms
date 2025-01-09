#include<bits/stdc++.h>

using namespace std;

string lcs(string a, string b,vector<vector<int>>&dp){
    //intialization of dp
    int n=a.length();
    int m=b.length();
    for(int i=0;i<n+1;i++){
        for(int j=0;j<m;j++){
            if(i==0 || j==0){
                dp[i][j]=0;
            }
        }
    }

    for(int i=1;i<n+1;i++){
        for(int j=1;j<m;j++){
            if(a[i]==b[j]){
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
        }
    }

    string str="";
    int i=n,j=m;

    while(i>0 && j>0){
        if(a[i-1]==b[j-1]){
            str+=a[i-1];
            i--;
            j--;
        }
        else if(dp[i-1][j]>dp[i][j-1]){
            i--;
        }
        else j--;
    }

    reverse(str.begin(),str.end());
    return str;
 
}

int main() {
   string a,b;
    cin >> a>>b;
    int n=a.length();
    int m=b.length();
    vector<vector<int>>dp(n+1,vector<int>(m+1));
    cout<<"The longest common subsequence among the two strings is "<<lcs(a,b,dp)<<endl;

    return 0;
}