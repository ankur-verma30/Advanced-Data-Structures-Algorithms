/*Unique numbers-2
There are exactly two unique numbers present in the array find the numbers and all the other numbers are present exactly two times in the array

*/
#include <bits/stdc++.h>

using namespace std;

pair<int, int> UniqueNumbers2(vector<int> numbers)
{
    int xor1 = 0;
    // Xor of all the numbers in the vector
    for (int i = 0; i < numbers.size(); i++)
    {
        xor1 ^= numbers[i];
    }

    // find the position of the first set bit in the xor
    int pos = 0;
    int temp = xor1;
    while ((temp & 1) == 0)
    {
        pos++;
        temp = temp >> 1;
    }
    // fitler the number of array which have set bit at the position index

    int setA = 0;
    int setB = 0;
    int mask = (1 << pos);
    for (int i = 0; i < numbers.size(); i++)
    {
        if ((numbers[i] & mask) > 0)
            setA ^= numbers[i];
        else
            setB ^= numbers[i];
    }

    return {setA, setB};
}

int main()
{
    vector<int> numbers;
    int size;
    int a;
    cout << "Enter the size of the vector which should be off odd length " << endl;
    cin >> size;
    if (size % 2 != 0)
    {
        cout << "Enter the size of the vector as even length " << endl;
        cin >> size;
    }
    cout << "Enter the elements of the vector " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> a;
        numbers.push_back(a);
    }

    pair<int, int> unique = UniqueNumbers2(numbers);
    cout << "the first unique number is " << unique.first << endl;
    cout << "the second unique number is " << unique.second << endl;
    return 0;
}
