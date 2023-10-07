#include <iostream>

using namespace std;

int main()
{
    int n;
    cout << "Enter the number to check it is power of two or not" << endl;
    cin >> n;

    if ((n & (n - 1)) == 0)    //T.C is O(1) check 
        cout << "the number is power of two" << endl;
    else
        cout << "the number is not power of two" << endl;

    return 0;
}