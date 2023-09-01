#include <iostream>

using namespace std;

void SetIthBit(int &n, int position)
{
    int mask = 1 << position;
    n = n | mask;
}

int main()
{
    int num, position;
    cout << "Enter the number = ";
    cin >> num; // cin contains the line change in itself
    cout << "Enter the  desired position you want to clear the bit = ";
    cin >> position;
    SetIthBit(num, position);
    cout << "the new value of the number after setting is  " << num;

    return 0;
}