#include <iostream>

using namespace std;

void ClearBitsInRange(int &n, int i, int j)
{

    int a = (~0 << (j + 1));//can also be written as (~0  << (j + 1))  
    int b = (1 << i) - 1;
    int mask = a | b;
    n = n & mask;
}
int main()
{
    int x, i, j;
    cout << "Enter the number ";
    cin >> x;
    cout << "Enter the starting position for clearing ";
    cin >> i;
    cout << "Enter the ending position for clearing ";
    cin >> j;
    ClearBitsInRange(x, i, j);
    cout << "The new number after clearing the range of bit is " << endl
         << x;

    return 0;
}