// this is used to find the recurrance relation
// We will find the fibonacci numbers

#include <bits/stdc++.h>
#define int long long int 

using namespace std;

const int mod = 1e9 + 7;
const int s2 = 2;

struct Mat
{
    int m[s2][s2];
    Mat()
    {
        memset(m, 0, sizeof(m));
    }
    void identity()
    {
        for (int i = 0; i < s2; i++)
            m[i][i] = 1;
    }
    Mat operator * (Mat a){
        Mat res;
        for (int i = 0; i < s2; i++)
        {
            for (int j = 0; j < s2; j++)
            {
                for (int k = 0; k < s2; k++)
                {
                    res[i][j] += m[i][k] * a.m[k][j];
                    res[i][j] %= mod;//we also have to overload the subscript operator in this
                }
            }
        }
        return res;
    }
};

int Fib(int n)
{
    Mat res;
    res.identity();
    Mat T;
    T.m[0][0] = T.m[0][1] = T.m[1][0] = 1;
    if (n <= 2)
        return 1;
    while (n)
    {
        if (n & 1)
            res = res * T;
        T = T * T;
        n = n / 2;
    }
    return res.m[0][0] + res.m[0][1];
}

int32_t main()
{
    cout << "Let's find the bigger values of fibonacci numbers " << endl;
    int n;
    cout << "Enter which position fibonacci numbers you want to find ";
    cin >> n;
    cout << "The number is " << Fib(n) << endl;

    return 0;
}