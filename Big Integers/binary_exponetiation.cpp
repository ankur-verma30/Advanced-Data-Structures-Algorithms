#include <bits/stdc++.h>
using namespace std;

int power(int a, int b){
    int res=1;
    while(b){
        if(b&1)
        res*=a;
        a*=a;
        b/=2;
    }
    return res;
}

int main()
{
    int a, b;

    cout << "Enter the base value " << endl;
    cin >> a;

    cout << "Enter the power " << endl;
    cin >> b;

    cout << "The value of " << a << "raised to " << b <<" is = "<< power(a, b) << endl;

    return 0;
}