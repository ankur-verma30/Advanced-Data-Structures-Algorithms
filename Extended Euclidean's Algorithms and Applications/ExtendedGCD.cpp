#include <bits/stdc++.h>

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

int main()
{
    int a, b;
    cin >> a >> b;
    int gcd = 0;
    vector<int> res = extendedGCD(a, b);

    cout << "GCD : " << res[2] << endl;
    cout << "X : " << res[0] << endl;
    cout << "Y : " << res[1] << endl;
}