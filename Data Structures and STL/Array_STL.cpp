#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

void UpdateArray(array<int, 6> &xxarr, int index, int value) // if passed by reference then it will update the value in the array
{
    xxarr[index] = value; // if passed by reference then it can be given two names as xxarr as both will be pointing on the same array it is the alias of the array
}
// All stl containers are passed by value

// for making the read only function for printing the array
void PrintArray(const array<int, 6> &arr) // only printing will take place can't modify the array
// NOTE: for the good pratice of coding for the readonly function use const
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
int main()
{
    array<int, 6> arr = {1, 2, 3, 4, 7, 6};

    UpdateArray(arr, 3, 12); // the array is not updated as they are copies of the object they are passed by value
    arr[0] = 10;
    PrintArray(arr);

    // using of the iterators  we have to include the
    sort(arr.begin(), arr.end()); // in this end iterator contains the address after the last element of the array
    cout << endl
         << "The sorted array is : ";
    PrintArray(arr);

    // for initializing the whole array with the same number
    // we use fill method
    array<int, 10> NewArray;
    NewArray.fill(0); // this will fill the whole array with 0
    cout << endl;
    // instead of using the normal for loop we can use for each loop
    //  for(int i=0; i<NewArray.size(); i++){
    //      cout<<NewArray[i]<<" ";}

    // for each loop
    for (int x : NewArray)
    {
        cout << x << " "; // gives the same result
    }
}