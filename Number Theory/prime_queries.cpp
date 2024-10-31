/*
You are given Q queries . In each query you are given two integers A and B. Find the number of primes in the range [a,b]

Input
2
1 10
11 20

Output
4
4

Constraints
A,B,Q<=10^6
*/

#include <bits/stdc++.h>
using namespace std;

#define N 1000000

void sieveOfEratosthenes(vector<long long> &sieve)
{
    sieve[0] = sieve[1] = 0;
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
    vector<int> countPrimes(N, 0);
    sieveOfEratosthenes(sieve);

    for (int i = 1; i <= N; i++)
    {
        countPrimes[i] += countPrimes[i - 1] + sieve[i];
    }
    vector<vector<int>> queries = {{1, 10}, {11, 20}};
    for (int i = 0; i < queries.size(); i++)
    {
        int first = queries[i][0];
        int second = queries[i][1];
        cout << countPrimes[second] - countPrimes[first - 1] << endl;
    }

    return 0;
}