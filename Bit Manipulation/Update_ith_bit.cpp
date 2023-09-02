#include <iostream>
using namespace std;

void ClearIthBit(int &n, int position)
{
    int mask = ~(1 << position);
    n = n & mask;
}
int UpdateIthBit(int &n, int position, int value)
{
    ClearIthBit(n, position);
    int mask = (value << position);
    n = n | mask;
    return n;
}

int main()
{
    int x, position, value;
    cout << "Enter the number = ";
    cin >> x; // cin contains the line change in itself
    cout << "Enter the  desired position of bit = ";
    cin >> position;
    cout << "Enter the value you want to update" << endl;
    cin >> value;
    x=UpdateIthBit(x,position,value);
    cout << "The value of the n is " << x << endl;
    return 0;
}