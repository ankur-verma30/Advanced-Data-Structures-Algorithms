#include<bits/stdc++.h>

using namespace std;

int  CountWays(int index){
   if(index==0) return 1;
   if(index==1) return 1;

   return CountWays(index-1)+CountWays(index-2);

}

int main(){
    int n;
    cout<<"the total number of stairs "<<endl;
    cin>>n;
    cout<<"The minimum number of ways to reach at the top "<<CountWays(n); 
}