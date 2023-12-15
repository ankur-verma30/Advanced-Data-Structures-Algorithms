// add two big integer numbers
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

string AddNumbers(string str1, string str2)
{
    string result = "";
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());

    if (str1.length() > str2.length())
        swap(str1, str2);
    int carry = 0;
    for (int i = 0; i < str1.length(); i++)
    {
        int d1 = CharToNumber(str1[i]);
        int d2 = CharToNumber(str2[i]);
        int sum = d1 + d2 + carry;
        int output_digit = sum % 10;
        result.push_back(IntToChar(output_digit));
        carry = sum / 10;
    }
    for (int i = str1.length(); i < str2.length(); i++)
    {
        int d2 = CharToNumber(str2[i]);
        int sum = d2 + carry;
        int output_digit = sum % 10;
        result.push_back(IntToChar(output_digit));
        carry = sum / 10;
    }

    if (carry)
        result.push_back('1');

    reverse(result.begin(), result.end());

    return result;
}
int main()
{
    string str1, str2;
    cout << "Enter a first numeric string " << endl;
    cin >> str1;
    cout << "Enter a second numeric string " << endl;
    cin >> str2;
    string result = AddNumbers(str1, str2);
    cout << "The result is " << result << endl;
    return 0;
}