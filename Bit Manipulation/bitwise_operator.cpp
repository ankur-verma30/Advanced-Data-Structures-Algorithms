#include <iostream>

using namespace std;

int main()
{
   int a = 0; // if this is a integer othewise if it was a bit we simply would have got 1

   cout << "the value of the a is= " << ~a << endl;
   // the value is -1 as at the binary level the 0 is stored as 0000000000 where MSB is the signed bit so after applying the complement it inverts to the negative value and the rest of the value is stored in the form of the 2's complement so it gets inverted again and added 1 to it we get -1
   // for checking the number is odd or even

   int x;
   cout << "Input the number to check whether it is even or odd" << endl;
   cin >> x;
   if (x & 1)
      cout << "This is the odd number" << endl;
   else
      cout << "This is the even number" << endl;
   return 0;
}