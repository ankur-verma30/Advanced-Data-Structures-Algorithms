#include <bits/stdc++.h>

using namespace std;

int multiply(int a, int b, int c)
{
    int result = 0;
    while (b)
    {
        if (b & 1)
            result += a;
        result %= c;
        a = 2 * a;
        a %= c;
        b /= 2;
    }
    return result;
}

int32_t main()
{
    cout << "The multiplication of two numbers are " << endl;
    cout << multiply(2, 10, 1e9 + 7);
    cout << endl;
    cout << multiply(45, 97, 1e9 + 7);
    return 0;
}