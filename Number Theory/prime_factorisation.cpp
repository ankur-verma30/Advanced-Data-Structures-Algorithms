#include <bits/stdc++.h>
using namespace std;

void primeFactorisation(int n)
{
    for (int i = 2; i * i <= n; i++)
    {
        int count = 0;
        if(n%i==0){
        while (n % i == 0)
        {

            n = n / i;
            count++;
        }
        cout << i << "^" << count <<" ";
    }
    }
    
    if (n != 1)
    {
        cout << n << "^1" << endl;
    }
}
int main()
{

    int n;

    cout << "Enter the number " << endl;
    cin >> n;

    primeFactorisation(n);

    return 0;
}