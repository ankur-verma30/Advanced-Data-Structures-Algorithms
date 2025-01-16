#include <bits/stdc++.h>

using namespace std;

class SegmentTrees
{
    vector<int> segments;

public:
    SegmentTrees(int n)
    {
        segments.resize(4 * n);
    }
    void build(int index, int low, int high, int arr[])
    {
        if (low == high)
        {
            segments[index] = arr[low];
            return;
        }
        int mid = low + (high - low) / 2;
        build(2 * index + 1, low, mid, arr);
        build(2 * index + 2, mid + 1, high, arr);
        segments[index] = min(segments[2 * index + 1], segments[2 * index + 2]);
    }

    int query(int index, int low, int high, int l, int r)
    {

        // no overlap between low and high and l and r
        if (high < l || low > r)
            return INT_MAX;

        // complete overlap between low and high and l and r
        if (high <= r && low >= l)
            return segments[index];

        // partial overlap between low and mid and mid+1 and high and l and r
        int mid = low + (high - low) / 2;
        int lvalue = query(2 * index + 1, low, mid, l, r);
        int rvalue = query(2 * index + 2, mid + 1, high, l, r);

        return min(lvalue, rvalue);
    }

    void update(int index, int low, int high, int idx, int val)
    {
        if (idx < low || idx > high)
            return;
        if (low == high)
        {
            segments[index] = val;
            return;
        }
        int mid = low + (high - low) / 2;
        if (idx <= mid)
            update(2 * index + 1, low, mid, idx, val);
        else
            update(2 * index + 2, mid + 1, high, idx, val);
        segments[index] = min(segments[2 * index + 1], segments[2 * index + 2]);
    }
};

int main()
{
    int n;
    cout << "Enter the number of elements of array1: "; // Input size of array from user.
    cin >> n;
    int arr1[n];
    cout << "Array elements: "; // Input array elements from user.
    for (int i = 0; i < n; i++)
        cin >> arr1[i];
    SegmentTrees sg1(n);
    sg1.build(0, 0, n - 1, arr1); // Building Segment Tree for array1.

    int m;
    cout << "Enter the number of elements of array2: "; // Input size of array from user.
    cin >> m;
    int arr2[m];
    cout << "Array elements: "; // Input array elements from user.
    for (int i = 0; i < m; i++)
        cin >> arr2[i];
    SegmentTrees sg2(m);
    sg2.build(0, 0, m - 1, arr2); // Building Segment Tree for array2.

    int q;
    cout << "Enter the number of queries: ";
    cin >> q;
    while (q--)
    {
        cout << "Enter the type of the query: " << endl;
        int type;
        cin >> type;
        if (type == 1)
        {
            int l1, r1;
            cout << "Enter the range (l1, r1): ";
            cin >> l1 >> r1;
            int l2, r2;
            cout << endl
                 << "Enter the range (l2, r2): ";
            cin >> l2 >> r2;
            int min1 = sg1.query(0, 0, n - 1, l1, r1);
            cout<<"Minimum value of the first array: "<< min1 << endl;
            int min2 = sg2.query(0, 0, m - 1, l2, r2);
            cout<<"Minimum value of the second array: "<< min2 << endl;
            cout << "Minimum of the range in both arrays: " << min(min1, min2) << endl;
        }
        else if (type == 2)
        {
            int arrayNo, idx, val;
            cout<<"Enter the array no for the updation in the respective array ";
            cin >> arrayNo;
            cout << "Enter the index and value: ";
            cin >> idx >> val;
            if (arrayNo == 1)
            {
                sg1.update(0, 0, n - 1, idx, val);
                arr1[idx] = val;
            }
            else if (arrayNo == 2)
            {
                sg2.update(0, 0, m - 1, idx, val);
                arr2[idx] = val;
            }
        }
    }
    return 0;
}