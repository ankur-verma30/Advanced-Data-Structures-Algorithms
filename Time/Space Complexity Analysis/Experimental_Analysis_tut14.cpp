#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
using namespace std;

void BubbleSort(vector<int> &a, int n)
{
    int temp = 0;
    for (int times = 1; times <= n - 1; times++)
    {
        // repeated swapping
        for (int j = 0; j <= n - times - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}
int main()
{
    int n;
    cout << "Enter the value of n = ";
    cin >> n;
    vector<int> arr(n, 0);

    // Init a reverse sorted array this is the merge sort
    // for (int i = 0; i < n; i++)
    // {
    //     arr[i] = n - i;
    // }
    auto start_time = clock();
    // sort(arr.begin(), arr.end());
    BubbleSort(arr, n); // checking for the bubble sort this is giving time value for the first 10000 elements
    auto end_time = clock();
    cout << "time taken = " << end_time - start_time << endl; // until 10000 it was showing 0 then for the 100000 it has shown some time
    return 0;
}