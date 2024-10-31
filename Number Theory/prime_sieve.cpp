#include <bits/stdc++.h>
using namespace std;
#define N 1000

void sieveOfEratosthenes(vector<long long> &sieve)
{
    sieve[0] = sieve[1] = 0;
    // start from 2 and mark all the multiples of ith number as not prime
    for (long long i = 2; i <= N; i++)
    {
        if (sieve[i])
        {
            for (long long j = i * i; j <= N; j += i)
                sieve[j] = 0;
        }
    }
}
int main()
{
    vector<long long> sieve(N, 1);
    vector<int> primes;
    sieveOfEratosthenes(sieve);
    for (long long i = 2; i <= N; i++)
    {
        if (sieve[i])
            primes.push_back((int)i);
    }

    for (const auto &x : primes)
        cout << x << " ";

    return 0;
}