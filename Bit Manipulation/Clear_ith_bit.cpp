#include <iostream>
using namespace std;

int ClearIthBit(int n, int position)
{
    int mask = ~(1 << position);
    n = n & mask;
    return n;

}

int main()
{
    int x, position;
    cout << "Enter the number = ";
    cin >> x; // cin contains the line change in itself
    cout << "Enter the  desired position you want to clear the bit = ";
    cin >> position;
    x=ClearIthBit(x,position);
    cout << "The value of the n is " << x << endl;

    return 0;
}