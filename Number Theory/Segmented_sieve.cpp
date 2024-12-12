#include <bits/stdc++.h>
using namespace std;

void sieveOfEratosthenes(int number, vector<long long> &sieve, vector<int> &preComputedPrimes)
{
    sieve[0] = sieve[1] = 0;
    // start from 2 and mark all the multiples of ith number as not prime
    for (long long i = 2; i <= number; i++)
    {
        if (sieve[i] == 1)
        {
            preComputedPrimes.push_back(i);
            for (long long j = i * i; j <= number; j += i)
                sieve[j] = 0;
        }
    }
}

int main()
{
    int number = 100000;
    vector<long long> sieve(number + 1, 1);
    vector<int> preComputedPrimes;
    sieveOfEratosthenes(number, sieve, preComputedPrimes);
    int m, n;
    cin >> m >> n;
    vector<int> segment(n - m + 1, 0);

    for (auto p : preComputedPrimes)
    {
        // if prime's square is out of bound then no need to run the loop before than all the number will already be marked
        if (p * p > n)
            break;
        // find the first multiple of the prime number
        int start = (m / p) * p;

        // special case when the m is less than the prime number
        if (p >= m && p <= n)
            start = 2 * p;
        for (int j = start; j <= n; j += p)
        { //this is the new page
            // if the first multiple we find is out of bound so till then it reaches m we continue;
            if (j < m)
                continue;
            // then we go to j-m when j is greater than or equal to m so we minus m so that it has index of 0
            segment[j - m] = 1;
        }
    }

    for (int i = m; i <= n; i++)
    {
        if (segment[i-m] == 0 && i != 1)
        {
            cout <<  i <<" ";
        }
    }
    return 0;
}