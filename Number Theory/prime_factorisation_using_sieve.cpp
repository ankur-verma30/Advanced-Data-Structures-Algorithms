#include <bits/stdc++.h>
using namespace std;

#define N 1000000

void sieveOfEratosthenes(vector<bool> &sieve)
{
    sieve[0] = sieve[1] = false;
    for (long long i = 2; i * i <= N; i++)
    {
        if (sieve[i])
        {
            for (long long j = i * i; j <= N; j += i)
            {
                sieve[j] = false;
            }
        }
    }
}

void PrimeFactorisation(vector<long long> &newSieve, const vector<bool> &sieve, int val)
{
    for (int i = 2; i <= val; i++)
    {
        if (sieve[i])
        {
            newSieve[i] = i;
            for (int j = i * i; j <= val; j += i)
            {
                if (newSieve[j] == 0)
                {
                    newSieve[j] = i;
                }
            }
        }
    }
}

int main()
{
    vector<bool> sieve(N + 1, true);
    sieveOfEratosthenes(sieve);
    vector<long long> newSieve(N + 1, 0);

    int n;
    cout << "Enter a number to factorize: ";
    cin >> n;
    PrimeFactorisation(newSieve, sieve, n);

    map<int, int> mp;

    while (n > 1)
    {
        mp[newSieve[n]]++;
        n = n / newSieve[n];
    }

    for (auto x : mp)
    {
        cout << x.first << "^" << x.second << " ";
    }
    cout << endl;

    return 0;
}