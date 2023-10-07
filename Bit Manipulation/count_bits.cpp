#include <iostream>

using namespace std;
int count_bits(int n)
{
    int count = 0;
    while (n > 0)
    {
        count += (n & 1); // Time Complexity o(log2n)     
        n = n >> 1;
    }
    return count;
}
int count_bits_hack(int n)
{
    int ans = 0;
    while (n > 0)
    {
        n = n & (n - 1); // removing each set bit in each set
        ans++;
    }
    return ans;
}
int main()
{
    int number;
    cout << "Enter the number to find the number of set bits " << endl;
    cin >> number;

    cout << "The number of set bits " << count_bits(number) << endl;
    cout << "The number of set bits " << count_bits_hack(15) << endl;

    return 0;
}
