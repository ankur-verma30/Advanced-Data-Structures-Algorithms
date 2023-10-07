#include <iostream>

using namespace std;
void ClearBitsInRange(int &n, int i, int j)
{
    int a = (~0) << (j + 1); // left shifted j+1
    int b = (1 << i) - 1;

    int mask = a | b;
    n = n & mask;
}

void replaceBits(int &n, int i, int j, int m)
{
    ClearBitsInRange(n, i, j); // first clear the bits from i to j

    int mask = (m << i); // left shift m by factor of i to make equivalent bits from the 0th position
    n = n | mask;        // taking or with the mask or the updated m that we are going to replace
}
int main()
{

    int n = 15;
    int i = 1;
    int j = 3;
    int m = 2;
    replaceBits(n, i, j, m);
    cout << "the new value of the n is " << n << endl;
    return 0;
}