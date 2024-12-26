#include<bits/stdc++.h>

using namespace std;

int Recursivegcd(int a, int b){
    if(b==0) return a;

    return gcd(b, a%b);  // Euclidean Algorithm
}

int main(){
    int a,b;
    cin>>a>>b;

    cout<<Recursivegcd(a,b)<<endl;
    return 0;
}