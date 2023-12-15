// multiply two strings
#include <bits/stdc++.h>

using namespace std;

int CharToNumber(char ch)
{
    return ch - '0';
}

char IntToChar(int n)
{
    return n + '0';
}

string MultiplyString(string str1, string str2)
{
    if (str1.length() > str2.length())
        swap(str1, str2);
    int carry = 0;
    vector<int> product(1000, 0);
    for (int i = 0; i < str1.length(); i++)
    {
        int multiplier = CharToNumber(str1[i]);
        for (int j = 0; j < str2.length(); j++)
        {
            int multiplicand = CharToNumber(str2[j]);
        }
    }
}
// do it later

int main()
{
    string str1, str2;
    cout << "Enter the numeric value of the string 1 " << endl;
    cin >> str1;
    cout << "Enter the numeric value of the string 2 " << endl;
    cin >> str2;

    string result = MultiplyString(str1, str2);
    cout << "The result is " << result << endl;
}