/*Find the unique number
Every number is appearing except one number and the size of the array is 2N+1 so find the unique number
*/

#include <bits/stdc++.h>

using namespace std;
int UniqueNumber(vector<int> &numbers, int size)
{
    int res = 0;
    for (int i = 0; i < size; i++)
    {
        res = res ^ numbers[i];
    }
    return res;
}
int main()
{
    vector<int> numbers;
    int size;
    int a;
    cout << "Enter the size of the vector which should be off odd length " << endl;
    cin >> size;
    if (size % 2 == 0)
    {
        cout << "Enter the size of the vector as odd length " << endl;
        cin >> size;
    }
    cout << "Enter the elements of the vector " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> a;
        numbers.push_back(a);
    }

    cout << "The unique number is " << UniqueNumber(numbers, size);
    return 0;
}