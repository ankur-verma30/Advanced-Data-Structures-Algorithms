#include <iostream>
using namespace std;

int GetIthBit(int n, int position)
{
    int mask = 1 << position;
    return (n & mask) > 0 ? 1 : 0;
}

int main()
{
    int x, position;
    cout << "Enter the number = ";
    cin >> x;//cin contains the line change in itself 
    cout << "Enter the value of the bit at desired position = ";
    cin >> position;
    cout << "The value of the ith bit is = " << GetIthBit(x, position) << endl;

    return 0;
}