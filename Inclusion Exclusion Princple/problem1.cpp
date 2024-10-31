// How many numbers less than 10^18 are divisible by first 10 prime numbers

#include<bits/stdc++.h>
using namespace std;


int main()
{

vector<int> prime={2,3,5,7,11,13,17,19,23,29};
int m=prime.size();
int ans=0;
int n=10;

for(int i=1;i<(1<<m);i++){
long long lcm=1;
    for(int j=0;j<m;j++){
        if((i >> j) & 1) {
            lcm*=prime[j];
        }
    }
        if(__builtin_popcount(i)%2==0){
            ans-=n/lcm;
    }
    else ans+=n/lcm;
   
}

cout<<ans;

return 0;
}