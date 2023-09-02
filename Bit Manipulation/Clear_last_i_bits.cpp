#include <iostream>
using namespace std;

void ClearLastIBits(int &n, int position)
{
    int mask = (-1 << position);
    n = n & mask;
}
int main()
{
    int x, position;
    cout << "Enter the number : ";
    cin >> x;
    cout << "Enter the position till there you want to clear the bits. ";
    cin >> position;
    ClearLastIBits(x, position);
    cout << "the new number is : " << x << endl;
    return 0;
}