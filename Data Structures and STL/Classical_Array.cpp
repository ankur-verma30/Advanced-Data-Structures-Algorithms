#include <iostream>
#include <algorithm>
using namespace std;
// This is the classical array
//  Array is passed by reference
void updateArray(int arr[], int index, int value)
{
    arr[index] = value;
}
void ArraySize(int *arr)
{
    cout << "The size of the array inside the function is = " << sizeof(arr) << endl;
}
void DisplayArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
int main()
{
    int arr[] = {1, 4, 2, 6, 4, 6};
    int n = sizeof(arr) / sizeof(arr[0]); // or the size of the int
    // actual array is updated
    updateArray(arr, 4, 23);
    DisplayArray(arr, n);
    cout << endl;
    ArraySize(arr); // this is giving 8 because it stores the base address of the actual object as pointers and as we know pointers takes  8 bytes in the memory that's why we have to pass explicitly the value of n
    cout << "Priniting the size of the array in the main function = " << sizeof(arr) << endl;

    // Using some common function of STL
    sort(arr, arr + n); // we have to give the ending of the array like ending array index is arr+n-1 so we have to give the address after of this i.e is arr+n for the sort algorithm  to work
    DisplayArray(arr, n);

    return 0;
}