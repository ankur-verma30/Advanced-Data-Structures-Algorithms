#include<bits/stdc++.h>

using namespace std;

vector<int> extendedGCD(int a, int b)
{
    if (b == 0) return {1, 0, a};
    

    vector<int> result = extendedGCD(b, a % b);
    int smallX = result[0];
    int smallY = result[1];
    int gcd = result[2];

    int x = smallY;
    int y = smallX - (a / b) * smallY;

    return {x, y,gcd };
}

int MultiplicativeModuloInverse(int a, int m){
    vector<int>result=extendedGCD(a,m);
    int x=result[0]; //x can be negative also
    int gcd=result[2];

    if(gcd!=1) return 0;

    return x;
}

int main(){
    int a,m;
    cin>>a>>m;  //shoule be relatively prime

    int res=MultiplicativeModuloInverse(a,m);
    res=(res%m +m)%m;
    if(res==0)
    cout<<"The Multiplicative Modulo of a and m does not exist"<<endl;
    else cout<<"The Multiplicative Modulo of a and m is "<<res<<endl;

    cout<<-4%5;
    return 0;
}