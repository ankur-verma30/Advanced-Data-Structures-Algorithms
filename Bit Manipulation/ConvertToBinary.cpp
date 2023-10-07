#include <iostream>

using namespace std;

int convertToBinary(int n)
{
    int ans = 0;
    int p = 1;
    while (n > 0)
    {
        int last_bit = (n & 1); // extract the last bit of the number
        ans += last_bit * p;    // multiply the number with its power and add to the intital number
        p *= 10;                // upgrade power
        n >>= 1;                // right shift one to get the last bit of the number every time
    }
    return ans;
}

int main()
{
    int n;
    cout << "Input the number " << endl;
    cin >> n;

    cout << "The binary form is " << convertToBinary(n) << endl;

    return 0;
}